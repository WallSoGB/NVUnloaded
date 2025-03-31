#pragma once

#include "NiShadeProperty.hpp"

class BSShaderAccumulator;
class NiSourceTexture;
class Lighting30ShaderProperty;
class ShadowSceneLight;
class BGSTextureUseMap;

NiSmartPointer(BSShaderProperty);

enum Flags {
	BSSP_SPECULAR						= 0,
	BSSP_SKINNED						= 1,
	BSSP_LOW_DETAIL						= 2,
	BSSP_VERTEX_ALPHA					= 3,
	BSSP_MOTION_BLUR					= 4,
	BSSP_SINGLE_PASS					= 5,
	BSSP_EMPTY							= 6,
	BSSP_ENVIRONMENT_MAPPING			= 7,
	BSSP_ALPHA_TEXTURE					= 8,
	BSSP_ZPREPASS						= 9,
	BSSP_FACEGEN						= 10,
	BSSP_PARALLAX						= 11,
	BSSP_MODEL_SPACE_NORMALS			= 12,
	BSSP_NON_PROJECTIVE_SHADOWS			= 13,
	BSSP_LANDSCAPE						= 14,
	BSSP_REFRACTION						= 15,
	BSSP_FIRE_REFRACTION				= 16,
	BSSP_EYE_ENVIRONMENT_MAPPING		= 17,
	BSSP_HAIR							= 18,
	BSSP_DYNAMIC_ALPHA					= 19,
	BSSP_LOCAL_MAP_HIDE_SECRET			= 20,
	BSSP_WINDOW_ENVIRONMENT_MAPPING		= 21,
	BSSP_TREE_BILLBOARD					= 22,
	BSSP_SHADOW_FRUSTUM					= 23,
	BSSP_MULTIPLE_TEXTURES				= 24,
	BSSP_REMAPPABLE_TEXTURES			= 25,
	BSSP_DECAL							= 26,
	BSSP_DYNAMIC_DECAL					= 27,
	BSSP_PARALLAX_OCCLUSION				= 28,
	BSSP_EXTERNAL_EMITTANCE				= 29,
	BSSP_SHADOW_MAP						= 30,
	BSSP_ZBUFFER_TEST					= 31,
	BSSP_ZBUFFER_WRITE					= 32,
	BSSP_LOD_LANDSCAPE					= 33,
	BSSP_LOD_BUILDING					= 34,
	BSSP_NO_FADE						= 35,
	BSSP_REFRACTION_TINT				= 36,
	BSSP_VERTEX_COLORS					= 37,
	BSSP_1ST_PERSON						= 38,
	BSSP_1ST_LIGHT_IS_POINTLIGHT		= 39,
	BSSP_2ND_LIGHT						= 40,
	BSSP_3RD_LIGHT						= 41,
	BSSP_VERTEX_LIGHTING				= 42,
	BSSP_UNIFORM_SCALE					= 43,
	BSSP_FIT_SLOPE						= 44,
	BSSP_BILLBOARD_ENV_FADE				= 45,
	BSSP_NO_LOD_LAND_BLEND				= 46,
	BSSP_ENVMAP_LIGHT_FADE				= 47,
	BSSP_WIRE_FRAME						= 48,
	BSSP_VATS_SELECTION					= 49,
	BSSP_SHOW_IN_LOCAL_MAP				= 50,
	BSSP_PREMULT_ALPHA					= 51,
	BSSP_SKIP_NORMAL_MAPS				= 52,
	BSSP_ALPHA_DECAL					= 53,
	BSSP_NO_TRANSPARENCY_MULTISAMPLING	= 54,
	BSSP_STINGER_PROP					= 55,
	BSSP_UNK3							= 56,
	BSSP_UNK4							= 57,
	BSSP_UNK5							= 58,
	BSSP_UNK6							= 59,
	BSSP_UNK7							= 60,
	BSSP_UNK8							= 61,
	BSSP_UNK9							= 62,
	BSSP_REALTIME_CUBEMAP				= 63,
	BSSP_MAX_FLAGS						= 64
};


