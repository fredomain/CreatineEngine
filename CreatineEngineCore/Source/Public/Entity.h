#pragma once
#ifndef ENTITY_H
#define ENTITY_H

namespace CE {

	/**
	 * @brief This class is the interface of game objects and scenes.
	 * Components must be registered manually in the scene using the function registerComponents.
	 * Component registration will be kept manual to improve modularity in CreatineEngine.
	 */
	class Entity
	{
	public:
		virtual void update(float deltaTime) = 0;

		/**
		 * @brief Initializes the object.
		 This is a pure virtual function that must be implemented by derived classes.
		 IMPORTANT: call ResourceManager::get functions in the Entity constructor, not in initialize.
		 */
		virtual void initialize() = 0;

		void enableUpdate();
		void disableUpdate();


	private:
		bool executeUpdate = true;
	};

}

#endif