#pragma once
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "core/hardware.hpp"
#include "core/log.hpp"
#include "core/core.hpp"

namespace momo {

class Window
{
    public:
        Window();
        ~Window();

        void swap_buffers() { glfwSwapBuffers(window); }
        void poll_events() { glfwPollEvents(); }
        [[nodiscard]] bool should_close() const { return glfwWindowShouldClose(window); }

        [[nodiscard]] GLFWwindow* get_window() { return window; }
    private:
        GLFWwindow* window = nullptr;
        glm::mat4 proj;

        i32 window_width = 500;
        i32 window_height = 500;

};

}