//
// Created by 97862 on 2023/2/17.
//
#include <fstream>
#include <iostream>
#include "Logger.h"
#include "TimeUtil.h"
#include <sstream>
#include <sys/stat.h>

#if defined (_WIN64) || defined (WIN32) || defined (_WIN32)

#include <direct.h>
#include <mutex>

#else

#include <unistd.h>

#endif

std::mutex logLock;
Logger logger;

std::string LevelName[3] = {
        "DEBUG", "INFO", "ERROR"
};

// 通过stat结构体 获得文件大小，单位字节
long getFileSize(const char *fileName) {
    if (fileName == nullptr) {
        return 0;
    }
    // 这是一个存储文件(夹)信息的结构体，其中有文件大小和创建时间、访问时间、修改时间等
    struct stat statbuf{};
    // 提供文件名字符串，获得文件属性结构体
    stat(fileName, &statbuf);
    // 获取文件大小
    long filesize = statbuf.st_size;
    return filesize;
}

void Logger::write(const std::string &str) {
    std::lock_guard<std::mutex> lk(logLock);
    std::ofstream fout;
    fout.open(logFile, std::ios::app);
    fout << str << std::endl;
    fout.close();
}

Logger::Logger() {
    // 区分此函数是在Windows环境调用还是Linux环境调用
#if defined (_WIN64) || defined (WIN32) || defined (_WIN32)
    logFile = _getcwd(nullptr, 0);

    mkdir((logFile + "/log").c_str());
#else
    logFile = getcwd(nullptr, 0);
    std::string command = "mkdir -p " + logFile+"/log";
    system(command.c_str());
#endif
    logFile += R"(/log/log.log)";
    std::cout << logFile << std::endl;
}

void Logger::log(Logger::Level lv, const std::string &file, int line, const std::string &content) {
    if (this->level > lv) {
        return;
    }
    std::stringstream ss;
    const std::string &dateTime = getCurrentDateTime();
    ss << '[' << dateTime << "][" << file << ':' << line << "][" << LevelName[lv] << "] - " << content;
    try {
        std::string str = ss.str();
        std::cout << str << std::endl;
        write(str);
        long size = getFileSize(logFile.c_str());
        if (size >= maxFileSize) {
            std::lock_guard<std::mutex> lk(logLock);
            size = getFileSize(logFile.c_str());
            if (size >= maxFileSize) {
                remove((logFile + ".bak").c_str());
                rename(logFile.c_str(), (logFile + ".bak").c_str());
            }
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}




