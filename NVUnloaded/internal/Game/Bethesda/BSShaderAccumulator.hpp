#pragma once

#include "NiAlphaAccumulator.hpp"

NiSmartPointer(BSShaderAccumulator)

class BSShaderProperty;
class BSInstanceRendering;
class ShadowSceneNode;

class BSShaderAccumulator : public NiAlphaAccumulator {
public:

	virtual void FinishAccumulatingPreResolveDepth();
	virtual void FinishAccumulatingPostResolveDepth();
	virtual void RenderPassList(uint32_t, bool); // Oblivion leftover

	struct SunOcclusionTest {
		void*		pOcclusionQuery;
		bool		bWaiting;
		float		fPercentOccluded;
		uint32_t	uiPixelCount;
		uint32_t	uiFrameCount;
	};

	uint32_t								unk034;
	bool									bWireFrameRelated;
	bool									unk039;
	bool									bRenderDOF;
	uint32_t								uiSunPixelCount;
	bool									bWaitingForSunQuery;
	float									fPercentSunOccludedStored;
	SunOcclusionTest						kSunTests[3];
	bool									bProcessLights;
	bool									bIs1stPerson;
	// cut off
};