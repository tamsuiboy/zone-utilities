#ifndef EQEMU_MAP_VIEW_MODULE_VOLUME_H
#define EQEMU_MAP_VIEW_MODULE_VOLUME_H

#include "module.h"
#include "scene.h"
#include "dynamic_geometry.h"
#include <oriented_bounding_box.h>
#include <vector>
#include <memory>

struct Region
{
	uint32_t area_type;
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
	glm::vec3 extents;
	OrientedBoundingBox obb;
};

class ModuleVolume : public Module, public SceneHotkeyListener
{
public:
	ModuleVolume();
	virtual ~ModuleVolume();

	virtual const char *GetName() { return "Volume"; };
	virtual void OnLoad(Scene *s);
	virtual void OnShutdown();
	virtual void OnDrawMenu();
	virtual void OnDrawUI();
	virtual void OnDrawOptions();
	virtual void OnSceneLoad(const char *zone_name);
	virtual void OnSuspend();
	virtual void OnResume();
	virtual bool HasWork();
	virtual bool CanSave();
	virtual void Save();
	virtual void OnHotkey(int ident);
	virtual void OnClick(int mouse_button, const glm::vec3 *collide_hit, const glm::vec3 *select_hit, Entity *selected);
	virtual void Tick(float delta_time);
private:
	bool LoadVolumes(const std::string &dir);
	void BuildVolumeEntities();

	Scene *m_scene;
	std::vector<std::unique_ptr<DynamicGeometry>> m_volumes;
	std::vector<Region> m_regions;
	int m_selected;
	bool m_modified;
	int m_work_pending;
	bool m_render_volume;

	void BuildFromWatermap(const glm::vec3 &pos);
};

#endif
