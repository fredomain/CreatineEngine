#pragma once
#ifndef OBSERVERBROADCAST_H
#define OBSERVERBROADCAST_H

#include "ObserverInfo.h"
#include <unordered_map>

namespace CE {

	class ObserverBroadcast
	{
	public:
		// Functions called by observers
		void addUpdateCallback(ObserverInfo::UpdateCallback cb, void* callbackObject);
		void removeUpdateCallback(void* callbackObject);

		void notifyObservers();

	private:
		std::unordered_map<void*, ObserverInfo::UpdateCallback> observerMap;

	};

}

#endif

