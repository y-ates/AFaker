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

#ifndef _GRABBER_H
#define _GRABBER_H

#include <string>
#include <cstring>
#include <curl/curl.h>

class Grabber {
 private:
    const char* url;
    std::string data;
    
 public:
    Grabber();
    Grabber(char* url_string);

    static size_t writeCallback(void *ptr, size_t size, size_t nmemb, void *data);
    static void* myrealloc(void *ptr, size_t size);
    void getContent();
};

#endif
