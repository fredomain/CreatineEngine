#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <SDL_ttf.h>
#include "Texture.h"
#include "Surface.h"
//#include "Sound.h"

namespace CE {

    /**
     * @brief Manages loading and caching of resources such as textures and surfaces, providing shared ownership and automatic cleanup of unused resources.
     */
    class ResourceManager {
    public:
        ~ResourceManager() = default;

        // Prohibir copiar y mover
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;
        ResourceManager(ResourceManager&&) = delete;
        ResourceManager& operator=(ResourceManager&&) = delete;

        static ResourceManager& get();

        /**
         * @brief Load not loaded resource
         */
        static void load();
        void loadSurfaces() const;
        void loadTextures() const;
        //void loadAllSounds() const;

        /**
         * @brief Force the reload of every resource (even ones already loaded)
         */
        static void reload();
        void reloadSurfaces() const;
        void reloadTextures() const;
        //void loadAllSounds() const;

        static void clearUnused(); // clean not referenced resources

        // This functions can be replaced with a template in the future
        static std::shared_ptr<Texture> getTexture(
            const std::string& label,
            SDL_Renderer* renderer,
            SDL_Surface* surface
        );
        static std::shared_ptr<Texture> getTexture(
            const std::string& label,
            SDL_Renderer* renderer,
            SDL_Texture* texture
        );
        static std::shared_ptr<Texture> getImageTexture(
            const std::string& label,
            SDL_Renderer* renderer,
            std::string path
        );
        static std::shared_ptr<Texture> getTextTexture(
            const std::string& label,
            SDL_Renderer* renderer,
            std::string text,
            TTF_Font* font,
            size_t textSize,
            SDL_Color textColor
        );

        // This functions can be replaced with a template in the future
        static std::shared_ptr<Surface> getSurface(
            const std::string& label,
            SDL_Surface* surface
        );
        static std::shared_ptr<Surface> getImageSurface(
            const std::string& label,
            std::string path
        );
        static std::shared_ptr<Surface> getTextSurface(
            const std::string& label,
            std::string text,
            TTF_Font* font,
            size_t textSize,
            SDL_Color textColor
        );

        //std::shared_ptr<Sound> getSound(const std::string& label);

    private:
        ResourceManager() = default;        

        std::unordered_map<std::string, std::weak_ptr<Texture>> textureMap;
        std::unordered_map<std::string, std::weak_ptr<Surface>> surfaceMap;
        //std::unordered_map<std::string, std::weak_ptr<Sound>> soundMap;

        // This functions can be replaced with a template in the future
        std::shared_ptr<Texture> findTexture(std::string label);
        std::shared_ptr<Surface> findSurface(std::string label);
        //std::shared_ptr<Sound> findSound(std::string label);
    };

}

#endif
