//
//  menue.cpp
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 28/01/25.
//
#include <iostream>
#include "menue.h"
using namespace std;

namespace MenueAsk {
    MenueCls::MenueCls() {}
    void MenueCls::signinSignupFun(){
        cout << "1- To Signin enter 1.\n2- To Registring enter 2.\n3- To Logout enter 3.\nPlease enter your choice : ";
    }
    void MenueCls::editeDeleteFun(){
        cout << "1- To Edite Your info enter 1.\n2- To Delete Your info enter 2.\n3- To Move into App enter 3.\nPlease enter your choice : ";
    }
    MenueCls::~MenueCls() {}
}


