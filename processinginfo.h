#ifndef PROCESSINGINFO_H
#define PROCESSINGINFO_H

#include <string>
#include <iostream>
#include <QLabel>

#include "./logprocess.h"

class ProcessingInfo {
public:
    ProcessingInfo(std::string ifilename, std::string ofilename,
                   std::string roomInfo, unsigned interval) {

        // fixme: lab's displaying tijme.
        if (ifilename.empty()) {
            m_inputFilename = "D:\\Qt\\project\\widget_test\\log\\zt.txt";
            QLabel lab("INPUT FILENAME cannot be empty");
            lab.show();
        }
        else {
            m_inputFilename = ifilename;
        }
        if (ofilename.empty()) {
            m_outputFileName = m_inputFilename + "_result" + ".txt";
            std::string str =  std::string("OUTPUT FILENAME is empty \n") +
                               std::string("the DEFAULT filename is : ") +
                               m_outputFileName;
            QLabel lab(str.c_str());
            //lab.setText(QString(str));
            lab.show();
        }
        else {
            m_outputFileName = ofilename;
        }

        if (roomInfo.empty()) {
            m_roomInfo = "46807";
            QLabel lab("ROOMID cannot be empty");
            lab.show();
        }
        else {
            m_roomInfo = roomInfo;
        }

        if (interval > 0)
            m_interval = interval;
        else {
            interval = 1;
            QLabel lab("time INTERVAL must be greater than 0");
            lab.show();
        }
    }

    bool startProcess() {
        LogProcess lp(m_inputFilename, m_outputFileName, m_roomInfo);
        lp.startProcess();
        return true;
    }

private:
    std::string     m_inputFilename; // absolute path and file name
    std::string     m_outputFileName;
    std::string     m_roomInfo;
    unsigned        m_interval;
};



#endif // PROCESSINGINFO_H