class BSShaderProperty : public NiShadeProperty {
public:
	BSShaderProperty();
	virtual ~BSShaderProperty();

	enum BSShaderFlags {
		Specular					= 0x1,
		Skinned						= 0x2,
		LowDetail					= 0x4,
		Vertex_Alpha				= 0x8,
		Motion_Blur					= 0x10,
		Single_Pass					= 0x20,
		Empty						= 0x40,
		Environment_Mapping			= 0x80,
		Alpha_Texture				= 0x100,
		Z_Prepass					= 0x200,
		FaceGen						= 0x400,
		Parallax_Shader				= 0x800,
		Model_Space_Normals			= 0x1000,
		Non_Projective_Shadows		= 0x2000,
		Landscape					= 0x4000,
		Refraction					= 0x8000,
		Fire_Refraction				= 0x10000,
		Eye_Environment_Mapping		= 0x20000,
		Hair						= 0x40000,
		Dynamic_Alpha				= 0x80000,
		Localmap_Hide_Secret		= 0x100000,
		Window_Environment_Mapping	= 0x200000,
		Tree_Billboard				= 0x400000,
		Shadow_Frustum				= 0x800000,
		Multiple_Textures			= 0x1000000,
		Remappable_Textures			= 0x2000000,
		Decal_Single_Pass			= 0x4000000,
		Dynamic_Decal_Single_Pass	= 0x8000000,
		Parallax_Occlusion			= 0x10000000,
		External_Emittance			= 0x20000000,
		Shadow_Map					= 0x40000000,
		ZBuffer_Test				= 0x80000000,
	};

	enum BSShaderFlags2 {
		ZBuffer_Write					= 0x1,
		LOD_Landscape					= 0x2,
		LOD_Building					= 0x4,
		No_Fade							= 0x8,
		Refraction_Tint					= 0x10,
		Vertex_Colors					= 0x20,
		_1st_person						= 0x40,
		_1st_Light_is_Point_Light		= 0x80,
		_2nd_Light						= 0x100,
		_3rd_Light						= 0x200,
		Vertex_Lighting					= 0x400,
		Uniform_Scale					= 0x800,
		Fit_Slope						= 0x1000,
		Billboard_and_Envmap_Light_Fade = 0x2000,
		No_LOD_Land_Blend				= 0x4000,
		Envmap_Light_Fade				= 0x8000,
		Wireframe						= 0x10000,
		VATS_Selection					= 0x20000,
		Show_in_Local_Map				= 0x40000,
		Premult_Alpha					= 0x80000,
		Skip_Normal_Maps				= 0x100000,
		Alpha_Decal						= 0x200000,
		No_Transparency_Multisampling	= 0x400000,
		stinger_prop					= 0x800000,
		Unknown3						= 0x1000000,
		Unknown4						= 0x2000000,
		Unknown5						= 0x4000000,
		Unknown6						= 0x8000000,
		Unknown7						= 0x10000000,
		Unknown8						= 0x20000000,
		Unknown9						= 0x40000000,
		Wall_RealTimeEnv				= 0x80000000,
	};

	class RenderPass {
	public:
		enum AccumMode : uint8_t {
			ACCUM_NONE				= 0,
			ACCUM_ALPHA_BLEND		= 1,
			ACCUM_UNK_2				= 2,
			ACCUM_PARTICLE			= 3,
			ACCUM_DECAL_SINGLE		= 4,
			ACCUM_DYN_DECAL_SINGLE	= 5,
			ACCUM_REFRACTION		= 6,
			ACCUM_REFRACTION_CLEAR	= 7,
			ACCUM_UNK_8				= 8,
			ACCUM_UNK_9				= 9,
			ACCUM_LOD				= 10,
			ACCUM_UNK_11			= 11,
			ACCUM_UNK_12			= 12,
			ACCUM_UNK_13			= 13,
			ACCUM_ALPHA_FADE		= 14,
		};

		NiGeometry*			pGeometry;
		uint16_t			usPassEnum;
		AccumMode			eAccumulationHint;
		bool				bIsFirst;
		bool				bNoFog;
		uint8_t				ucNumLights;
		uint8_t				ucMaxNumLights;
		uint8_t				cCurrLandTexture;
		ShadowSceneLight**	ppSceneLights;
	};

