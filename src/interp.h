#ifndef PEW_INTERP_H
#define PEW_INTERP_H

#include <functional>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <limits>
#include <algorithm>
#include <thread>

#define interp_VERSION_SEMANTIC "1.0.0"

// TODO: how to use namespace and have nice looking factory
namespace pew {

class Interp {
    uint16_t frequencyHz = 60;
    uint64_t start = 0, duration = 400;
    bool isInterrupted = false;
    std::thread thr;

    std::function<bool(double, uint64_t)> onStep;
    std::function<void()> onEnd;
    std::function<double(double)> easing;

    inline uint64_t now() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }

    Interp();

    void tick() {
        uint64_t elapsed = this->now() - start;
        double ratio = std::clamp((double) elapsed / duration, 0.0, 1.0);

        // apply easing function if available, otherwise linear
        if (easing) ratio = easing(ratio);

        // allow user defined behaviour on step
        if (onStep && !onStep(ratio, elapsed)) isInterrupted = true;

        // check if end is reached
        if (elapsed > duration || isInterrupted) {
            if (onEnd) onEnd();
            return;
        }

        usleep(1000000.0 / frequencyHz);
        tick();
    }

  public:
    Interp(std::function<bool(double, uint64_t)> fun, uint64_t duration);
    void setOnEnd(std::function<void()> fun) { onEnd = fun; };
    void setEasing(std::function<double(double)> fun) { easing = fun; };
    void setFrequency(uint16_t frequency) { frequencyHz = std::clamp((int) frequency, 1, 240); };
    void stop() { isInterrupted = true; };

    void run() {
        start = now();
        isInterrupted = false;
        thr = std::thread(&Interp::tick, this);
    }

    ~Interp() {
        if (!thr.joinable()) return;
        stop();
        thr.join();
    }
};

} // namespace

#endif
