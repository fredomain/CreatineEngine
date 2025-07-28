#pragma once
#ifndef RECTENTITY_H
#define RECTENTITY_H

#include "Entity.h"
#include "Rect.h"

namespace CE {

	/**
	 * @brief Represents a rectangular entity.
	 */
	class RectEntity : public Entity
	{
		virtual void setX() = 0;
		virtual void setY() = 0;
		virtual void setWidth() = 0;
		virtual void setHeight() = 0;
	};

}

#endif

