#ifndef COUNTNUMBER
#define COUNTNUMBER

#include <string>
#include <fstream>
#include <cassert>

class CountNumber {
public:
    CountNumber(std::string filename, std::string ofilename = "", unsigned interval = 1);
    ~CountNumber();

    bool startProcess();
    unsigned countNumberByInterval(std::string begin, std::string end, int interval = 1);

    const std::string getOfilename() const {
        return m_ofilename;
    }

private:
    std::string     m_ifilename;
    std::string     m_ofilename;
    std::ifstream   m_ifstream;
    std::ofstream   m_ofstream;
    unsigned        m_interval;
};

#endif // COUNTNUMBER
