#pragma once

#include "ibeamableobject.h"

#include <vector>

class SunbeamScene
{
public:
    void addObject(IBeamableObject* object);
private:
    std::vector<IBeamableObject*> objects;
};