#ifndef DIRECTORYOPERATION
#define DIRECTORYOPERATION

#include <iostream>
#include <string>
#include <QDir>
// #include <filesystem>

using namespace std;
class DirectoryOPeration {
public:
    DirectoryOPeration(std::string dir);
    bool iteratorDirectory();
private:
    QDir  m_logDir;
};

#endif // DIRECTORYOPERATION

