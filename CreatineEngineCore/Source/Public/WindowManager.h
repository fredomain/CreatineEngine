#pragma once
#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SDL3/SDL.h>
#include <string>

namespace CE {

    class WindowManager {
    public:
        WindowManager();
        ~WindowManager();

        bool initialize(const std::string& title, int width, int height, bool fullscreen = false);
        void shutdown();

        void setResolution(int width, int height);
        void toggleFullscreen();
        int getWidth() const;
        int getHeight() const;
        bool isFullscreen() const;

        void setWindowIcon(const std::string& iconPath); // Cambiar icono manualmente
        SDL_Window* getWindow() const;
        SDL_Renderer* getRenderer() const;

    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        bool fullscreen = false;

        void loadDefaultIcon(); // Carga Content/Icon/icon32p.bmp por defecto
    };

}

#endif // WINDOWMANAGER_H
