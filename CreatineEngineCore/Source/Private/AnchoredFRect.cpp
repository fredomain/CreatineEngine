#include "AnchoredFRect.h"
#include "Logger.h"

namespace CE {

	float AnchoredFRect::getX() const {
		return rect.x + anchorOffset.x;
	}

	void AnchoredFRect::setX(float x) {
		rect.x = x - anchorOffset.x;
		//printf("rect.x = %f\n", rect.x);
	}

	float AnchoredFRect::getY() const {
		return rect.y + anchorOffset.y;
	}

	void AnchoredFRect::setY(float y) {
		rect.y = y - anchorOffset.y;
		//printf("rect.y = %f\n", rect.y);
	}

	void AnchoredFRect::setPosition(float x, float y) {
		rect.x = x - anchorOffset.x;
		rect.y = y - anchorOffset.y;
	}

	void AnchoredFRect::setPosition(const FVector& position) {
		rect.x = position.x - anchorOffset.x;
		rect.y = position.y - anchorOffset.y;
	}

	FVector AnchoredFRect::getPosition() const {
		return FVector{ rect.x + anchorOffset.x, rect.y + anchorOffset.y };
	}

	FVector AnchoredFRect::getRectPosition() const {
		return FVector{ rect.x, rect.y };
	}

	const SDL_FRect* AnchoredFRect::getRect() const{
		return &rect;
	}

	void AnchoredFRect::setAnchor(RectAnchor anchor) {
		FVector userPosition = getPosition();	// Store the user position before computing the new anchor offset. This is needed because userPosition is computed through anchorOffset
		this->anchor = anchor;
		anchorOffset = computeAnchorOffset(rect.w, rect.h, anchor);
		// Update position to reflect the change in the anchor offset (using the user position stored)
		rect.x = userPosition.x - anchorOffset.x;
		rect.y = userPosition.y - anchorOffset.y;
	}

	RectAnchor AnchoredFRect::getAnchor() const {
		return anchor;
	}

	FVector AnchoredFRect::getAnchorOffset() const {
		return anchorOffset;
	}

	float AnchoredFRect::getWidth() const {
		return rect.w;
	}

	float AnchoredFRect::getHeight() const {
		return rect.h;
	}

	void AnchoredFRect::setWidth(float w) {
		FVector userPosition = getPosition();	// Store the user position before computing the new anchor offset. This is needed because userPosition is computed through anchorOffset
		rect.w = w;
		anchorOffset = computeAnchorOffset(rect.w, rect.h, anchor);
		// Update position to reflect the change in the anchor offset (using the user position stored)
		rect.x = userPosition.x - anchorOffset.x;
	}

	void AnchoredFRect::setHeight(float h) {
		FVector userPosition = getPosition();	// Store the user position before computing the new anchor offset. This is needed because userPosition is computed through anchorOffset
		rect.h = h;
		anchorOffset = computeAnchorOffset(rect.w, rect.h, anchor);
		// Update position to reflect the change in the anchor offset (using the user position stored)
		rect.y = userPosition.y - anchorOffset.y;
	}

	void AnchoredFRect::setSize(float w, float h) {
		FVector userPosition = getPosition();	// Store the user position before computing the new anchor offset. This is needed because userPosition is computed through anchorOffset
		rect.w = w;
		rect.h = h;
		anchorOffset = computeAnchorOffset(rect.w, rect.h, anchor);
		// Update position to reflect the change in the anchor offset (using the user position stored)
		rect.x = userPosition.x - anchorOffset.x;
		rect.y = userPosition.y - anchorOffset.y;
	}

	/*void AnchoredFRect::updateAnchorOffset(FVector position) {
		anchorOffset = computeAnchorOffset(rect.w, rect.h, anchor);
		// Update position to reflect the change in the anchor offset (using the user position stored)
		rect.x = position.x - anchorOffset.x;
		rect.y = position.y - anchorOffset.y;
	}*/

}
