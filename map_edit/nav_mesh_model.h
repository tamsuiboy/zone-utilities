#ifndef EQEMU_MAP_EDIT_NAV_MESH_MODEL_H
#define EQEMU_MAP_EDIT_NAV_MESH_MODEL_H

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "entity.h"
#include "dynamic_geometry.h"

class NavMeshModel : public Entity
{
public:
	NavMeshModel();
	virtual ~NavMeshModel();

	virtual void Draw();
	void Update();

	const glm::vec4& GetPointsTint() { return m_points.GetTint(); }
	void SetPointsTint(const glm::vec4 &tint) { m_points.SetTint(tint); }
	std::vector<glm::vec3>& GetPointsVerts() { return m_points.GetVerts(); }
	std::vector<unsigned int>& GetPointsInds() { return m_points.GetInds(); }

	const glm::vec4& GetLinesTint() { return m_lines.GetTint(); }
	void SetLinesTint(const glm::vec4 &tint) { m_lines.SetTint(tint); }
	std::vector<glm::vec3>& GetLinesVerts() { return m_lines.GetVerts(); }
	std::vector<unsigned int>& GetLinesInds() { return m_lines.GetInds(); }

	const glm::vec4& GetTrianglesTint() { return m_triangles.GetTint(); }
	void SetTrianglesTint(const glm::vec4 &tint) { m_triangles.SetTint(tint); }
	std::vector<glm::vec3>& GetTrianglesVerts() { return m_triangles.GetVerts(); }
	std::vector<unsigned int>& GetTrianglesInds() { return m_triangles.GetInds(); }

private:
	DynamicGeometry m_points;
	DynamicGeometry m_lines;
	DynamicGeometry m_triangles;
};

#endif
