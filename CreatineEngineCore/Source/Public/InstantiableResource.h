#pragma once
#ifndef INSTANTIABLERESOURCE_H
#define INSTANTIABLERESOURCE_H

#include "Resource.h"
#include "ObserverBroadcast.h"

namespace CE {

    class InstantiableResource : public Resource
    {
    public:
        virtual void load() = 0;            // Still an abstract class
        virtual bool isLoaded() const = 0;

        // Functions called by observers
        void addUpdateCallback(ObserverInfo::UpdateCallback cb, void* callbackObject);
        void removeUpdateCallback(void* callbackObject);

    protected:
        ObserverBroadcast observerBroadcast;
    };

}

#endif

