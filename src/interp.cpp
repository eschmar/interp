#include "interp.h"

namespace pew {
    Interp::Interp() {}

    Interp::Interp(std::function<bool(double, uint64_t)> fun, uint64_t duration) {
        this->duration = duration;
        this->onStep = fun;
    }
}
