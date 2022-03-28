#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "core/log.hpp"
#include "core/core.hpp"

#include "util/timer.hpp"
#include "render/window.hpp"


using namespace momo;

int main(int /*argc*/, char** /*argv*/)
{
    Log::init();
    MOMO_CORE_ERROR("Hello, World!");

    return 0;
}