#include "NiD3DTextureStage.hpp"

NiDX9RenderState* NiD3DTextureStage::GetRenderState() {
#ifdef GAME
	return *(NiDX9RenderState**)0x126F6C8;
#else
	return *(NiDX9RenderState**)0xF98360;
#endif
}

NiDX9Renderer* NiD3DTextureStage::GetRenderer() {
#ifdef GAME
	return *(NiDX9Renderer**)0x126F6C4;
#else
	return *(NiDX9Renderer**)0xF9835C;
#endif
}

LPDIRECT3DDEVICE9 NiD3DTextureStage::GetD3DDevice() {
#ifdef GAME
	return *(LPDIRECT3DDEVICE9*)0x126F6C0;
#else
	return *(LPDIRECT3DDEVICE9*)0xF98358;
#endif
}