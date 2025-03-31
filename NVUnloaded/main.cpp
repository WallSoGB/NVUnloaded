#include "nvse/PluginAPI.h"

#include "internal/Game/Bethesda/BSShaderAccumulator.hpp"
#include "internal/Game/Bethesda/BSShaderManager.hpp"
#include "internal/Game/Gamebryo/NiD3DTextureStage.hpp"
#include "internal/Game/Gamebryo/NiTexture.hpp"

bool bHighResViewmodel = false;
uint8_t ucRenderScale = 8;
uint8_t ucFilterMode = 0;
int8_t cSkinQualityModifier = 1;
int8_t cTextureSkipModifier = 0;
int8_t cCloudQualityModifier = 0;

struct MipSettings {
	float	fMipMapLODBias;
	uint8_t	ucMaxMipLevel;
};

uint32_t GetLargestSide(NiTexture* apTexture) {
	uint32_t uiWidth = apTexture->GetWidth();
	uint32_t uiHeight = apTexture->GetHeight();
	return uiWidth > uiHeight ? uiWidth : uiHeight;
}

uint8_t GetMaxMipForRes(uint32_t auiRes, bool abObjectLOD, bool abLandLOD) {
	if (abObjectLOD) {
		if (auiRes < 1024)
			return 0;
		else if (auiRes < 2048)
			return 1;
		else if (auiRes < 4096)
			return 2;
		else if (auiRes < 8192)
			return 3;
		else
			return 4;
	}
	else if (abLandLOD) {
		if (auiRes < 512)
			return 0;
		else if (auiRes < 1024)
			return 1;
		else if (auiRes < 2048)
			return 2;
		else if (auiRes < 4096)
			return 3;
		else
			return 4;
	}
	else {
		if (auiRes < 256)
			return 0;
		else if (auiRes < 512)
			return 1;
		else if (auiRes < 1024)
			return 2;
		else if (auiRes < 2048)
			return 3;
		else if (auiRes < 4096)
			return 4;
		else
			return 5;
	}
}

static NiFixedString kScopeCrosshair;

