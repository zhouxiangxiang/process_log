#include <cassert>
#include <ctime>
#include <algorithm>

#include "./countnumber.h"

CountNumber::CountNumber(std::string ifilename, std::string ofilename, unsigned interval) {
    if (ifilename.empty())
        assert(0 && "file name cannot be empty");
    if (ofilename.empty())
        ofilename = ifilename + "_result.txt";
    m_ifilename = ifilename;
    m_ofilename = ofilename;
    m_interval = interval;
}

bool CountNumber::startProcess(){
    if (!m_ifstream.is_open()) {
        m_ifstream.open(m_ifilename);
        if (!m_ifstream.is_open()) {
            assert(0 && "open file failed.");
        }
    }

    if (!m_ofstream.is_open()) {
        m_ofstream.open(m_ofilename);
        if (!m_ofstream.is_open()) {
            assert(0 && "open file failed.");
        }
    }

    if (!m_ifstream.eof()) {
        std::string curline;
        std::string nextline;

        std::getline(m_ifstream, curline);
        unsigned count = 1;
        while(!m_ifstream.eof()) {
            std::getline(m_ifstream, nextline);
                // curline.find_last_of(':')
                // nextline.find_last_of(':')

                if (!curline.compare(0, curline.find_last_of(':'), nextline.substr(0, nextline.find_last_of(':')))) {
                    ++count;
                }
                else {
                    curline.erase(std::remove(curline.begin(), curline.end(), '\n'), curline.end());
                    if (!curline.empty())
                        m_ofstream << curline.substr(0, curline.find_last_of(':')) + " \t > " + std::to_string(count) << std::endl;
                    curline = nextline;
                    count = 1;
                }
        }
        curline.erase(std::remove(curline.begin(), curline.end(), '\n'), curline.end());
        if (!curline.empty())
            m_ofstream << curline.substr(0, curline.find_last_of(':')) + " \t : " + std::to_string(count) << std::endl;
    }
    return true;
}

unsigned CountNumber::countNumberByInterval(std::string begin, std::string end, int interval) {
    return 0;
}

CountNumber::~CountNumber() {
    if (m_ifstream.is_open())
        m_ifstream.close();
    if (m_ofstream.is_open()) {
        m_ofstream.close();
    }
}
