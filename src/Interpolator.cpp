#include "Interpolator.h"

namespace pew {
    Interpolator::Interpolator() {}

    Interpolator::Interpolator(std::function<bool(double, uint64_t)> fun, uint64_t duration) {
        this->duration = duration;
        this->onStep = fun;
    }
}
