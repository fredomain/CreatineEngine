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
		 * @brief Creates a new entity of type T.
		 * @tparam T The type of the entity to create, must be derived from Entity.
		 * @tparam ...Args The types of the constructor arguments for the entity.
		 * @param ...args The constructor arguments for the entity.
		 * @return A pointer to the newly created entity.
		 */
		template <typename T, typename... Args>
			requires std::is_constructible_v<T, Args...>
		T* createEntity(Args&&... args) {
			auto entity = std::make_unique<T>(std::forward<Args>(args)...);		// C++20 perfect forwarding when using the entity constructor arguments
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

