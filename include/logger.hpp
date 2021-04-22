#include <string>
#ifndef LOGPATH
#define LOGPATH "/logs/"
#endif

class Logger {
    private:
        std::string pluginName;
    public:
        static void log(std::string messageType, std::string msg);
        Logger(std::string plugin);
        void info(std::string s);
        void error(std::string s);
        void warn(std::string s);
        void debug(std::string s);

};