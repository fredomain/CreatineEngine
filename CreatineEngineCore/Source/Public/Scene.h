#pragma once
#ifndef SCENE_H
#define SCENE_H

//#include "Entity.h"
#include "ResourceManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"

#include <memory>
#include <vector>

namespace CE {

	class Entity;

	/**
	 * @brief Represents a scene in a graphical application, managing entities, components, and resources.
	 */
	class Scene
	{
	public:
		/**
		 * @brief Constructs a new Scene object.
		 Call ResourceManager::get functions here to register resources before
		 SceneManager calls ResourceManager::load().
		 Create/register entities here.
		 */
		Scene();
		virtual ~Scene();

		/**
		 * @brief Initializes data. Call after loading resources.
		 */
		virtual void initialize();

		virtual void update();

		/**
		 * @brief Registers an entity for management or processing.
		 * Call this function in the constructor of the scene.
		 * @param entity A unique pointer to the Entity to be registered. Ownership of the entity is transferred to the function.
		 */
		Entity* registerEntity(std::unique_ptr<Entity> entity);	// It could be a template with the new entity type to create it within the function itself, name it CreateEntity in that case?
		void unregisterEntity(Entity* entity);

		void registerComponent(Renderable& renderable);
		void unregisterComponent(Renderable& renderable);

		const TimingManager& getTimingManager();

	protected:
		void updateEntityList(float deltaTime);
		void initializeEntityList();
		void render();

		RenderEngine renderEngine;
		TimingManager timingManager;

		std::vector<std::unique_ptr<Entity>> entityList;
	};

}

#endif

