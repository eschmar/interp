#include <iostream>
#include "interp.h"
#include "matplotlib-cpp/matplotlibcpp.h"
#include <iomanip>
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    std::cout << "Hello from interp! " << interp_VERSION_SEMANTIC << "\n";

    pew::Interp p = pew::interp(1000);

    std::vector<double> x;
    std::vector<uint64_t> y;

    p.setOnStep([&](double value, uint64_t elapsed) mutable {
        x.push_back(value);
        y.push_back(elapsed);
    });

    p.run();

    plt::plot(x, y);
    plt::show();

    return 0;
}
