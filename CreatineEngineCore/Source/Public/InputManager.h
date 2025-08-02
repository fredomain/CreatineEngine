#pragma once
#ifndef VECTOR_H
#define VECTOR_H

namespace CE {

	class InputManager
	{
	public:
		/**
		 * @brief Check if new input events are available.
		 *        Executes the related actions to those events
		 */
		void update();

	private:
		InputManager() = default;



	};

}

#endif

