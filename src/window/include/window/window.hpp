#pragma once

#include <common/common_header.hpp>

namespace game
{
    class Window
    {   
        private:
            static void framebuffer_size_callback(GLFWwindow* _window, int width, int height);
        public:
            bool initialize(unsigned int w, unsigned int h, std::string window_title);
            void main_loop();
            void clean_up();

        private:
            GLFWwindow* _window = nullptr;
    };
}