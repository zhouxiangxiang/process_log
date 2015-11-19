#include "sort_result.h"
#include <vector>
#include <functional>
#include <algorithm>

Sort_Result::Sort_Result(const std::string& ifn, const std::string& ofn) {
    m_ifn = ifn;
    if (ofn.empty()) {
        m_ofn = m_ifn + "out.txt";
    }
}

Sort_Result::~Sort_Result(){
    if (m_ifs.is_open()) {
        m_ifs.close();
    }
    if (m_ofs.is_open()) {
        m_ofs.close();
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

bool Sort_Result::compare(std::string& lhs, std::string& rhs) {
    if (getHour(lhs) < getHour(rhs)) {
        return true;
    }
    if (getHour(lhs) == getHour(rhs) && getMin(lhs) < getMin(rhs)) {
        return true;
    }
    if (getHour(lhs) == getHour(rhs) && getMin(lhs) == getMin(rhs) && getSec(lhs) < getSec(rhs)) {
        return true;
    }
    return false;
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


    auto cmp = std::bind(&Sort_Result::compare, this, std::placeholders::_2, std::placeholders::_1);
    std::sort(content.begin(), content.end(), cmp);

/*
    auto itend = content.end();
    for (auto it = content.begin(); it != itend - 1; ++it) { // fixme: too slow.
        auto ehour = getHour(*it); // external
        auto emin = getMin(*it);
        auto esec = getSec(*it);
        std::cout << "-----:" << *it << std::endl;
        std::cout << "***" << ehour  << " - " << emin  << " - " << esec << std::endl;
        for (auto inIt = content.begin(); inIt != it; ++inIt) {
            auto ihour = getHour(*inIt);
            auto imin = getMin(*inIt);
            auto isec = getSec(*inIt);

            if (ehour < ihour) {
                std::swap(*it, *inIt);
                continue;
            }
            if (ehour == ihour && emin < imin) {
                std::swap(*it, *inIt);
                continue;
            }
            if (ehour == ihour && emin == imin && esec < isec) {
                std::swap(*it, *inIt);
                continue;
            }
        }
    }
*/
    if (!m_ofs.is_open()) {
        m_ofs.open(m_ofn, std::ios_base::out);
       if (!m_ofs.is_open()) {
                assert(0 && "open file failed.");
        }
    }

    auto itend = content.end();
    for (auto it = content.begin(); it != itend; ++it) {
        m_ofs << *it << std::endl;
    }
}