MipSettings GetMipSetting(uint8_t aucStage, NiTexture* apTexture) {
	MipSettings kSettings = { -1.25f, 4};
	if (!apTexture)
		return kSettings;

	BSShaderProperty::RenderPass* pPass = BSShaderManager::GetCurrentRenderPass();
	BSShaderAccumulator* pAccum = BSShaderManager::GetCurrentAccumulator();
	NiGeometry* pGeometry = pPass->pGeometry;
	bool bFirstPerson = pAccum && pAccum->bIs1stPerson;
	if (bFirstPerson && pGeometry->m_kName == kScopeCrosshair)
		return { 0.f, 0 };

	BSShaderProperty* pShadeProp = pGeometry->GetShadeProperty<BSShaderProperty>();

	bool bObjectLOD = false;
	bool bLandLOD	= false;

	if (pShadeProp) {
		bObjectLOD	= pShadeProp->IsLODBuilding();
		bLandLOD	= pShadeProp->IsLODLand();
	}

	uint32_t uiTextureRes = GetLargestSide(apTexture);

	BSShaderManager::RenderPassType ePass = BSShaderManager::GetCurrentPass();

	switch (ePass) {
	case BSShaderManager::BSSM_AMBDIFFTEX_Fg:
	case BSShaderManager::BSSM_AMBDIFFTEX_FgA:
	case BSShaderManager::BSSM_AMBDIFFTEX_GFgA:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFg:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFgA:
	case BSShaderManager::BSSM_AMBDIFFTEX_SGFgA:
	case BSShaderManager::BSSM_AMBDIFFTEX_FFg:
	case BSShaderManager::BSSM_AMBDIFFTEX_FGFgA:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFG:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFGVc:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFFg:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFGA:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFGAVc:
	case BSShaderManager::BSSM_AMBDIFFTEX_SFGFgA:
	case BSShaderManager::BSSM_ADTS_Fg:
	case BSShaderManager::BSSM_ADTS_SFg:
	case BSShaderManager::BSSM_ADTS_FgShp:
	case BSShaderManager::BSSM_ADTS_SFgShp:
	case BSShaderManager::BSSM_ADTS2_Fg:
	case BSShaderManager::BSSM_ADTS2_SFg:
	case BSShaderManager::BSSM_ADTS2_FgShp:
	case BSShaderManager::BSSM_ADTS2_SFgShp:
	case BSShaderManager::BSSM_ADT10_Fg:
	case BSShaderManager::BSSM_ADT10_SFg:
	case BSShaderManager::BSSM_ADT4_Fg:
	case BSShaderManager::BSSM_ADT4_SFg:
	case BSShaderManager::BSSM_ADTS10_Fg:
	case BSShaderManager::BSSM_ADTS10_SFg:
	case BSShaderManager::BSSM_AD2_Fg:
	case BSShaderManager::BSSM_AD2_SFg:
	case BSShaderManager::BSSM_AD2_FgShp:
	case BSShaderManager::BSSM_AD2_SFgShp:
	case BSShaderManager::BSSM_AD3_Fg:
	case BSShaderManager::BSSM_AD3_SFg:
	case BSShaderManager::BSSM_AD3_FgShp:
	case BSShaderManager::BSSM_AD3_SFgShp:
	case BSShaderManager::BSSM_ADT_Fg:
	case BSShaderManager::BSSM_ADT_SFg:
	case BSShaderManager::BSSM_ADT_FgShp:
	case BSShaderManager::BSSM_ADT_SFgShp:
	case BSShaderManager::BSSM_ADT2_Fg:
	case BSShaderManager::BSSM_ADT2_SFg:
	case BSShaderManager::BSSM_ADT2_FgShp:
	case BSShaderManager::BSSM_ADT2_SFgShp:
	case BSShaderManager::BSSM_DIFFUSEPT2_Fg:
	case BSShaderManager::BSSM_DIFFUSEPT2_SFg:
	case BSShaderManager::BSSM_DIFFUSEPT2_FgShp:
	case BSShaderManager::BSSM_DIFFUSEPT2_SFgShp:
	case BSShaderManager::BSSM_DIFFUSEPT3_Fg:
	case BSShaderManager::BSSM_DIFFUSEPT3_SFg:
	case BSShaderManager::BSSM_DIFFUSEPT3_FgShp:
	case BSShaderManager::BSSM_DIFFUSEPT3_SFgShp:
	case BSShaderManager::BSSM_TEXTURE_Fg:
	case BSShaderManager::BSSM_TEXTURE_SFg:
	case BSShaderManager::BSSM_3XLIGHTING_Fg:
	case BSShaderManager::BSSM_3XLIGHTING_SFg:
	case BSShaderManager::BSSM_3XLIGHTING_FgSpc:
	case BSShaderManager::BSSM_3XLIGHTING_SFgSpc:
	case BSShaderManager::BSSM_3XLIGHTING_FgShp:
	case BSShaderManager::BSSM_3XLIGHTING_SFgShp:
	case BSShaderManager::BSSM_3XLIGHTING_FgShpSpc:
	case BSShaderManager::BSSM_3XLIGHTING_SFgShpSpc:
	{
		kSettings.fMipMapLODBias = 0.f;
		if (!bFirstPerson && bHighResViewmodel)
			kSettings.ucMaxMipLevel = std::max(0, GetMaxMipForRes(uiTextureRes, false, false) - cSkinQualityModifier);
		break;
	}
	case BSShaderManager::BSSM_DISTANT_TREE_BASE:
	{
		kSettings.ucMaxMipLevel = GetMaxMipForRes(uiTextureRes, bObjectLOD, false);
		break;
	}
	case BSShaderManager::BSSM_ADT_Mn: 
	{
		if (aucStage == 7) {
			kSettings.ucMaxMipLevel = 0;
			kSettings.fMipMapLODBias = 0.f;
		}
		else {
			kSettings.ucMaxMipLevel = GetMaxMipForRes(uiTextureRes, bObjectLOD, bLandLOD);
		}
		break;
	}
	case BSShaderManager::BSSM_SKY_CLOUDS:
	case BSShaderManager::BSSM_SKY_CLOUDS_UNDERWATER: 
	{
		kSettings.ucMaxMipLevel = std::max(0, GetMaxMipForRes(uiTextureRes, false, false) - cCloudQualityModifier);
		break;
	}
	case BSShaderManager::BSSM_TILE:
	{
		kSettings.fMipMapLODBias = 0.f;
		kSettings.ucMaxMipLevel = 0;
		break;
	}
	default:
	{
		kSettings.ucMaxMipLevel = GetMaxMipForRes(uiTextureRes, bObjectLOD, bLandLOD) + cTextureSkipModifier;
		break;
	}
	}

	if (bFirstPerson && bHighResViewmodel) {
		kSettings.ucMaxMipLevel = std::max(0, kSettings.ucMaxMipLevel - 1);
	}

	return kSettings;
}


class NiD3DTextureStageEx : public NiD3DTextureStage {
public:
	bool ConfigureStage(bool abAllowRepeats) {
		MipSettings kSettings = GetMipSetting(m_uiStage, m_pkTexture);
		LPDIRECT3DDEVICE9 pD3DDevice = GetD3DDevice();
		DWORD uiMipMapLODBias = *(DWORD*)&kSettings.fMipMapLODBias;
		pD3DDevice->SetSamplerState(m_uiStage, D3DSAMP_MIPMAPLODBIAS, uiMipMapLODBias);
		pD3DDevice->SetSamplerState(m_uiStage, D3DSAMP_MAXMIPLEVEL, kSettings.ucMaxMipLevel);
		return ThisCall<bool>(0xE7EB00, this, abAllowRepeats);;
	}

	void SetFilterMode(uint32_t eFilter) {
		ThisCall(0xE7DEF0, this, 3);
	}
};

