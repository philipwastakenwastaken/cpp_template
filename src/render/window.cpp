#include "render/window.hpp"
#include "GLFW/glfw3.h"
#include "core/core.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include "render/opengl/vertex_array.hpp"
#include "render/opengl/vertex_buffer.hpp"
#include "render/opengl/gl_shader.hpp"

#include "util/rng.hpp"

namespace momo {

Window::Window()
{
    auto glfw_result = glfwInit();
    MOMO_ASSERT(glfw_result, "Could not initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef MOMO_PLATFORM_MACOSX
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


    window = glfwCreateWindow(window_width, window_height, "Momo: Chip-8 emulator", nullptr, nullptr);

    MOMO_ASSERT(window, "Could not initialize GLFW window");

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    auto gl_version = gladLoadGL(glfwGetProcAddress);
    MOMO_ASSERT(gl_version, "Could not initalize glad");
    MOMO_TRACE("Loaded OpenGL version {0}, {1}", GLAD_VERSION_MAJOR(gl_version), GLAD_VERSION_MINOR(gl_version));


    int h = 0;
    int w = 0;
    glfwGetFramebufferSize(window, &w, &h);
    MOMO_TRACE("w: {0} h {1}", w, h);
    glViewport(0, 0, w, h);

    // (0, 0) at top left
    proj = glm::ortho(0.0f, static_cast<float>(window_width), static_cast<float>(window_height), 0.0f, -1.0f, 1.0f);
}

Window::~Window() { glfwTerminate(); }

} // namespace momo