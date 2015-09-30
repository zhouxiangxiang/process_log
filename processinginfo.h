#ifndef PROCESSINGINFO_H
#define PROCESSINGINFO_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include <QLabel>
#include <QFileInfo>
#include <QPlainTextEdit>

#include "./logprocess.h"
#include "./countnumber.h"
#include "./directoryoperation.h"

class ProcessingInfo {
public:
    ProcessingInfo(std::string ifilename, std::string ofilename,
                   std::string roomInfo, unsigned interval) {

        // fixme: lab's displaying tijme.
        if (ifilename.empty()) {
            /*
            m_inputFilename = "D:\\Qt\\project\\widget_test\\log\\zt.txt";
            QLabel lab("INPUT FILENAME cannot be empty");
            lab.show();
            */
            assert(0 && "INPUT FILENAME is empty");
        }
        else {
            m_inputFilename = ifilename;
        }

        if (ofilename.empty()) {
            /*
            m_outputFileName = m_inputFilename + "_result" + ".txt";
            std::string str =  std::string("OUTPUT FILENAME is empty \n") +
                               std::string("the DEFAULT filename is : ") +
                               m_outputFileName;
            QLabel lab(str.c_str());
            //lab.setText(QString(str));
            lab.show();
            */
            assert(0 && "OUTPUT FILENAME is empty");
        }
        else {
            m_outputFileName = ofilename;
        }

        if (roomInfo.empty()) {
            /*
            m_roomInfo = "roomid:46807";
            QLabel lab("ROOMID cannot be empty");
            lab.show();
            */
            assert(0 && "ROOMID is empty");
        }
        else {
            m_roomInfo = roomInfo;
        }

        if (interval > 0)
            m_interval = interval;
        else {
            /*
            interval = 1;

            QLabel lab("time INTERVAL must be greater than 0");
            lab.show();
            */
            assert(0 && "interval is empty");
        }
    }

    bool startProcess(QPlainTextEdit  *mp_pttConsole) {
        QFileInfo fileInfo(m_inputFilename.c_str());
        if (fileInfo.isDir()) {
            DirectoryOPeration curDir(m_inputFilename.c_str());
            curDir.iteratorDirectory();

            QDir dirOp(m_inputFilename.c_str());

            //DirectoryOPeration dirOperation(m_inputFilename.c_str());
            std::string ofilename;
             QFileInfoList list = dirOp.entryInfoList();
             for (int i = 0; i < list.size(); ++i) {
                QFileInfo fi = list.at(i);
                //fi.makeAbsolute();
                //fi.filePath();
                if (!fi.isDir()) {
                    std::string str =  "[ " +  std::to_string(i) + " ]" + qPrintable(QString("%1").arg(fi.fileName()));
                    mp_pttConsole->appendPlainText(str.c_str());
                    LogProcess lp(fi.absoluteFilePath().toStdString(), m_outputFileName, m_roomInfo);
                    lp.startProcess();
                    std::chrono::duration<int, deci> ztm(1);
                    std::this_thread::sleep_for(ztm);
                    ofilename = lp.getOFilename();
                }
                else { // directory.
                    continue;
                }
             }

             CountNumber cn(ofilename);
             cn.startProcess();
        }
        else {
            LogProcess lp(m_inputFilename, m_outputFileName, m_roomInfo);
            lp.startProcess();

            CountNumber cn(lp.getOFilename());
            cn.startProcess();
        }


        /*
        LogProcess lp(m_inputFilename, m_outputFileName, m_roomInfo);
        lp.startProcess();

        CountNumber cn(lp.getOFilename());
        cn.startProcess();
        */
        return true;
    }

private:
    std::string     m_inputFilename; // absolute path and file name
    std::string     m_outputFileName;
    std::string     m_roomInfo;
    unsigned        m_interval;
};



#endif // PROCESSINGINFO_H

