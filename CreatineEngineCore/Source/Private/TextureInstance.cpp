#include "TextureInstance.h"
#include <print>

namespace CE {

	TextureInstance::TextureInstance(Texture* texture) : texture(texture){
		texture->addUpdateCallback(&TextureInstance::onTextureLoaded, this);

		// if texture is already loaded, set the needed parameters
		if (texture->isValid()) {
			setSourceWidth(static_cast<float>(texture->getWidth()));
			setSourceHeight(static_cast<float>(texture->getHeight()));
			//std::print("Source setted\n");
		}
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
