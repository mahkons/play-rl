#pragma once

#include <vector>

#include "env/cell.h"

using std::vector;

namespace NEnv {
    class HexagonalMap {
    public:
        HexagonalMap(int height, int width) : height(height), width(width),
            map(height, vector<Cell>(width)) {}

    private:
        const int height;
        const int width;
        const vector<vector<Cell>> map;
    };
} // namespace NEnv
