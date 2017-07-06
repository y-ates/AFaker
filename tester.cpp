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

#include "0_view/gui.h"
#include "0_model/grabber.h"
#include "0_model/filler.h"
#include "tester.h"
#include <iostream>

testFaker::testFaker(int c, char** v) {
    std::cout << "[#]: Testing AFaker..." << std::endl;
    
    argc = c;
    argv = v;
}

void testFaker::test() {
    std::cout << "[##]: Testing grabber functions..." << std::endl;
    testGrabber();

    std::cout << std::endl << "[#] Note: Done." << std::endl << std::endl;
    
    std::cout << "[##]: Testing GUI functions..." << std::endl;
    testGUI();

    std::cout << std::endl << "[#] Note: Done." << std::endl << std::endl;
    
    std::cout << "[##]: Testing filler functions..." << std::endl;
    testFiller();

    std::cout << std::endl << "[#] Note: Done." << std::endl << std::endl;

    std::cout << "[##]: Testing postSend() function..." << std::endl;
    testSendPost();
}

void testFaker::testFiller() {
    Filler filler;
    std::string first_name = filler.getFirstName();
    std::string last_name = filler.getSecondName();

    std::cout << "[###]: Random first name: " << first_name
              << std::endl;
    std::cout << "[###]: Random second name: " << last_name
              << std::endl;
    std::cout << "[###]: Resulting name: " << first_name << " " << last_name
              << std::endl;

}

void testFaker::testGrabber() {
    std::cout << "[###]: Running grabber constructor with parameter"
              << " (www.google.de)" << std::endl;
    Grabber grabber1("www.google.de");
    grabber1.setContent();
    //std::cout << grabber1.getContent() << std::endl;

    std::cout << "[###]: Running grabber constructor without parameter"
              << std::endl;
    Grabber grabber2;
    grabber2.setContent();
    //std::cout << grabber2.getContent() << std::endl;
}

void testFaker::testGUI() {
	/* Init main window */
    std::cout << "[###]: Running GUI..." << std::endl;
	GUI gui;
	gui.start(argc, argv);    
}

void testFaker::testSendPost() {
    Filler filler;
    filler.sendPOST("https://www.trash-mail.com/inbox/", "form-postbox=test");
    //filler.sendPOST("http://localhost:8000/getpost.php", "name=test");
}
