#include <simulation/window.hpp>

int main() {
    Window window(1600, 800, "Spring simulation");

    window.RunMessageLoop();

    return 0;
}
