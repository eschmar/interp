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

    std::vector<double> x;
    std::vector<double> y; // use double isntead of uint64_t so named_plot does not complain.

    std::vector<std::pair<std::string, std::function<double(double)>>> easings;

    easings.push_back(std::make_pair(std::string("Linear"), pew::InterpolatorMethod::linear));
    easings.push_back(std::make_pair(std::string("Sqrt"), pew::InterpolatorMethod::sqrt));

    for (std::pair<std::string, std::function<double(double)>> easing : easings) {
        x.clear();
        y.clear();

        pew::Interpolator interp([&](double value, uint64_t elapsed) mutable {
            std::cout << "[" << elapsed << "\t" << value << "]\n";
            x.push_back(value);
            y.push_back(elapsed);
            return true;
        }, RUNTIME_LENGTH_MS);

        interp.setEasing(easing.second);
        interp.run();

        usleep(RUNTIME_LENGTH_MS * 1000);

        // plt::plot(y, x);
        plt::named_plot(easing.first, y, x);
    }

    plt::legend();
    plt::save("plot.png");

    return 0;
}
