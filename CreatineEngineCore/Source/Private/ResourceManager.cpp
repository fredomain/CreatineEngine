#include "ResourceManager.h"

namespace CE {

    ResourceManager::~ResourceManager() {
        clear();
    }

    void ResourceManager::registerResource(Resource* resource) {
        if (resource && std::find(resourceList.begin(), resourceList.end(), resource) == resourceList.end()) {
            resourceList.push_back(resource);
        }
    }

    void ResourceManager::unregisterResource(Resource* resource) {
        resourceList.erase(
            std::remove(resourceList.begin(), resourceList.end(), resource),
            resourceList.end()
        );
    }

    void ResourceManager::clear() {
        for (auto* resource : resourceList) {
            if (resource) {
                delete resource; // Libera cada recurso
            }
        }
        resourceList.clear();
    }

}
