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


const std::string Sort_Result::getHour(std::string& tm) const {
    return tm.substr(0, tm.find_first_of(":"));
}
const std::string Sort_Result::getMin( std::string& tm) const{
    auto it = tm.find_first_of(":");
    auto endit = tm.rfind(":");
    return tm.substr(it + 1, endit - it - 1);
}
const std::string Sort_Result::getSec( std::string& tm) const{
    return tm.substr(tm.rfind(":") + 1, 2);
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
        auto ehour = getHour(*it); // external
        auto emin = getMin(*it);
        auto esec = getSec(*it);
        std::cout << "-----:" << *it << std::endl;
        std::cout << "***" << ehour << std::endl;
        std::cout << "\t:" << emin << std::endl;
        std::cout << "\t\t:" << esec << std::endl;

        for (auto inIt = it + 1; inIt != itend; ++inIt) {
            auto ihour = getHour(*inIt);
            auto imin = getMin(*inIt);
            auto isec = getSec(*inIt);

            if (ehour.compare(ehour) == 0) {
                if (emin.compare(imin) == 0) { // minutes
                    if (esec.compare(isec) == 0) {
                        std::cout << "error occured" << std::endl; // fixme: output a warning friendly.
                        break;
                    }
                    else if (esec.compare(isec) > 0) {
                        std::string swapStr = *inIt;
                        *inIt = *it;
                        *it = swapStr;
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else if (emin.compare(imin) > 0) { // minutes
                    std::string swapStr = *inIt;
                    *inIt = *it;
                    *it = swapStr;
                    break;
                }
                else {
                    continue;
                }
            }
            else if (ehour.compare(ihour) > 0) {
                std::string swapStr = *inIt;
                *inIt = *it;
                *it = swapStr;
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

