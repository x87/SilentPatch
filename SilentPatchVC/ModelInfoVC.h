#pragma once

#include <rwcore.h>
#include <rpworld.h>

class CVehicleModelInfo
{
public:
	uint8_t		 __pad1[40];
	RpClump*	 m_clump;
	uint8_t		 __pad3[16];
	unsigned int m_dwType;
	uint8_t		 __pad4[11];
	int8_t		 m_numComps;
	uint8_t		 __pad2[268];
	RpAtomic*	 m_comps[6];
	uint8_t		 __pad5[4];

public:
	RwFrame*		GetExtrasFrame( RpClump* clump );

	// For SkyGfx interop
	static void AttachCarPipeToRwObject_Default(RwObject*) { }
	static inline void (*AttachCarPipeToRwObject)(RwObject* object) = &AttachCarPipeToRwObject_Default;
};

static_assert(sizeof(CVehicleModelInfo) == 0x174, "Wrong size: CvehicleModelInfo");