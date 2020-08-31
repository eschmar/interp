#ifndef PEW_INTERP_H
#define PEW_INTERP_H

#include <functional>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <limits>
#include <algorithm>

#define interp_VERSION_SEMANTIC "1.0.0"

namespace pew {

class Interp {
    int frequencyHz = 60;
    uint64_t start = 0, duration = 400;

    std::function<void(double)> onStep;
    std::function<void()> onStart, onEnd;
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
        if (onStep) onStep(ratio);

        // check if end is reached
        if (ratio >= 1.0) {
            if (onEnd) onEnd();
            return;
        }

        usleep(1000000.0 / frequencyHz);
        tick();
    }

  public:
    static Interp create(long duration);
    void setOnStart(std::function<void()> fun) { onStart = fun; };
    void setOnEnd(std::function<void()> fun) { onEnd = fun; };
    void setOnStep(std::function<void(double)> fun) { onStep = fun; };

    void run() {
        start = now();
        if (onStart) onStart();
        tick();
    }
};

inline Interp interp(long duration) {
    return Interp::create(duration);
}

} // namespace

#endif
