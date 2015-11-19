#include "./logprocess.h"

LogProcess::LogProcess(std::string ifilename, std::string ofilename,  std::string rePattern) {
    if (ifilename.empty())
        assert(0 && "input file name cannot be empty");
    if (ofilename.empty())
        assert(0 && "output file name cannot be empty");
    if (rePattern.empty())
        assert(0 && "re pattern cannot be empty");

    m_ifilename = ifilename;
    m_ofilename = ofilename;
    m_rePattern = rePattern;
}

 bool LogProcess::startProcess() {
    if (!m_ifstream.is_open()) {
         m_ifstream.open(m_ifilename);
         if (!m_ifstream.is_open())
             assert(0 && "open input file failed.");
    }

    if (!m_ofstream.is_open()) {
        m_ofstream.open(m_ofilename, std::ofstream::app | std::ofstream::out);
        if (!m_ofstream.is_open())
            assert(0 && "open output file failed.");
    }

    std::regex expr("([0-9]+):([0-9]+):([0-9])+:([0-9]+)");
    std::string curline;
    std::smatch smr;
    while (!m_ifstream.eof()) {
        std::getline(m_ifstream, curline);
        if (std::string::npos != curline.find(m_rePattern)) {
            if (std::regex_search(curline, smr, expr)) {
                m_ofstream << smr[0]  << std::endl;
            }
        }
    }

    return true;
 }

LogProcess::~LogProcess(){
    if (m_ofstream.is_open())
        m_ofstream.close();
    if (m_ifstream.is_open())
        m_ifstream.close();
}
