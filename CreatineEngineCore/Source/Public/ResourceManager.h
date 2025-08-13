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
#include "Logger.h"

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

		/**
		 * @brief Get a texture from the resource manager, loading it if necessary.
		 * @tparam T The type of the texture to create.
		 * @tparam ...Args The types of the constructor arguments for the texture.
		 * @param label The label of the texture.
		 * @param ...args The constructor arguments for the texture.
		 * @return A shared pointer to the texture.
		 */
		template <typename T, typename... Args>
			requires std::is_constructible_v<T, Args...>
        static std::shared_ptr<Texture> getTexture(const std::string& label, Args&&... args) {
            ResourceManager& rm = get();

            std::shared_ptr<Texture> shared = rm.findTexture(label);
            if (shared) {      // Texture found
                Logger::log(LogFileType::Engine,
                    std::format("Texture {} already loaded", label),
                    LogLevel::Verbose,
                    "Resource Manager");
            }
            else {             // Texture not found, return a new one
				shared = std::make_shared<T>(std::forward<Args>(args)...);  // Perfect forwarding
                rm.textureMap[label] = shared;

                Logger::log(
                    LogFileType::Engine,
                    std::format("Texture {} has been loaded", label),
                    LogLevel::Verbose,
                    "Resource Manager");
            }
            return shared;
        }

        /**
         * @brief Get a surface from the resource manager, loading it if necessary.
         * @tparam T The type of the surface to create.
         * @tparam ...Args The types of the constructor arguments for the surface.
         * @param label The label of the surface.
         * @param ...args The constructor arguments for the surface.
         * @return A shared pointer to the surface.
         */
        template <typename T, typename... Args>
			requires std::is_constructible_v<T, Args...>
        static std::shared_ptr<Surface> getSurface(const std::string& label, Args&&... args) {
            ResourceManager& rm = get();

            std::shared_ptr<Surface> shared = rm.findSurface(label);
            if (shared) {      // Surface found
                Logger::log(LogFileType::Engine,
                    std::format("Surface {} already loaded", label),
                    LogLevel::Verbose,
                    "Resource Manager");
            }
            else {             // Surface not found, return a new one
                shared = std::make_shared<T>(std::forward<Args>(args)...);  // Perfect forwarding
                rm.surfaceMap[label] = shared;
                
                Logger::log(
                    LogFileType::Engine,
                    std::format("Surface {} has been loaded", label),
                    LogLevel::Verbose,
                    "Resource Manager");
            }
            return shared;
        }
        

        //std::shared_ptr<Sound> getSound(const std::string& label);

    private:
        ResourceManager() = default;        

        std::unordered_map<std::string, std::weak_ptr<Texture>> textureMap;
        std::unordered_map<std::string, std::weak_ptr<Surface>> surfaceMap;
        //std::unordered_map<std::string, std::weak_ptr<Sound>> soundMap;

        std::shared_ptr<Texture> findTexture(std::string label);
        std::shared_ptr<Surface> findSurface(std::string label);
        //std::shared_ptr<Sound> findSound(std::string label);
    };

}

#endif
