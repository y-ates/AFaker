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

#include "grabber.h"
#include <stdlib.h>  // malloc, realloc
#include <cstring>   // memcpy 

Grabber::Grabber(void) {
    url = "http://www.google.com";  // test url
}

Grabber::Grabber(const char* url_string) {
    url = url_string;
}

const void* Grabber::myrealloc(void *ptr, size_t size) {
    if (ptr) {
        return realloc(ptr, size);
    } else {
        return malloc(size);
    }
}

size_t Grabber::writeCallback(void *ptr, size_t size,
                              size_t nmemb, void *data) {
   size_t realsize = size * nmemb;
   struct memoryStruct *mem = (struct memoryStruct *)data;
   mem->memory = (char *)myrealloc(mem->memory, mem->size + realsize + 1);

   if (mem->memory) {
      memcpy(&(mem->memory[mem->size]), ptr, realsize);
      mem->size += realsize;
      mem->memory[mem->size] = 0;
   }

   return realsize;
}

void Grabber::setContent(void) {
    CURL* curl;
    struct memoryStruct website_content;
    website_content.memory = NULL;
    website_content.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Grabber::writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&website_content);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

    curl_easy_perform(curl);

    //std::cout << std::endl << website_content.memory << std::endl;
    data = website_content;

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

char* Grabber::getContent(void) {
    return data.memory;
}
