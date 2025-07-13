#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "AssetLoaderManager.h"
#include "ResourceManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"

#include <memory>
#include <vector>

namespace CE {

	class Scene
	{
	public:

		Scene(SDL_Renderer* renderer);
		virtual ~Scene();

		/**
		 * @brief Loads or initializes resources or data.
		 */
		virtual void initialize();
		virtual void shutdown();

		virtual void update();

		void registerEntity(std::unique_ptr<Entity>&& entity);
		void unregisterEntity(Entity* entity);

		void registerComponent(AssetLoader& assetLoader);
		void registerComponent(Resource& resource);
		void registerComponent(Renderable& renderable);
		void unregisterComponent(AssetLoader& assetLoader);
		void unregisterComponent(Resource& resource);
		void unregisterComponent(Renderable& renderable);

	protected:
		void updateEntityList(float deltaTime);
		void render();

		AssetLoaderManager assetLoaderManager;
		ResourceManager resourceManager;
		RenderEngine renderEngine;
		TimingManager timingManager;

		std::vector<std::unique_ptr<Entity>> entityList;
	};

}

#endif

