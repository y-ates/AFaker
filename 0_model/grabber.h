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

#include <curl/curl.h>

class Grabber {
 private:
    struct memoryStruct {
        char *memory;
        size_t size;
    };
    const char *url;
    memoryStruct data;

 public:
    Grabber(void);
    Grabber(const char *url_string);
    ~Grabber(void);

    const static void* myrealloc(void *ptr, size_t size);
    static size_t writeCallback(void *ptr, size_t size,
                                size_t nmemb, void *data);
    void setContent(void);
    char* getContent(void);
};

#endif  // _GRABBER_H
