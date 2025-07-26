#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

namespace CE {

    class Resource {
    public:
        virtual void load() = 0;
        virtual bool isLoaded() const = 0;
    };

}

#endif // RESOURCE_H
