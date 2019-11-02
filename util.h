//
// Created by leticia on 10/12/18.
//

#ifndef CG_2018_2_OPENGL_UTIL_H
#define CG_2018_2_OPENGL_UTIL_H

#include <vector>
#include <sstream>
#include "debugTimer.h"

namespace Util
{
    std::vector<std::string> Split(const std::string &s, char delim)
    {
        std::vector<std::string> elems;

        const char* cstr = s.c_str();
        unsigned int strLength = s.length();
        unsigned int start = 0;
        unsigned int end = 0;

        while(end <= strLength)
        {
            while(end <= strLength)
            {
                if(cstr[end] == delim)
                    break;
                end++;
            }

            elems.push_back(s.substr(start, end - start));
            start = end + 1;
            end = start;
        }

        return elems;
    }
};

#endif //CG_2018_2_OPENGL_UTIL_H
