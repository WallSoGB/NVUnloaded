#pragma once

#include "NiAccumulator.hpp"
#include "NiGeometry.hpp"
#include "NiTPointerList.hpp"

typedef NiTPointerList<NiGeometry*> NiSortedObjectList;

NiSmartPointer(NiBackToFrontAccumulator);

class NiBackToFrontAccumulator : public NiAccumulator {
public:
	NiBackToFrontAccumulator();
	virtual ~NiBackToFrontAccumulator();

	virtual void Sort();

	NiSortedObjectList	m_kItems;
	NiSortedObjectList* m_pGeometryList;
	int32_t				m_iNumItems;
	int32_t				m_iMaxItems;
	NiGeometry**		m_ppkItems;
	float*				m_pfDepths;
	int32_t				m_iCurrItem;
};

ASSERT_SIZE(NiBackToFrontAccumulator, 0x30);