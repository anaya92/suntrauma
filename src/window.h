#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "icanvas.h"

class DrawableWindow : public ICanvas
{
public:
    DrawableWindow(int w, int h, std::string title);
    ~DrawableWindow();
public:
    void resize(int w, int h);
    int getWidth();
    int getHeight();
    void refresh();
    bool notClosed();
public:
    void clearCanvas(Rgb color) override;
    void setPixel(int x, int y, Rgb color) override;
    void resizeCanvas(int w, int h) override;
private:
    void rebuildCanvas(int w, int h);
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* streamingTexture = nullptr;
    unsigned int* pixels = nullptr; // window surface
};