#include "ImageAssetGPU.h"

namespace CE {

	ImageAssetGPU::ImageAssetGPU(SDL_Renderer* renderer, const std::string& path, AssetManager* assetManager = nullptr)
		: Asset(path, assetManager), texture(nullptr), renderer(renderer) {
	}

	ImageAssetGPU::ImageAssetGPU(SDL_Renderer* renderer, std::string&& path, AssetManager* assetManager = nullptr)
		: Asset(path, assetManager), texture(nullptr), renderer(renderer) {
	}

	bool ImageAssetGPU::load(){

	}
}