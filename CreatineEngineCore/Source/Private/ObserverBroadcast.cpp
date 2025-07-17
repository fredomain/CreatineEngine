#include "ObserverBroadcast.h"

namespace CE {

	void ObserverBroadcast::addUpdateCallback(ObserverInfo::UpdateCallback cb, void* callbackObject) {
		observerMap[callbackObject] = cb;
	}

	void ObserverBroadcast::removeUpdateCallback(void* callbackObject) {
		if (callbackObject) {
			observerMap.erase(callbackObject);
		}
	}

	void ObserverBroadcast::notifyObservers() {
		for (const auto& [obj, cb] : observerMap) {
			cb(obj);
		}
	}

}
