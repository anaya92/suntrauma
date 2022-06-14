#pragma once

#include "rgb.h"

class ICanvas
{
protected:
    int canvasWidth = 0, canvasHeight = 0;
public:
    virtual void clearCanvas(Rgb color) = 0;
    virtual void setPixel(int x, int y, Rgb color) = 0;
    virtual void resizeCanvas(int w, int h) = 0;

    virtual int getCanvasWidth() { return canvasWidth; }
    virtual int getCanvasHeight() { return canvasHeight; }
};