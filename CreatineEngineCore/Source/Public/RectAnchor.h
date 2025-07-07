#pragma once
#ifndef RECTANCHOR_H
#define RECTANCHOR_H

#include "FVector.h"

namespace CE {

	enum RectAnchor {
		CENTER,
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		TOP_LEFT,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_RIGHT
	};

	FVector computeAnchorOffset(float w, float h, RectAnchor anchor);
}



#endif // !RECTANCHOR_H