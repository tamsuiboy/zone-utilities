#ifndef EQEMU_COMMON_WATER_MAP_H
#define EQEMU_COMMON_WATER_MAP_H

#include <stdint.h>
#include <string>
#include <vector>

#include "eq_math.h"

enum WaterRegionType {
	RegionTypeUnsupported = -2,
	RegionTypeUntagged = -1,
	RegionTypeNormal = 0,
	RegionTypeWater = 1,
	RegionTypeLava = 2,
	RegionTypeZoneLine = 3,
	RegionTypePVP = 4,
	RegionTypeSlime = 5,
	RegionTypeIce = 6,
	RegionTypeVWater = 7,
	RegionTypeGeneralArea = 8,
	RegionTypePreferPathing = 9,
	RegionTypeDisableNavMesh = 10
};

struct RegionDetails
{
	glm::vec3 verts[8];
	WaterRegionType type;
};

class WaterMap
{
public:
	WaterMap() { }
	~WaterMap() { }
	
	static WaterMap* LoadWaterMapfile(std::string dir, std::string zone_name);
	virtual WaterRegionType ReturnRegionType(float y, float x, float z) const { return RegionTypeNormal; }
	virtual bool InWater(float y, float x, float z) const { return false; }
	virtual bool InVWater(float y, float x, float z) const { return false; }
	virtual bool InLava(float y, float x, float z) const { return false; }
	virtual bool InLiquid(float y, float x, float z) const { return false; }
	virtual void CreateMeshFrom(std::vector<glm::vec3> &verts, std::vector<unsigned int> &inds) { }
	virtual void GetRegionDetails(std::vector<RegionDetails> &details) { };
protected:
	virtual bool Load(FILE *fp) { return false; }
};

#endif
