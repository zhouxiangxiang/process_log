#include <cassert>

#include "./directoryoperation.h"

DirectoryOPeration::DirectoryOPeration(std::string dir) {
    m_logDir = QDir(dir.c_str());
    if (!m_logDir.exists())
        assert(0 && "file doest not exist.");
}

bool DirectoryOPeration::iteratorDirectory() {
     QFileInfoList list = m_logDir.entryInfoList();
     for (int i = 0; i < list.size(); ++i) {
         QFileInfo fileInfo = list.at(i);
        std::cout << qPrintable(QString("%1").arg(fileInfo.fileName()));
         std::cout << std::endl;
     }
    return true;
}
