#include <iostream>
#include "interp.h"
// #include <matplot/matplot.h>
#include <iomanip>

int main() {
    std::cout << "Hello from interp! " << interp_VERSION_SEMANTIC << "\n";

    pew::Interp p = pew::interp(1000);

    p.setDuration(5000);
    p.setOnStep([](double value, uint64_t elapsed){
        std::cout.precision(17);
        std::cout << "[" << elapsed << "\t" << value << "]. Tick.\n";
    });

    p.run();

    return 0;
}
