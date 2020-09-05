#include <functional>
#include <cmath>

namespace pew {
    struct InterpolatorMethod {
        static constexpr auto linear = [](double in) { return in; };
        static constexpr auto sqrt = [](double in) { return std::sqrt(in); };
        static constexpr auto cubicRoot = [](double in) { return std::pow(in, 1.0 / 3.0); };
        static constexpr auto square = [](double in) { return in * in; };
        static constexpr auto cube = [](double in) { return in * in * in; };
    };
}
