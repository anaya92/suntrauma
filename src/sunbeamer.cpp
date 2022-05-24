#include "sunbeamer.h"

void SunbeamerApi::setViewport(float w, float h)
{
    viewportDimensions = Vector2f(w, h);
}

void SunbeamerApi::setViewport(Vector2f dimensions)
{
    viewportDimensions = dimensions;
}

void SunbeamerApi::frame(ICanvas* canvas)
{
    
}