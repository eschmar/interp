#ifndef PEW_INTERP_H
#define PEW_INTERP_H

#define interp_VERSION_SEMANTIC "1.0.0"

namespace pew {
    class Interp {
        Interp();

        public:
            static Interp create(long duration);
    };

    inline Interp interp(long duration) {
        return Interp::create(duration);
    }
}

#endif
