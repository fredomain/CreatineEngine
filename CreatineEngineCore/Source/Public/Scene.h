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

		Scene();
		virtual ~Scene();

		/**
		 * @brief Loads or initializes resources or data.
		 */
		virtual void initialize();

		virtual void update();

		void registerEntity(std::unique_ptr<Entity>&& entity);
		void unregisterEntity(Entity* entity);

		void registerComponent(Renderable& renderable);
		void unregisterComponent(Renderable& renderable);

	protected:
		void updateEntityList(float deltaTime);
		void render();

		RenderEngine renderEngine;
		TimingManager timingManager;

		std::vector<std::unique_ptr<Entity>> entityList;
	};

}

#endif