	class RenderPassArray;

	virtual void						CopyTo(BSShaderProperty* apTarget);
	virtual void						CopyData(BSShaderProperty* apTarget);
	virtual void						SetupGeometry(NiGeometry* apGeometry);
	virtual RenderPassArray*			GetRenderPasses(const NiGeometry* apGeometry, const uint32_t auiEnabledPasses, uint16_t* apusPassCount, const uint32_t aeRenderMode, BSShaderAccumulator* apAccumulator, bool abAddPass);
	virtual uint16_t					GetNumberofPasses(NiGeometry* apGeometry);
	virtual RenderPassArray*			GetRenderPassArray4C();
	virtual RenderPass*					GetDepthPass(NiGeometry* apGeometry);
	virtual BSShaderProperty*			PickShader(NiGeometry* apGeometry, uint32_t unk0 = 0, uint32_t unk2 = 1);
	virtual NiSourceTexture*			GetDiffuseTexture() const;
	virtual RenderPassArray*			GetWaterDepthPass(NiGeometry* apGeometry);
	virtual void						CountTextures(void* apCountFunc, BGSTextureUseMap* apTexMap) const;
	virtual void						PrecacheTextures() const;

	uint32_t			ulFlags[2];
	float				fAlpha;
	float				fFadeAlpha;
	float				fEnvMapScale;
	float				fLODFade;
	int32_t				iLastRenderPassState;
	RenderPassArray*	pRenderPassArray;
	RenderPassArray*	pRenderPassArray_depthMap;
	RenderPassArray*	pRenderPassArray_constAlpha;
	RenderPassArray*	pRenderPassArray_localMap;
	RenderPassArray*	pRenderPassArray_siblock;
	RenderPassArray*	pRenderPassArray_waterDepth;
	RenderPassArray*	pRenderPassArray_silhouette;
	uint32_t			uiShaderIndex;
	float				fDepthBias;

	bool GetFlag(uint32_t auiFlag) const;
	void SetFlag(uint32_t auiFlag, bool abEnable);

