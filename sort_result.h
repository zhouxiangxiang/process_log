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
    std::string m_ifn;
    std::string m_ofn;
    std::ifstream m_ifs;
    std::ofstream m_ofs;
};


#endif // SORT_RESULT_H

