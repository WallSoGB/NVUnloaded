#pragma once

#include "NiAVObject.hpp"
#include "NiSkinPartition.hpp"
#include "NiSkinData.hpp"

NiSmartPointer(NiSkinInstance);

class NiSkinInstance : public NiObject {
public:
	NiSkinInstance();
	virtual ~NiSkinInstance();

	NiSkinDataPtr		m_spSkinData;
	NiSkinPartitionPtr	m_spSkinPartition;
	NiAVObject*			m_pkRootParent;
	NiAVObject**		m_ppkBones;
	uint32_t			m_uiFrameID;
	uint32_t			m_uiNumMatrices;
	uint32_t			m_uiNumRegisters;
	uint32_t			m_uiAllocatedSize;
	void*				m_pvBoneMatrices;
	void*				unk2C;
	void*				m_pvSkinToWorldWorldToSkinMatrix;

	CREATE_OBJECT(NiSkinInstance, 0xA866F0);
	NIRTTI_ADDRESS(0x11F5B2C);

	static NiSkinInstance* Create(NiSkinData* apSkinData, NiAVObject* apRootParent, NiAVObject** ppBones);

	void UpdateModelBound(NiBound& arBound);

	__forceinline NiSkinPartition* GetSkinPartition() const { return m_spSkinPartition.m_pObject; };
	void SetSkinPartition(NiSkinPartition* pkSkinPartition) { m_spSkinPartition = pkSkinPartition; };

	__forceinline NiSkinData* GetSkinData() const { return m_spSkinData.m_pObject; };
	void SetSkinData(NiSkinData* pkSkinData) { m_spSkinData = pkSkinData; };

	void GetWorldToSkinTransform(NiTransform& arWorldToSkin) const;

	void SetBoneMatrices(void* apMatrices, uint32_t auiAllocatedSize);
	void SetBoneMatrixInfo(uint32_t auiNumMatrices, uint32_t auiNumRegisters);
};

ASSERT_SIZE(NiSkinInstance, 0x34);