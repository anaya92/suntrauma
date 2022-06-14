#include "sunbeamer.h"

void SunbeamEngine::setViewport(float w, float h, float distance)
{
    viewportDimensions = Math::Vector2f(w, h);
    viewportDistance = distance;
}

void SunbeamEngine::setViewport(Math::Vector2f dimensions, float distance)
{
    viewportDimensions = dimensions;
    viewportDistance = distance;
}

void SunbeamEngine::frame(SunbeamScene* scene, ICanvas* canvas)
{
    
}