static uint32_t uiWidth = UINT32_MAX;
static uint32_t uiHeight = UINT32_MAX;

class NiDX9RendererEx {
public:
	uint32_t GetScreenWidth() {
		uint32_t uiOrgWidth = ThisCall(0xB6C1A0, this);
		uiWidth = uiOrgWidth / ucRenderScale;
		return uiWidth;
	}

	uint32_t GetScreenHeight() {
		uint32_t uiOrgHeight = ThisCall(0xB6C1D0, this);
		uiHeight = uiOrgHeight / ucRenderScale;
		return uiHeight;
	}
};

void NVSEMessageHandler(NVSEMessagingInterface::Message* msg) {
	if (msg->type == NVSEMessagingInterface::kMessage_DeferredInit)
		kScopeCrosshair = "AGRD";
}

EXTERN_DLL_EXPORT bool NVSEPlugin_Query(const NVSEInterface* nvse, PluginInfo* info) {
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "New Vegas Unloaded";
	info->version = 100;

	return !nvse->isEditor;
}

EXTERN_DLL_EXPORT bool NVSEPlugin_Load(NVSEInterface* nvse) {
	if (!nvse->isEditor) {
		static_cast<NVSEMessagingInterface*>(nvse->QueryInterface(kInterface_Messaging))->RegisterListener(nvse->GetPluginHandle(), "NVSE", NVSEMessageHandler);

		ucRenderScale = GetPrivateProfileInt("Render", "uRenderScale", 8, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		ucFilterMode = GetPrivateProfileInt("Textures", "uFilterMode", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		cTextureSkipModifier = GetPrivateProfileInt("Textures", "iTextureSkipModifier", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		cCloudQualityModifier = GetPrivateProfileInt("Textures", "iCloudQualityModifier", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		cSkinQualityModifier = GetPrivateProfileInt("Textures", "iSkinQualityModifier", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		bHighResViewmodel = GetPrivateProfileInt("Textures", "bHighResViewmodel", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");
		bool bLessColors = GetPrivateProfileInt("Render", "bDecreaseColorDepth", 0, "Data\\NVSE\\Plugins\\NewVegasUnloaded.ini");

		ucRenderScale = std::max(1ui8, std::min(16ui8, ucRenderScale));

		for (uint32_t uiCallAddr : {0xB7C1C3, 0xB8083C, 0xB809C0, 0xB83E3C, 0xB83E76, 0xB83EB0, 0xB83EEA, 0xB83F24, 0xBB07D3, 0xBB6500, 0xBB65E0, 0xBB66E5, 0xBC5592, 0xBD213F, 0xBE0DAC, 0xBF600E, 0xBF62BA, 0xBF6572, 0xC02F16, 0xC09E42, 0xC09F48, 0xC0A043, 0xC0A15A, 0xC0CE79, 0xE7C91E, 0xE8DB6C, }) {
			ReplaceCallEx(uiCallAddr, &NiD3DTextureStageEx::SetFilterMode);
		}

		for (uint32_t uiCallAddr : {0xB7DD63, 0xB7DE52, 0xB7DE65, 0xB7DF45, 0xB7DF58, 0xB7E059, 0xB7E06C, 0xB7E200, 0xB7E213, 0xB7E225, 0xB89CF7, 0xB89D68, 0xBA627E, 0xBB66EE, 0xBC8D82, 0xBCA913, 0xBCA92D, 0xBE219A, 0xBE21E2, 0xC043A4, 0xE7F8D3 }) {
			ReplaceCallEx(uiCallAddr, &NiD3DTextureStageEx::ConfigureStage);
		}
		WriteRelJumpEx(0xBCBCD0, &NiD3DTextureStageEx::ConfigureStage);

		if (ucRenderScale != 1) {
			for (uint32_t uiCallAddr : { 0xB6C357, 0xB6C478, 0xB6C4B4, 0xB6C8FE, 0xB6C9F3, 0xB6CB71, 0xB6CBD7, 0xB6CC26, 0xB6CE7B }) {
				ReplaceCallEx(uiCallAddr, &NiDX9RendererEx::GetScreenWidth);
			}

			for (uint32_t uiCallAddr : { 0xB6C485, 0xB6C4C1, 0xB6C90B, 0xB6CA00, 0xB6CB81, 0xB6CBE4, 0xB6CC33, 0xB6CE88 }) {
				ReplaceCallEx(uiCallAddr, &NiDX9RendererEx::GetScreenHeight);
			}
		}
		
		if (bLessColors) {
			SafeWrite8(0xB6C49A + 2, D3DFMT_X1R5G5B5);
			SafeWrite8(0xB6C50D + 2, D3DFMT_X1R5G5B5);
			SafeWrite8(0xB6CC48 + 2, D3DFMT_X1R5G5B5);
		}
	}

	return true;
}

BOOL WINAPI DllMain(
	HANDLE  hDllHandle,
	DWORD   dwReason,
	LPVOID  lpreserved
)
{
	return TRUE;
}
