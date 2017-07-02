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

#include "filler.h"

Filler::Filler(void) {
    srand(time(NULL));
    seed = time(NULL);
}

std::string Filler::getFirstName(void) {
    unsigned int firstName_count = getLineCount(first_name_listpath);
    int name_position = rand_r(&seed) % firstName_count - 1;

    return getStringAtLine(name_position, first_name_listpath);
}

std::string Filler::getSecondName(void) {
    unsigned int secondName_count = getLineCount(second_name_listpath);
    int name_position = rand_r(&seed) % secondName_count - 1;

    return getStringAtLine(name_position, second_name_listpath);
}

std::string Filler::getEmailAdress(void) {
    return "[-] Error: getEmailAdress";
}

std::string Filler::getStringAtLine(const unsigned int line,
                                    const char *filename) {
    std::deque<std::string> all_strings;
    std::ifstream filestream(filename);

    if (filestream.is_open()) {
        copy(std::istream_iterator<std::string>(filestream),
             std::istream_iterator<std::string>(),
             std::back_inserter<std::deque<std::string>>(all_strings));
        filestream.close();
    } else {
        std::cout << "[-] Error: Could not open file (getStringAtLine)."
                  << std::endl;
        return "[-] Error: getStringAtLine";
    }

    return all_strings[line];
}

unsigned int Filler::getLineCount(const char *filename) {
    std::ifstream filestream(filename);
    filestream.unsetf(std::ios_base::skipws);

    unsigned line_count = std::count(std::istream_iterator<char>(filestream),
                      std::istream_iterator<char>(),
                      '\n');
    return line_count;
}
