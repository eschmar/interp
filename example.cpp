#include <iostream>
#include "interp.h"

int main() {
    std::cout << "Hello from interp! " << interp_VERSION_SEMANTIC << "\n";

    pew::Interp p = pew::interp(1000);

    return 0;
}
