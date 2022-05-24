#pragma once

#include "icanvas.h"
#include "qmath.h"

class Sunbeam
{
    
};

class SunbeamerApi
{
public
    SunbeamerApi() {}
public:
    void setViewport(float w, float h);
    void setViewport(Vector2f dimensions);
    void frame(ICanvas* canvas);
private:
    Vector2f viewportDimensions;
};