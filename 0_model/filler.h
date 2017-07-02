/******************************************************************************
 ** Copyright (C) 2017 Yakup Ates <Yakup.Ates@rub.de>

 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** any later version.

 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.

 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef _FILLER_H
#define _FILLER_H

#include <stdlib.h>   // srand, rand
#include <time.h>     // time
#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#include <fstream>
#include <istream>
#include <iterator>
#include <algorithm>  // std::count

class Filler {
 private:
    const char *first_name_listpath = "0_model/wordfiles/first_name.txt";
    const char *second_name_listpath = "0_model/wordfiles/last_name.txt";
    unsigned int seed;

 public:
    Filler(void);
    std::string getFirstName(void);
    std::string getSecondName(void);
    std::string getEmailAdress(void);
    std::string getStringAtLine(const unsigned int line, const char *filename);
    unsigned int getLineCount(const char *filename);
};

#endif  // _FILLER_H
