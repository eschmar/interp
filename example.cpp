#include <iostream>
#include "interp.h"
#include "matplotlibcpp.h"
#include <iomanip>
#include <vector>
#include <math.h>

namespace plt = matplotlibcpp;

int main() {
    std::cout << "Hello from interp! " << interp_VERSION_SEMANTIC << "\n";

    std::vector<double> x;
    std::vector<uint64_t> y;

    pew::Interp p = pew::Interp([&](double value, uint64_t elapsed) mutable {
        std::cout << "[" << elapsed << "\t" << value << "]\n";
        x.push_back(value);
        y.push_back(elapsed);
    }, 5000);

    p.setEasing([](double in){
        return sqrt(in);
    });

    p.run();

    plt::plot(y, x);
    plt::save("plot.png");

    std::cout << "Wait for a bit...\n";
    usleep(2000000);
    std::cout << "Done.\n";

    return 0;
}
