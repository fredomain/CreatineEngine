#include "ResourceManager.h"
#include "ImageSurface.h"
#include "TextSurface.h"
#include "ImageTexture.h"
#include "TextTexture.h"
#include "Logger.h"

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
        for (auto& pair : textureMap) {
            if (auto ptr = pair.second.lock()) {
                if (!ptr->isLoaded()) {
                    ptr->load();
                }
            }
        }
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

    std::shared_ptr<Texture> ResourceManager::getTexture(
        const std::string& label,SDL_Renderer* renderer,
        SDL_Surface* surface
    ){
        ResourceManager& rm = get();

        std::shared_ptr<Texture> shared = rm.findTexture(label);
        if (shared) {      // Texture found
            return shared;
        }
        else {             // Texture not found, return a new one
            shared = std::make_shared<Texture>(renderer, surface);
            rm.textureMap[label] = shared;
            return shared;
        }
    }

    std::shared_ptr<Texture> ResourceManager::getTexture(
        const std::string& label,
        SDL_Renderer* renderer,
        SDL_Texture* texture
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Texture> shared = rm.findTexture(label);
        if (shared) {      // Texture found
            return shared;
        }
        else {              // Texture not found, return a new one
            shared = std::make_shared<Texture>(renderer, texture);
            rm.textureMap[label] = shared;
            return shared;
        }
    }

    std::shared_ptr<Texture> ResourceManager::getImageTexture(
        const std::string& label,
        SDL_Renderer* renderer,
        std::string path
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Texture> shared = rm.findTexture(label);
        if (shared) {      // Texture found
            Logger::logMessage(LogFileType::Engine,
                std::format("ImageTexture {} already loaded", label),
                LogLevel::Verbose,
                "Resource Manager");
        }
        else {              // Texture not found, return a new one
            shared = std::make_shared<ImageTexture>(renderer, path);
            rm.textureMap[label] = shared;
            Logger::logMessage(
                LogFileType::Engine,
                std::format("ImageTexture {} has been loaded", label),
                LogLevel::Verbose,
                "Resource Manager");
        }
        return shared;
    }
    std::shared_ptr<Texture> ResourceManager::getTextTexture(
        const std::string& label,
        SDL_Renderer* renderer,
        std::string text,
        TTF_Font* font,
        size_t textSize,
        SDL_Color textColor
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Texture> shared = rm.findTexture(label);
        if (shared) {      // Texture found
            return shared;
        }
        else {              // Texture not found, return a new one
            shared = std::make_shared<TextTexture>(renderer, text, font, textSize, textColor);
            rm.textureMap[label] = shared;
            return shared;
        }
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

    std::shared_ptr<Surface> ResourceManager::getSurface(
        const std::string& label,
        SDL_Surface* surface
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Surface> shared = rm.findSurface(label);
        if (shared) {      // Surface found
            return shared;
        }
        else {             // Surface not found, return a new one
            shared = std::make_shared<Surface>(surface);
            rm.surfaceMap[label] = shared;
            return shared;
        }
    }

    std::shared_ptr<Surface> ResourceManager::getImageSurface(
        const std::string& label,
        std::string path
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Surface> shared = rm.findSurface(label);
        if (shared) {      // Surface found
            return shared;
        }
        else {             // Surface not found, return a new one
            shared = std::make_shared<ImageSurface>(path);
            rm.surfaceMap[label] = shared;
            return shared;
        }
    }

    std::shared_ptr<Surface> ResourceManager::getTextSurface(
        const std::string& label,
        std::string text,
        TTF_Font* font,
        size_t textSize,
        SDL_Color textColor
    ) {
        ResourceManager& rm = get();

        std::shared_ptr<Surface> shared = rm.findSurface(label);
        if (shared) {      // Surface found
            return shared;
        }
        else {             // Surface not found, return a new one
            shared = std::make_shared<TextSurface>(text, font, textSize, textColor);
            rm.surfaceMap[label] = shared;
            return shared;
        }
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
