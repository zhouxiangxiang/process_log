#include "sort_result.h"
#include <vector>

Sort_Result::Sort_Result(const std::string& ifn, const std::string& ofn) {
    m_ifn = ifn;
    if (ofn.empty()) {
        m_ofn = m_ifn + "out.txt";
        std::cout << ":==============" << m_ifn << std::endl;
    }
}

Sort_Result::~Sort_Result(){
    if (m_ifs.is_open()) {
        m_ifs.close();
    }

}

void Sort_Result::startSort() {
    std::cout << __FILE__ << ": " << __LINE__ << ":" << __FUNCTION__ << std::endl;
    if (!m_ifs.is_open()) {
        m_ifs.open(m_ifn);
        if (!m_ifs.is_open()) {
            assert(0 && "open file failed.");
        }
    }

    std::string iCurLine;
    std::vector <std::string> content; // bad implementation.

    while (!m_ifs.eof()) {
        std::getline(m_ifs, iCurLine);
        content.push_back(iCurLine);
    }

    auto itend = content.end();
    for (auto it = content.begin(); it != itend; ++it) { // fixme: too slow.
        for (auto inIt = it + 1; inIt != itend; ++inIt) {
            // if (it->compare(0, 8, inIt->substr(0, 8)) > 0) {
            if (it->compare(*inIt)) {
                continue;
            }
            else {
                std::string swapStr = *inIt;
                *inIt = *it;
                *it = swapStr;
            }
        }
    }

    if (!m_ofs.is_open()) {
        m_ofs.open(m_ofn, std::ios_base::out);
       if (!m_ofs.is_open()) {
                assert(0 && "open file failed.");
        }
    }

    itend = content.end();
    for (auto it = content.begin(); it != itend; ++it) {
        m_ofs << *it << std::endl;
    }
}

