#include "Scene.h"
#include "Entity.h"

namespace CE {

	Scene::Scene(SDL_Renderer* renderer)
		: renderEngine(renderer) {
	}

	Scene::~Scene() {
		shutdown();
	}

	void Scene::initialize() {
		resourceManager.loadAllAssets();		
	}

	void Scene::shutdown() {
		resourceManager.clear();
		renderEngine.clear();
		timingManager.reset();

		entityList.clear();
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

	ResourceManager& Scene::getResourceManager(){
		return resourceManager;
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
	void Scene::registerComponent(AssetLoader& assetLoader) {
		resourceManager.registerAssetLoader(&assetLoader);
	}

	void Scene::registerComponent(Resource& resource) {
		resourceManager.registerResource(&resource);
	}

	void Scene::registerComponent(Renderable& renderable) {
		renderEngine.registerRenderable(&renderable);
	}

	void Scene::unregisterComponent(AssetLoader& assetLoader) {
		resourceManager.unregisterAssetLoader(&assetLoader);
	}

	void Scene::unregisterComponent(Resource& resource) {
		resourceManager.unregisterResource(&resource);
	}

	void Scene::unregisterComponent(Renderable& renderable) {
		renderEngine.unregisterRenderable(&renderable);
	}
}
