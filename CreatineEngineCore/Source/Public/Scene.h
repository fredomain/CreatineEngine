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
		Scene(std::string name);
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
		template <typename T>
		T* createEntity() {
			auto entity = std::make_unique<T>();
			T* raw_pointer = entity.get();			// Store entity raw pointer before moving it
			entity->registerComponentsInScene(*this);	// Register components before moving the entity
			entityList.emplace_back(std::move(entity));
			return raw_pointer;
		}

		void removeEntity(Entity* entity);

		void registerComponent(Renderable& renderable);
		void unregisterComponent(Renderable& renderable);

		const TimingManager& getTimingManager();

		std::string getName() const;

	protected:
		void updateEntityList(float deltaTime);
		void initializeEntityList();
		void render();

		std::string name;

		RenderEngine renderEngine;
		TimingManager timingManager;

		std::vector<std::unique_ptr<Entity>> entityList;
	};

}

#endif

