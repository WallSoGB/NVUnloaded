#pragma once

#include "NiTransform.hpp"
#include "BSMemObject.hpp"

class NiCamera;

class NiBound {
public:
	NiBound() : m_kCenter(NiPoint3(0.0f,0.0f,0.0f)) , m_iRadius(0) {};
	NiBound(NiPoint3 akCenter, float afRadius) : m_kCenter(akCenter) , m_fRadius(afRadius) {};
	~NiBound() {};

	NiPoint3	m_kCenter;
	union {
		int32_t		m_iRadius;
		float		m_fRadius;
	};

	static float	ms_fFuzzFactor;
	static float	ms_fTolerance;

	bool operator==(const NiBound& arOther) const {
		return m_kCenter == arOther.m_kCenter && m_fRadius == arOther.m_fRadius;
	}

	BS_ALLOCATORS
};

ASSERT_SIZE(NiBound, 0x10);