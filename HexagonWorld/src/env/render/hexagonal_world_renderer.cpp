#include <iostream>
#include <cassert>
#include <SDL2/SDL.h>

#include "env/render/hexagonal_world_renderer.h"

namespace NEnv::NRender {

    namespace {
        SDL_Texture* load_image(std::string file, SDL_Renderer* renderer){
            SDL_Surface *loadedImage = nullptr;
            SDL_Texture *texture = nullptr;
            loadedImage = SDL_LoadBMP(file.c_str());
            if (loadedImage != nullptr){
                texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
                SDL_FreeSurface(loadedImage);
            } else {
                std::cout << SDL_GetError() << std::endl;
                assert(false);
            }
            return texture;
        }

        void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int height, int width) {
            SDL_Rect rect {x, y, width, height};
            SDL_QueryTexture(texture, NULL, NULL, NULL, NULL);
            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    } // namespace

    HexagonalWorldRenderer::HexagonalWorldRenderer(const HexagonalWorld& world) : world(world) {

    }

    HexagonalWorldRenderer::~HexagonalWorldRenderer() {
        if (initialized) {
            for (auto& texture : textures) {
                SDL_DestroyTexture(texture.second);
            }
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }

    void HexagonalWorldRenderer::lazy_init() const {
        initialized = true;
        if (int error = SDL_Init(SDL_INIT_EVERYTHING); error != 0) {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            assert(false); // TODO some exception maybe?
        }
        window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
        if (window == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            assert(false);
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr){
            std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            assert(false);
        }
        textures["cat"] = load_image("../res/cat.bmp", renderer);
    }

    void HexagonalWorldRenderer::render() const {
        if (!initialized) {
            lazy_init();
        }
        SDL_RenderClear(renderer);

        render_texture(renderer, textures["cat"], 100, 100, 100, 100);

        SDL_RenderPresent(renderer);
        SDL_Delay(10); // TODO hm
    }
} // namespace NEnv::NRender
