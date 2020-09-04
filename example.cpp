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

    pew::Interp p([&](double value, uint64_t elapsed) mutable {
        std::cout << "[" << elapsed << "\t" << value << "]\n";
        x.push_back(value);
        y.push_back(elapsed);
        return true;
    }, 5000);

    p.setEasing([](double in){
        return sqrt(in);
    });

    p.run();

    usleep(2000000);

    plt::plot(y, x);
    plt::save("plot.png");

    std::cout << "Done.\n";

    return 0;
}
