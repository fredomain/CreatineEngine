#include "ObserverInfo.h"

namespace CE {

	ObserverInfo::ObserverInfo(UpdateCallback cb, void* obj)
		: cb(cb), callbackObject(obj) {
	}

	void ObserverInfo::notify() const {
		if (cb) cb(callbackObject);
	}

}
