#pragma once

#include "NiTexturingProperty.hpp"

class NiD3DTextureStageGroup;
class NiGlobalConstantEntry;
class NiDX9RenderState;
class NiDX9Renderer;

class NiD3DTextureStage : public NiMemObject {
public:
	NiD3DTextureStage();
	~NiD3DTextureStage();

	NiTexturingProperty::FilterMode		m_eFilter;
	uint32_t							m_uiStage;
	NiTexture*							m_pkTexture;
	uint32_t							m_uiTextureFlags;
	NiD3DTextureStageGroup*				m_pkTextureStageGroup;
	uint32_t							m_uiTextureTransformFlags;
	NiGlobalConstantEntry*				m_pkGlobalEntry;
	D3DMATRIX							m_kTextureTransformation;
	uint16_t							m_usObjTextureFlags;
	bool								m_bTextureTransform;
	bool								m_bRendererOwned;
	uint32_t							m_uiRefCount;
	bool								bApply;
	bool								bUnk65;
	bool								bUnk66;
	bool								bUnk67;

	static NiDX9RenderState* GetRenderState();
	static NiDX9Renderer* GetRenderer();
	static LPDIRECT3DDEVICE9 GetD3DDevice();
};

ASSERT_SIZE(NiD3DTextureStage, 0x68);