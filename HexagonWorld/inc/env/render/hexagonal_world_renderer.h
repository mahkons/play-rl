#include <memory>
#include <string>
#include <map>
#include <SDL2/SDL.h>

#include "env/hexagonal_world.h"
#include "env/hexagonal_map.h"

namespace NEnv::NRender {
    class HexagonalWorldRenderer {
    public:
        HexagonalWorldRenderer(const HexagonalWorld& world);
        ~HexagonalWorldRenderer();
        
        void render() const;

    private:
        void lazy_init() const;

    private:
        const HexagonalWorld& world; // ugly? one should be sure, that world is not deleted yet
        
        // ugly mutables for lazy initialization
        mutable bool initialized = false;
        mutable SDL_Window* window;
        mutable SDL_Renderer* renderer;
        mutable std::map<std::string, SDL_Texture*> textures;
    };
} // namespace NEnv::NRender
