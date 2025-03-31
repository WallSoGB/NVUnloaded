#pragma once

#include "NiBackToFrontAccumulator.hpp"

NiSmartPointer(NiAlphaAccumulator);

class NiAlphaAccumulator : public NiBackToFrontAccumulator {
public:
	NiAlphaAccumulator();
	virtual ~NiAlphaAccumulator();

	bool m_bObserveNoSortHint;
	bool m_bSortByClosestPoint;
	bool m_bInterfaceSort;
};

ASSERT_SIZE(NiAlphaAccumulator, 0x34);