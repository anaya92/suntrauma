#include "window.h"
#include "sunbeamer.h"

#include <cstdlib>

int main(int argc, char* argv[])
{
    DrawableWindow window(640, 480, "");
    window.resizeCanvas(320, 240);

    SunbeamerApi renderer;
    
    while (window.notClosed())
    {
        renderer.frame(&window);
        window.refresh();
    }
}