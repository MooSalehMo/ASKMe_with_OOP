//
//  signinSignup.cpp
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 26/01/25.
//
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "signinSignup.h"
#include "check.h"

//Start define objects
Check_Ask::CheckCls checkSign;
//Start define objects

// start namespace SigninSignupAsk
namespace SigninSignupAsk {
    // start define SigninSignupCls
    signinSignupCls::signinSignupCls(): name(""), mail(""), pass(""), age(0), userId(""),mailPlusPass(""), fileName("") {}
    // start define SigninSignupCls

    // start fun signupFun
    int signinSignupCls::signupFun() {
            cout << "Please enter your Email : ";
            cin >> signinSignupCls::mail ;
            cout << "Please enter your pass : ";
            cin >> signinSignupCls::pass ;
            cout << "Please enter your Name : ";
            cin >> signinSignupCls::name ;
            cout << "Please enter your Id : ";
            cin >> signinSignupCls::userId ;
            cout << "Please enter your age : ";
            cin >> signinSignupCls::age ;
            
            string data[4] = {signinSignupCls::name, signinSignupCls::userId, signinSignupCls::mail, signinSignupCls::pass};
             
            signinSignupCls::fileName = "data.txt";
            fstream output(signinSignupCls::fileName, ios::out | ios::app);
            bool findMailTrueFalse = checkSign.mailTrueFalseFun(signinSignupCls::mail);

            if (findMailTrueFalse == true) { // Start if and else check there is an mail
                cout << "You've already an Email with us "<< signinSignupCls::mail << " !, You can signin " << endl;
                signinSignupCls::signinFun();
            } else {
                for(int i=0; i< (sizeof(data) / sizeof(data[0])); i++)
                    output << data[i] << endl;
                output << signinSignupCls::age << endl;
                cout <<"Welcome " << signinSignupCls::mail << " You've signup succes \n";
            } // End if and else check there is an mail
        
        output.close();
        signinSignupCls::mail = "";
        signinSignupCls::pass = "";
        signinSignupCls::name = "";
        signinSignupCls::userId = "";
        signinSignupCls::age = 0 ;
        return 0;
    } // End fun signupFun

    // start fun signinFun
    const int signinSignupCls::signinFun() {
            cout << "Please enter your Email : ";
            cin >> signinSignupCls::mail ;
            cout << "Please enter your pass : ";
            cin >> signinSignupCls::pass ;
            bool vMailTrueFalse = checkSign.mailTrueFalseFun(signinSignupCls::mail);
        
            if (vMailTrueFalse)
                cout << "Welcome " << signinSignupCls::mail << " You've signin succes \n";
            else {
                cout << "This Email isn't Exist any Email with us "<< signinSignupCls::mail<< " You don't have Email with us! , You can signup .\n";
                signinSignupCls::signupFun();
            }
        
        signinSignupCls::mail = "";
        signinSignupCls::pass = "";
        return 0;
    } // End fun signinFun

    // Start shoose fun
    const void signinSignupCls::chooseFun(int choose){
            switch (choose) { // start switch
                case 1:
                    signinSignupCls::signinFun();
                    break;
                case 2:
                    signinSignupCls::signupFun();
                    break;
                case 3:
                    exit(1);
                    break;
                default:
                    cout <<"Your choice incorrect !";
                    break;
            } // End switch
    }// End shoose fun

} // start namespace SigninSignupAsk
