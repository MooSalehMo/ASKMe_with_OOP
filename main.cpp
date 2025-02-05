//
//  main.cpp
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 26/01/25.
//

#include <iostream>
#include <string>
using namespace std ;

#include "signinSignup.h"
#include "menue.h"
#include "edite.h"

int main(int argc, const char * argv[]) {
    
    // Start Define objects from classes
    MenueAsk::MenueCls menueObjectInMain;
    SigninSignupAsk::signinSignupCls signObjectInMain;
    EditeAsk::EditeCls editeObjectInMain;
    // End Define objects from classes
    
    // Start gen fun signin signup
    menueObjectInMain.signinSignupFun();
    int choose = 0;
    cin >> choose;
    signObjectInMain.chooseFun(choose);
    // End gen fun signin signup
    
    // Start gen fun edite delete
    menueObjectInMain.editeDeleteFun();
    cin >> choose;
    editeObjectInMain.chooseFun(choose);
    // End gen fun edite delete
    

    return 0;
}