	bool HasSpecular() const { return (ulFlags[0] & Specular) != 0; }
	bool IsSkinned() const { return (ulFlags[0] & Skinned) != 0; }
	bool IsLowDetail() const { return (ulFlags[0] & LowDetail) != 0; }
	bool HasVertexAlpha() const { return (ulFlags[0] & Vertex_Alpha) != 0; }
	bool HasMotionBlur() const { return (ulFlags[0] & Motion_Blur) != 0; }
	bool IsSinglePass() const { return (ulFlags[0] & Single_Pass) != 0; }
	bool IsEmpty() const { return (ulFlags[0] & Empty) != 0; }
	bool HasEnvironmentMap() const { return (ulFlags[0] & Environment_Mapping) != 0; }
	bool HasAlphaTexture() const { return (ulFlags[0] & Alpha_Texture) != 0; }
	bool IsZPrePass() const { return (ulFlags[0] & Z_Prepass) != 0; }
	bool IsFaceGen() const { return (ulFlags[0] & FaceGen) != 0; }
	bool IsParallax() const { return (ulFlags[0] & Parallax_Shader) != 0; }
	bool HasModelSpaceNormals() const { return (ulFlags[0] & Model_Space_Normals) != 0; }
	bool HasNonProjectiveShadows() const { return (ulFlags[0] & Non_Projective_Shadows) != 0; }
	bool IsLandscape() const { return (ulFlags[0] & Landscape) != 0; }
	bool HasRefraction() const { return (ulFlags[0] & Refraction) != 0; }
	bool HasFireRefraction() const { return (ulFlags[0] & Fire_Refraction) != 0; }
	bool HasEyeEnvironmentMap() const { return (ulFlags[0] & Eye_Environment_Mapping) != 0; }
	bool IsHair() const { return (ulFlags[0] & Hair) != 0; }
	bool HasDynamicAlpha() const { return (ulFlags[0] & Dynamic_Alpha) != 0; }
	bool IsLocalMapHideSecret() const { return (ulFlags[0] & Localmap_Hide_Secret) != 0; }
	bool HasWindowEnvironmentMap() const { return (ulFlags[0] & Window_Environment_Mapping) != 0; }
	bool IsTreeBillboard() const { return (ulFlags[0] & Tree_Billboard) != 0; }
	bool UsesShadowFrustum() const { return (ulFlags[0] & Shadow_Frustum) != 0; }
	bool HasMultipleTextures() const { return (ulFlags[0] & Multiple_Textures) != 0; }
	bool HasRemappableTextures() const { return (ulFlags[0] & Remappable_Textures) != 0; }
	bool IsSinglePassDecal() const { return (ulFlags[0] & Decal_Single_Pass) != 0; }
	bool IsSinglePassDynamicDecal() const { return (ulFlags[0] & Dynamic_Decal_Single_Pass) != 0; }
	bool HasParallaxOcclusion() const { return (ulFlags[0] & Parallax_Occlusion) != 0; }
	bool HasExternalEmittance() const { return (ulFlags[0] & External_Emittance) != 0; }
	bool IsShadowMap() const { return (ulFlags[0] & Shadow_Map) != 0; }
	bool HasZBufferTest() const { return (ulFlags[0] & ZBuffer_Test) != 0; }
	bool HasZBufferWrite() const { return (ulFlags[1] & ZBuffer_Write) != 0; }
	bool IsLODLand() const { return (ulFlags[1] & LOD_Landscape) != 0; }
	bool IsLODBuilding() const { return (ulFlags[1] & LOD_Building) != 0; }
	bool HasNoFade() const { return (ulFlags[1] & No_Fade) != 0; }
	bool HasRefractionTint() const { return (ulFlags[1] & Refraction_Tint) != 0; }
	bool HasVertexColors() const { return (ulFlags[1] & Vertex_Colors) != 0; }
	bool Is1stPerson() const { return (ulFlags[1] & _1st_person) != 0; }
	bool Is1stLightPointlight() const { return (ulFlags[1] & _1st_Light_is_Point_Light) != 0; }
	bool Is2ndLight() const { return (ulFlags[1] & _2nd_Light) != 0; }
	bool Is3rdLight() const { return (ulFlags[1] & _3rd_Light) != 0; }
	bool HasVertexLighting() const { return (ulFlags[1] & Vertex_Lighting) != 0; }
	bool HasUniformScale() const { return (ulFlags[1] & Uniform_Scale) != 0; }
	bool DoesFitSlopes() const { return (ulFlags[1] & Fit_Slope) != 0; }
	bool HasBillboardAndEnvmapLightFade() const { return (ulFlags[1] & Billboard_and_Envmap_Light_Fade) != 0; }
	bool HasNoLODLandBlend() const { return (ulFlags[1] & No_LOD_Land_Blend) != 0; }
	bool HasEnvmapLightFade() const { return (ulFlags[1] & Envmap_Light_Fade) != 0; }
	bool IsWireframe() const { return (ulFlags[1] & Wireframe) != 0; }
	bool IsVATSSelection() const { return (ulFlags[1] & VATS_Selection) != 0; }
	bool IsShownOnMap() const { return (ulFlags[1] & Show_in_Local_Map) != 0; }
	bool HasPremultAlpha() const { return (ulFlags[1] & Premult_Alpha) != 0; }
	bool DoesSkipNormalMaps() const { return (ulFlags[1] & Skip_Normal_Maps) != 0; }
	bool IsAlphaDecal() const { return (ulFlags[1] & Alpha_Decal) != 0; }
	bool HasNoTMSAA() const { return (ulFlags[1] & No_Transparency_Multisampling) != 0; }
	bool IsStingerProperty() const { return (ulFlags[1] & stinger_prop) != 0; }
	bool HasRealtimeCubeMaps() const { return (ulFlags[1] & Wall_RealTimeEnv) != 0; }
};

ASSERT_SIZE(BSShaderProperty, 0x60);