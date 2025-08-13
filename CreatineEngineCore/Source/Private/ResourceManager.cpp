#include "ResourceManager.h"
#include "ImageSurface.h"
#include "TextSurface.h"
#include "ImageTexture.h"
#include "TextTexture.h"

namespace CE {

    ResourceManager& ResourceManager::get() {
        static ResourceManager instance;
        return instance;
    }

    void ResourceManager::load() {
        ResourceManager& rm = get();
        rm.loadSurfaces();
        rm.loadTextures();
    }

    void ResourceManager::loadSurfaces() const {
        for (auto& pair : surfaceMap) {
            if (auto ptr = pair.second.lock()) {
                if (!ptr->isLoaded()) {
                    ptr->load();
                }                    
            }
        }
    }

    void ResourceManager::loadTextures() const {
        Logger::log(LogFileType::Engine,
            std::format("Loading texture resources list. Size: {}", textureMap.size()),
            LogLevel::Verbose,
            "Resource Manager");
        for (auto& pair : textureMap) {
            if (auto ptr = pair.second.lock()) {
                if (!ptr->isLoaded()) {
                    Logger::log(LogFileType::Engine,
                        "Loading Texture...",
                        LogLevel::Verbose,
                        "Resource Manager");
                    ptr->load();
                }
            }
        }
        Logger::log(LogFileType::Engine,
            "Texture resources list loaded",
            LogLevel::Verbose,
            "Resource Manager");
    }

    void ResourceManager::reload() {
        ResourceManager& rm = get();
        rm.reloadSurfaces();
        rm.reloadTextures();
    }

    void ResourceManager::reloadSurfaces() const {
        for (auto& pair : surfaceMap) {
            if (auto ptr = pair.second.lock()) {
                ptr->load();
            }
        }
    }

    void ResourceManager::reloadTextures() const {
        for (auto& pair : textureMap) {
            if (auto ptr = pair.second.lock()) {
                ptr->load();
            }
        }
    }

    std::shared_ptr<Texture> ResourceManager::findTexture(std::string label) {
        auto it = textureMap.find(label);
        if (it != textureMap.end()) {
            if (auto shared = it->second.lock()) {
                return shared;      // It is already loaded
            }
        }

        return nullptr;
    }

    std::shared_ptr<Surface> ResourceManager::findSurface(std::string label) {
        auto it = surfaceMap.find(label);
        if (it != surfaceMap.end()) {
            if (auto shared = it->second.lock()) {
                return shared;
            }
        }

        return nullptr;
    }

    void ResourceManager::clearUnused() {
        ResourceManager& rm = get();
        auto cleanup = [](auto& map) {
            for (auto it = map.begin(); it != map.end(); ) {
                if (it->second.expired()) {
                    it = map.erase(it);
                }
                else {
                    ++it;
                }
            }
            };
        cleanup(rm.textureMap);
        cleanup(rm.surfaceMap);
        //cleanup(soundMap);
    }

}
