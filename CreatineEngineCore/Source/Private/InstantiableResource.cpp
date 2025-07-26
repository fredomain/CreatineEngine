#include "InstantiableResource.h"

namespace CE {

    void InstantiableResource::addUpdateCallback(ObserverInfo::UpdateCallback cb, void* callbackObject) {
        observerBroadcast.addUpdateCallback(cb, callbackObject);
    }

    void InstantiableResource::removeUpdateCallback(void* callbackObject) {
        if (callbackObject) {
            observerBroadcast.removeUpdateCallback(callbackObject);
        }
    }

}
