#pragma once

#include "NiAVObject.hpp"
#include "NiPropertyState.hpp"

class NiGeometryData;
class NiSkinInstance;
class NiRenderer;
class BSShader;
class NiColorA;
class NiPoint2;

NiSmartPointer(NiGeometry);

class NiGeometry : public NiAVObject {
public:
	NiGeometry();
	virtual ~NiGeometry();

	virtual void	RenderImmediate(NiRenderer* pkRenderer);
	virtual void	RenderImmediateAlt(NiRenderer* pkRenderer);
	virtual void	SetModelData(NiGeometryData* pkModelData);
	virtual void	CalculateNormals();
	virtual void	CalculateConsistency(bool bTool);

	struct RendererData {};

	NiPropertyState				m_kProperties;
	NiPointer<NiGeometryData>	m_spModelData;
	NiPointer<NiSkinInstance>	m_spSkinInstance;
	BSShader*					m_pShader;

	__forceinline NiMaterialProperty* GetMaterialProperty() const { return m_kProperties.GetMaterialProperty(); };

	template <class T>
	T* GetShadeProperty() const { return static_cast<T*>(m_kProperties.GetShadeProperty<T>()); };
	NiShadeProperty* GetShadeProperty() const { return m_kProperties.GetShadeProperty<NiShadeProperty>();};
};

ASSERT_SIZE(NiGeometry, 0xC4);