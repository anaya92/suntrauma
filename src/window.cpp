#include "window.h"

#include <cstdlib>
#include <cstdio>

DrawableWindow::DrawableWindow(int w, int h, std::string title)
{
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        w,
        h,
        SDL_WINDOW_HIDDEN
    );

    if (!window)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", "Window creation failed", window);
        std::exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    rebuildCanvas(w, h);

    SDL_ShowWindow(window);
}

DrawableWindow::~DrawableWindow()
{
    std::free(pixels);
    SDL_DestroyTexture(streamingTexture);
    SDL_DestroyWindow(window);
}

void DrawableWindow::resize(int w, int h)
{
    SDL_SetWindowSize(window, w, h);
}

int DrawableWindow::getWidth()
{
    int v;
    SDL_GetWindowSize(window, &v, nullptr);
    return v;
}

int DrawableWindow::getHeight()
{
    int v;
    SDL_GetWindowSize(window, nullptr, &v);
    return v;
}

void DrawableWindow::refresh()
{
    SDL_UpdateTexture(streamingTexture, NULL, pixels, canvasWidth * 4);
    SDL_RenderCopy(renderer, streamingTexture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool DrawableWindow::notClosed()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        switch (ev.type)
        {
            case SDL_QUIT:
                return false;
                break;
        }
    }

    return true;
}

void DrawableWindow::clearCanvas(Rgb color)
{
    for (int i = 0; i < canvasWidth; i++)
    {
        for (int j = 0; j < canvasWidth; j++)
        {
            setPixel(i, j, color);
        }
    }
}

void DrawableWindow::setPixel(int x, int y, Rgb color)
{
    pixels[x + y * canvasWidth] = color.toRgba8888();
}

void DrawableWindow::resizeCanvas(int w, int h)
{
    rebuildCanvas(w, h);
}

void DrawableWindow::rebuildCanvas(int w, int h)
{
    canvasWidth = w;
    canvasHeight = h;
    if (pixels != nullptr) std::free(pixels);
    pixels = (unsigned int*)std::malloc(w * h * 4);

    SDL_DestroyTexture(streamingTexture);
    streamingTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, w, h);

    SDL_RenderSetLogicalSize(renderer, w, h);

    if (!pixels)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", "Window surface creation failed", window);
        std::exit(-1);
    }
}