#pragma once

#include "NiProperty.hpp"

class NiTexture;
class NiTextureTransform;

NiSmartPointer(NiTexturingProperty);

class NiTexturingProperty : public NiProperty {
public:
	NiTexturingProperty();
	virtual ~NiTexturingProperty();

	enum ApplyMode {
		APPLY_REPLACE		= 0,
		APPLY_DECAL			= 1,
		APPLY_MODULATE		= 2,
		APPLY_DEPRECATED	= 3,
		APPLY_DEPRECATED2	= 4,
		APPLY_MAX_MODES,
	};

	enum FilterMode {
		FILTER_NEAREST				= 0,
		FILTER_BILERP				= 1,
		FILTER_TRILERP				= 2,
		FILTER_NEAREST_MIPNEAREST	= 3,
		FILTER_NEAREST_MIPLERP		= 4,
		FILTER_BILERP_MIPNEAREST	= 5,
		FILTER_ANISOTROPY			= 6,
		FILTER_ANISOTROPY_2			= 7,
		FILTER_MAX_MODES,
	};

	enum ClampMode {
		CLAMP_S_CLAMP_T = 0,
		CLAMP_S_WRAP_T	= 1,
		WRAP_S_CLAMP_T	= 2,
		WRAP_S_WRAP_T	= 3,
		CLAMP_MAX_MODES,
	};
};