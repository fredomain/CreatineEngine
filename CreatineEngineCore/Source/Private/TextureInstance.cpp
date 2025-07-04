#include "TextureInstance.h"

namespace CE {

	TextureInstance::TextureInstance(Texture&) : texture(texture){
		texture->addUpdateCallback(&TextureInstance::onTextureLoaded, this);
	}

	TextureInstance::~TextureInstance() {
		if (texture) {
			texture->removeUpdateCallback(this);
		}
		
	}

	void TextureInstance::render() const {
		SDL_RenderTexture(texture->getRenderer(), texture->getData(), getSourceRectPtr(), getDestinationRectPtr());
	}

	void TextureInstance::onTextureLoaded(void* callbackObject) {
		TextureInstance* self = static_cast<TextureInstance*>(callbackObject);
		self->setSourceWidth(static_cast<float>(self->texture->getWidth()));
		self->setSourceHeight(static_cast<float>(self->texture->getHeight()));
	}

}
