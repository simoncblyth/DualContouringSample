#pragma once

#include <glm/glm.hpp>
#include "qef.h"

#include "DCS_API_EXPORT.hh"

struct DCS_API OctreeDrawInfo 
{
    OctreeDrawInfo() : index(-1), corners(0) {}

    int          index;
    int          corners;
    glm::vec3    position;
    glm::vec3    averageNormal;
    svd::QefData qef;

};

