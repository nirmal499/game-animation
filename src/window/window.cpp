#include <window/window.hpp>

namespace game
{
    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
    
    bool Window::initialize(unsigned int w, unsigned int h, std::string window_title)
    {
        if(!glfwInit())
        {
            Logger::log(1, "%s: glfwInit() error\n",__FUNCTION__);
            return false;
        }

        // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        _window = glfwCreateWindow(w, h, window_title.c_str(), nullptr, nullptr);
        if(!_window)
        {
            Logger::log(1, "%s: Not able to create Window\n", __FUNCTION__);
            glfwTerminate();

            return false;
        }

        /* Adding support for OpenGL to the window */
        glfwMakeContextCurrent(_window);

        /* Inorder to access OpenGL API from the driver we use the interface provided by the GLAD */
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return EXIT_FAILURE;
        }

        glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

        Logger::log(1, "%s: Window is successfully initialized\n", __FUNCTION__);
        return true;
    }

    void Window::main_loop()
    {
        while(!glfwWindowShouldClose(_window))
        {

            glClearColor(0.5, 0.5, 0.5, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
    }

    void Window::clean_up()
    {
        Logger::log(1, "%s: Destroying Window\n", __FUNCTION__);
        glfwDestroyWindow(_window);
        glfwTerminate();
    }
}