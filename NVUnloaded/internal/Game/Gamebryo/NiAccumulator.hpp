#pragma once

#include "NiObject.hpp"

class NiGeometry;
class NiCamera;
class NiAVObject;

NiSmartPointer(NiAccumulator);

class NiAccumulator : public NiObject {
public:
	NiAccumulator();
	virtual ~NiAccumulator();

	virtual void StartAccumulating(const NiCamera* pkCamera);
	virtual void FinishAccumulating();
	virtual void RegisterObjectArray(void* kArray);
	virtual bool RegisterObject(NiGeometry* apGeometry);
	virtual bool AddShared(NiAVObject* apObject);
	virtual void ClearSharedMap();

	NiCamera* m_pkCamera;
};

ASSERT_SIZE(NiAccumulator, 0xC);