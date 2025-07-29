#include "RectAnchor.h"

namespace CE {

	FVector computeAnchorOffset(float w, float h, RectAnchor anchor) {
		FVector offset;

		switch (anchor) {
		case RectAnchor::CENTER:
			offset.x = w / 2;
			offset.y = h / 2;
			break;
		case RectAnchor::TOP:
			offset.x = w / 2;
			offset.y = 0;
			break;
		case RectAnchor::BOTTOM:
			offset.x = w / 2;
			offset.y = h;
			break;
		case RectAnchor::LEFT:
			offset.x = 0;
			offset.y = h / 2;
			break;
		case RectAnchor::RIGHT:
			offset.x = w;
			offset.y = h / 2;
			break;
		case RectAnchor::TOP_LEFT:
			offset.x = 0;
			offset.y = 0;
			break;
		case RectAnchor::TOP_RIGHT:
			offset.x = w;
			offset.y = 0;
			break;
		case RectAnchor::BOTTOM_LEFT:
			offset.x = 0;
			offset.y = h;
			break;
		case RectAnchor::BOTTOM_RIGHT:
			offset.x = w;
			offset.y = h;
			break;
		}

		return offset;
	}

}