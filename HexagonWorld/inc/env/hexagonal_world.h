#pragma once

#include "hexagonal_map.h"

namespace NEnv {
    class HexagonalWorld {
    public:
        HexagonalWorld(int height, int width): map(height, width) {}

        const HexagonalMap& get_map() { return map; }
    private:
        HexagonalMap map;
    };
} // NEnv
