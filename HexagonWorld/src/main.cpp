#include "hello_world.h"
#include "env/hexagonal_world.h"
#include "env/render/hexagonal_world_renderer.h"

int main() {
    NEnv::HexagonalWorld world(5, 5);
    NEnv::NRender::HexagonalWorldRenderer renderer(world);

    for (int i = 0; i < 100; i++) {
        renderer.render();
    }
    return 0;
}
