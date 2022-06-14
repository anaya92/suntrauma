#include "window.h"
#include "sunbeamer.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    DrawableWindow window(640, 480, "");
    window.resizeCanvas(320, 240);

    SunbeamEngine renderer;
    
    while (window.notClosed())
    {
        window.clearCanvas(Rgb(0.5, 0.7, 0.3));
        renderer.frame(nullptr, &window);
        window.refresh();
    }
}