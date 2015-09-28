#ifndef LOGPROCESS
#define LOGPROCESS

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <regex>

class LogProcess {
public:
    LogProcess(std::string ifilename, std::string ofilename, std::string rePattern);

    bool startProcess();

    ~LogProcess();

private:

    std::string   m_ifilename;
    std::string   m_ofilename;
    std::ifstream m_ifstream;
    std::ofstream m_ofstream;

    std::regex    m_rePattern;
};

#endif // LOGPROCESS

