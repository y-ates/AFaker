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

#include "parser.h"

Parser::Parser() {
    xmlInitParser();
}

Parser::~Parser() {
    xmlCleanupParser();
}

int Parser::executeXPath(const char* filename,
                         const xmlChar* xpath_expression) {
    xmlDocPtr document;
    xmlXPathContextPtr xpath_context;
    xmlXPathObjectPtr xpath_object;

    document = xmlParseFile(filename);
    if (document == NULL) {
        std::cout << "[-] Error: xmlParseFile() did not work." << std::endl;
        return -1;
    }

    xpath_context = xmlXPathNewContext(document);
    if (xpath_context == NULL) {
        std::cout << "[-] Error: xmlXpathNewContext() did not work."
                  << std::endl;
        xmlFreeDoc(document);
        return -1;
    }

    xpath_object = xmlXPathEvalExpression(xpath_expression, xpath_context);
    if (xpath_object == NULL) {
        std::cout << "[-] Error: xmlXPathEvalExpression() did not work."
                  << std::endl;
        xmlFreeDoc(document);
        xmlXPathFreeContext(xpath_context);
        return -1;
    }

    print_nodes(xpath_object->nodesetval);

    xmlFreeDoc(document);
    xmlXPathFreeContext(xpath_context);
    xmlXPathFreeObject(xpath_object);
    return 0;
}

void Parser::print_nodes(xmlNodeSetPtr nodes) {
    xmlNodePtr cur;
    int size;

    size = (nodes) ? nodes->nodeNr : 0;
    for (int i=0; i < size; ++i) {
        if (nodes->nodeTab[i]->type == XML_NAMESPACE_DECL) {
            xmlNsPtr ns;
            ns = (xmlNsPtr)nodes->nodeTab[i];
            cur = (xmlNodePtr)ns->next;

            if (cur->ns) {
                std::cout << "namespace " << ns->prefix << "=" << ns->href
                          << "for node " << cur->ns->href << ":" << cur->name
                          << std::endl;
            } else {
                std::cout << "namespace " << ns->prefix << "=" << ns->href
                          << "for node " << cur->name
                          << std::endl;
            }
        } else if (nodes->nodeTab[i]->type == XML_ELEMENT_NODE) {
            cur = nodes->nodeTab[i];

            if (cur->ns) {
                std::cout << "element node " << cur->ns->href << ":"
                          << cur->name
                          << std::endl;
            } else {
                std::cout << "element node " << cur->name
                          << std::endl;
            }
        } else {
            cur = nodes->nodeTab[i];
            std::cout << "node " << cur->name << ": type " << cur->type
                      << std::endl;
        }
    }
}
