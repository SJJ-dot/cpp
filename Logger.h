//
// Created by 97862 on 2023/2/17.
//

#ifndef DEMO_LOGGER_H
#define DEMO_LOGGER_H


#include <string>


class Logger {
public:
    enum Level {
        DEBUG, INFO, ERROR
    };

private:
    std::string logFile;
    Level level = DEBUG;
    long maxFileSize = 1 * 1024 * 1024;

    void write(const std::string &str);

public:
    Logger();

    void log(Level lv, const std::string& file, int line, const std::string& content);
};

static Logger logger;

#define __FILENAME__ (strrchr(__FILE__, '/') + 1)

#define debug(content) logger.log(Logger::DEBUG,__FILE__,__LINE__, content)
#define info(content) logger.log(Logger::INFO,__FILE__,__LINE__, content)
#define error(content) logger.log(Logger::ERROR,__FILE__,__LINE__, content)
#endif //DEMO_LOGGER_H
