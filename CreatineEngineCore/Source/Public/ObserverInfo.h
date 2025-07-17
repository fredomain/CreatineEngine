#pragma once
#ifndef OBSERVERINFO_H
#define OBSERVERINFO_H

namespace CE {

	class ObserverInfo {
	public:
		using UpdateCallback = void(*)(void* callbackObject);	// Callback function pointer type

		ObserverInfo(UpdateCallback cb, void* obj);

		void notify() const;

		UpdateCallback cb;
		void* callbackObject;
	};

}

#endif
