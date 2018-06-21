#pragma once

//#include "Matrix.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

/*

This file is part of N3LP (https://github.com/hassyGo/N3LP)

The MIT License (MIT)

Copyright (c) 2016 Kazuma Hashimoto

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

namespace Utils{

  inline bool isSpace(const char& c){
    return (c == ' ' || c == '\t');
  }

  inline void split(const std::string& str, std::vector<std::string>& res){
    bool tok = false;
    int beg = 0;

    res.clear();

    for (int i = 0, len = str.length(); i < len; ++i){
      if (!tok && !Utils::isSpace(str[i])){
	beg = i;
	tok = true;
      }

      if (tok && (i == len-1 || Utils::isSpace(str[i]))){
	tok = false;
	res.push_back(isSpace(str[i]) ? str.substr(beg, i-beg) : str.substr(beg, i-beg+1));
      }
    }
  }

  inline void split(const std::string& str, std::vector<std::string>& res, const char sep){
    bool tok = false;
    int beg = 0;

    res.clear();

    for (int i = 0, len = str.length(); i < len; ++i){
      if (!tok && str[i] != sep){
	beg = i;
	tok = true;
      }

      if (tok && (i == len-1 || str[i] == sep)){
	tok = false;
	res.push_back((str[i] == sep) ? str.substr(beg, i-beg) : str.substr(beg, i-beg+1));
      }
    }
  }

}
