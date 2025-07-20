#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "ResourceManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"

#include <memory>
#include <vector>

namespace CE {

	/**
	 * @brief Represents a scene in a graphical application, managing entities, components, and resources.
	 */
	class Scene
	{
	public:
		/**
		 * @brief Constructs a new Scene object.
		 Call ResourceManager::get functions here to register resources before
		 SceneManager calls ResourceManager::load()
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
		void registerEntity(std::unique_ptr<Entity> entity);
		void unregisterEntity(Entity* entity);

		void registerComponent(Renderable& renderable);
		void unregisterComponent(Renderable& renderable);

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

