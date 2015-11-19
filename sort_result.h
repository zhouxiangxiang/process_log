#ifndef SORT_RESULT_H
#define SORT_RESULT_H
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>

class Sort_Result {
public:
    Sort_Result(const std::string& ifn, const std::string& ofn = "");
    ~Sort_Result();

    void startSort();
private:
    inline const std::string getHour(std::string& tm) const;
    inline const std::string getMin( std::string& tm) const;
    inline const std::string getSec( std::string& tm) const;

private:
    std::string m_ifn;
    std::string m_ofn;
    std::ifstream m_ifs;
    std::ofstream m_ofs;
};


#endif // SORT_RESULT_H

