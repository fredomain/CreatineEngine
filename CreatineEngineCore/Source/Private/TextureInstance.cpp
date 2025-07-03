#include "TextureInstance.h"

namespace CE {

	void TextureInstance::render() const {
		SDL_RenderTexture(texture.getRenderer(), texture.getData(), getSourceRectPtr(), getDestinationRectPtr());
	}

}
