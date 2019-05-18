//
// Created by Jakub Kiermasz on 2019-05-19.
//

#include "../../include/Tools/StringConverter.hpp"

std::wstring StringConverter::StringToWstring(const std::string &s) const {
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}

std::string StringConverter::WstringToString(const std::wstring &s) const {
    std::string temp(s.length(), ' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}