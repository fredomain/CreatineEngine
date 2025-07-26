#include "Entity.h"
#include "Scene.h"

namespace CE {
	void Entity::update(float deltaTime) {
		if (!executeUpdate) {
			return;
		}
	}

	void Entity::enableUpdate() {
		executeUpdate = true;
	}
	void Entity::disableUpdate() {
		executeUpdate = false;
	}

}