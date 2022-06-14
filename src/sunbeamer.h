#pragma once

#include "icanvas.h"
#include "qmath.h"
#include "sunbeamscene.h"

class Sunbeam
{
    
};

class SunbeamEngine
{
public:
    SunbeamEngine() {}
public: // state stuff
    void setViewport(float w, float h, float distance);
    void setViewport(Math::Vector2f dimensions, float distance);
public:
    void frame(SunbeamScene* scene, ICanvas* canvas);
protected: // state stuff
    Math::Vector2f viewportDimensions = Math::Vector2f(0.0f);
    float viewportDistance = 1.0f;
protected:
};