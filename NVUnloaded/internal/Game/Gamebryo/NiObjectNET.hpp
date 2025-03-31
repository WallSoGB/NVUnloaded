#pragma once

#include "NiObject.hpp"
#include "NiFixedString.hpp"

class NiTimeController;
class NiExtraData;

class NiObjectNET : public NiObject {
public:
	NiObjectNET();
	virtual ~NiObjectNET();

	NiFixedString					m_kName;
	NiPointer<NiTimeController>		m_spControllers;
	NiExtraData**					m_ppkExtra;
	uint16_t						m_usExtraDataSize;
	uint16_t						m_usMaxSize;

	const char* GetName() const { return m_kName.m_kHandle; };
	void SetName(const NiFixedString& arString) { m_kName = arString;	};
};

ASSERT_SIZE(NiObjectNET, 0x18);