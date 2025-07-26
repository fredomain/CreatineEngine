#include "WindowManager.h"
#include <SDL3/SDL.h>
#include <SDL_image.h>

namespace CE {

    WindowManager::WindowManager() = default;

    WindowManager::~WindowManager() {
        shutdown();
    }

    bool WindowManager::initialize(const std::string& title, int width, int height, bool fullscreen) {
        Uint32 windowFlags = 0;
        if (fullscreen) windowFlags |= SDL_WINDOW_FULLSCREEN;

        if (!SDL_CreateWindowAndRenderer(title.c_str(), width, height, windowFlags, &window, &renderer))
        {
            SDL_Log("Window and Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
        }

        this->fullscreen = fullscreen;

        loadDefaultIcon();
        return true;
    }

    void WindowManager::shutdown() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }
        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }
    }

    void WindowManager::setResolution(int width, int height) {
        if (window) {
            SDL_SetWindowSize(window, width, height);
        }
    }

    void WindowManager::toggleFullscreen() {
        if (window) {
            fullscreen = !fullscreen;
            SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
        }
    }

    int WindowManager::getWidth() const {
        int w = 0;
        if (window) SDL_GetWindowSize(window, &w, nullptr);
        return w;
    }

    int WindowManager::getHeight() const {
        int h = 0;
        if (window) SDL_GetWindowSize(window, nullptr, &h);
        return h;
    }

    bool WindowManager::isFullscreen() const {
        return fullscreen;
    }

    SDL_Window* WindowManager::getWindow() const {
        return window;
    }

    SDL_Renderer* WindowManager::getRenderer() const {
        return renderer;
    }

    void WindowManager::setWindowIcon(const std::string& iconPath) {
        if (window) {
            SDL_Surface* icon = IMG_Load(iconPath.c_str());
            if (icon) {
                SDL_SetWindowIcon(window, icon);
                SDL_DestroySurface(icon);
            }
            else {
                SDL_Log("Failed to load icon: %s", SDL_GetError());
            }
        }
    }

    void WindowManager::loadDefaultIcon() {
        setWindowIcon("Content/Icon/icon32p.ico");
    }

}
