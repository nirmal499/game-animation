#include <memory>
#include <common/common_header.hpp>

int main()
{
    std::unique_ptr<game::Window> w = std::make_unique<game::Window>();

    if(!w->initialize(640, 480, "OpenGL Window"))
    {
        game::Logger::log(1, "%s error: Window initialization error\n", __FUNCTION__);
        return -1;
    }

    w->main_loop();
    w->clean_up();

    
    return 0;
}