#include "Scene.h"
#include "Entity.h"
#include "SceneManager.h"

namespace CE {

	Scene::Scene()
		: renderEngine(SceneManager::getWindowRenderer()) {
	}

	Scene::~Scene() {
		renderEngine.clear();
		timingManager.reset();
		entityList.clear();
	}

	void Scene::initialize() {

	}

	void Scene::render() {		
		renderEngine.render();
	}

	void Scene::updateEntityList(float deltaTime) {
		for (auto& entity : entityList) {
			entity->update(deltaTime);
		}
	}

	void Scene::update() {
		timingManager.update();				// Update timing manager to update deltaTime		
		updateEntityList(timingManager.getGameDeltaTime());
		render();
		timingManager.frameRateControl();	// Control frame rate if needed
	}

	void Scene::registerEntity(std::unique_ptr<Entity>&& entity) {
		entityList.emplace_back(std::move(entity));
	}

	void Scene::unregisterEntity(Entity* entity) {
		//entityList.erase(std::remove(entityList.begin(), entityList.end(), entity), entityList.end());
		entityList.erase(
			std::remove_if(entityList.begin(), entityList.end(),
				[entity](const std::unique_ptr<Entity>& e) { return e.get() == entity; }),
			entityList.end());
	}

	// --- Component registration ---
	void Scene::registerComponent(Renderable& renderable) {
		renderEngine.registerRenderable(&renderable);
	}

	void Scene::unregisterComponent(Renderable& renderable) {
		renderEngine.unregisterRenderable(&renderable);
	}
}
