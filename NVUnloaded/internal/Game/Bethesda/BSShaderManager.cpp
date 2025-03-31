#include "BSShaderManager.hpp"
#include "BSShaderAccumulator.hpp"

BSShaderManager::RenderPassType BSShaderManager::GetCurrentPass() {
#ifdef GAME
	return *(RenderPassType*)0x11F91E4;
#else
	return *(RenderPassType*)0xF23C34;
#endif
}

BSShaderProperty::RenderPass* BSShaderManager::GetCurrentRenderPass() {
#ifdef GAME
	return *(BSShaderProperty::RenderPass**)0x11F91E0;
#else
	return *(BSShaderProperty::RenderPass**)0xF23C30;
#endif
}

ShadowSceneNode* BSShaderManager::GetShadowSceneNode(uint32_t aeType) {
	return ((ShadowSceneNode**)0x11F91C8)[aeType];
}

BSShaderAccumulator* BSShaderManager::GetAccumulator() {
	return (*(BSShaderAccumulatorPtr*)0x11F95EC);
}

BSShaderAccumulator* BSShaderManager::GetCurrentAccumulator() {
	return (*(BSShaderAccumulatorPtr*)0x11F95F0);
}

NiDX9Renderer* BSShaderManager::GetRenderer() {
	return *(NiPointer<NiDX9Renderer>*)0x11F9508;
}