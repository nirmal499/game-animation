#pragma once

#include <cstdio>

namespace game
{
    class Logger
    {
        public:
            /* LOG if the given log_level is equal or smaller to member propert _log_level */
            template<typename... Args>
            static void log(unsigned int log_level, Args... args)
            {
                if(log_level < _log_level)
                {
                    std::printf(args...);
                    std::fflush(stdout);
                }
            }

            static void set_log_level(unsigned int log_level)
            {
                _log_level = log_level <= 9 ? log_level : 9; 
            }

        private:
            static unsigned int _log_level;
    };
}