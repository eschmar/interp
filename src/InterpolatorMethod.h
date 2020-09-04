#include <functional>
#include <cmath>

namespace pew {
    struct InterpolatorMethod {
        static constexpr auto linear = [](double in) { return in; };
        static constexpr auto sqrt = [](double in) { return std::sqrt(in); };
    };
}
