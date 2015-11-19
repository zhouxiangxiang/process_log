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


const int Sort_Result::getHour(std::string& tm) const {
    return std::atoi(tm.substr(0, tm.find_first_of(":")).c_str());
}
const int Sort_Result::getMin( std::string& tm) const{
    auto it = tm.find_first_of(":");
    auto endit = tm.rfind(":");
    return std::atoi(tm.substr(it + 1, endit - it - 1).c_str());
}
const int Sort_Result::getSec( std::string& tm) const{
    return std::atoi(tm.substr(tm.rfind(":") + 1, 2).c_str());
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
        iCurLine.clear();
    }

    auto itend = content.end();
    for (auto it = content.begin(); it != itend; ++it) { // fixme: too slow.
        auto ehour = getHour(*it); // external
        auto emin = getMin(*it);
        auto esec = getSec(*it);
        std::cout << "-----:" << *it << std::endl;
        std::cout << "***" << ehour  << " - " << emin  << " - " << esec << std::endl;

        for (auto inIt = it + 1; inIt != itend; ++inIt) {
            auto ihour = getHour(*inIt);
            auto imin = getMin(*inIt);
            auto isec = getSec(*inIt);

            if (ehour == ihour) {
                if (emin == imin) { // minutes
                    if (esec == isec) {
                        std::cout << "error occured" << std::endl; // fixme: output a warning friendly.
                        break;
                    }
                    else if (esec > isec) {
                        std::swap(it, inIt);
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else if (emin > imin) { // minutes
                    std::swap(it, inIt);
                    break;
                }
                else {
                    continue;
                }
            }
            else if (ehour > ihour) {
                std::swap(it, inIt);
                break;
            }
            else {
                continue;
            }

            /*
            if (it->compare(*inIt)) {
                continue;
            }
            else {
                std::string swapStr = *inIt;
                *inIt = *it;
                *it = swapStr;
            }
            */
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

