#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include "Resource.h"

namespace CE {

    class ResourceManager {
    public:
        ResourceManager() = default;
        ~ResourceManager();

        void registerResource(Resource* resource);
        void unregisterResource(Resource* resource);

        void clear(); // Elimina todos los recursos registrados

    private:
        std::vector<Resource*> resourceList;
    };

}

#endif // RESOURCEMANAGER_H
