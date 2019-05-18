//
// Created by Jakub Kiermasz on 2019-05-19.
//

#ifndef HEXADOKU_STRINGCONVERTER_HPP
#define HEXADOKU_STRINGCONVERTER_HPP

#include <iostream>

class StringConverter {
public:
    std::wstring StringToWstring(const std::string& s) const;
    std::string WstringToString(const std::wstring& s) const;
};


#endif //HEXADOKU_STRINGCONVERTER_HPP
