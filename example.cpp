#include <iostream>
#include "Interpolator.h"
#include "matplotlibcpp.h"
#include <iomanip>
#include <vector>
#include <utility>
#include <math.h>

namespace plt = matplotlibcpp;

#define RUNTIME_LENGTH_MS 2000

int main() {
    std::cout << "Hello from interp! " << interp_VERSION_SEMANTIC << "\n";

    std::vector<double> x; // use double isntead of uint64_t so named_plot does not complain.
    std::vector<double> y;

    std::vector<std::pair<std::string, std::function<double(double)>>> easings = {
        std::make_pair(std::string("Linear"), interp::InterpolatorMethod::linear),
        std::make_pair(std::string("Sqrt"), interp::InterpolatorMethod::sqrt),
        std::make_pair(std::string("Square"), interp::InterpolatorMethod::square),
        std::make_pair(std::string("Cube"), interp::InterpolatorMethod::cube),
        std::make_pair(std::string("CubicRoot"), interp::InterpolatorMethod::cubicRoot)
    };

    for (std::pair<std::string, std::function<double(double)>> easing : easings) {
        x.clear();
        y.clear();

        interp::Interpolator interp([&](double value, uint64_t elapsed) mutable {
            std::cout << "[" << elapsed << "\t" << value << "]\n";
            x.push_back(elapsed);
            y.push_back(value);
            return true;
        }, RUNTIME_LENGTH_MS);

        interp.setEasing(easing.second);
        interp.run();

        usleep(RUNTIME_LENGTH_MS * 1000);

        plt::named_plot(easing.first, x, y);
    }

    plt::legend();
    plt::title("x: elapsed time in ms, y: current value");
    plt::save("plot.png");

    return 0;
}
