#pragma once

#include "qmath.h"

class IBeamableObject
{
    virtual void Trace(Math::Vector3f o, Math::Vector3f f) = 0;
};