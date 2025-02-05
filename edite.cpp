//
//  edite.cpp
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 28/01/25.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "edite.h"
#include "check.h"
#include "signinSignup.h"

// Start define objects
Check_Ask::CheckCls checkObjectEdite;
SigninSignupAsk::signinSignupCls signObjectEdite;
// End define objects

namespace EditeAsk { // start Namespace EditeAsk

    EditeCls::EditeCls(){
            signObjectEdite.mail = "" ;
            signObjectEdite.pass = "" ;
            signObjectEdite.name = ""  ;
            signObjectEdite.userId = "";
            signObjectEdite.age = 0 ;
    } // This class friend to signin singup class

    // start fun editeInfo
    int EditeCls::editeInfoFun(const string& mail, const string& pass){
        
        string line = "", *address;
        address = new string;
        signObjectEdite.fileName = "data.txt";
        fstream output(signObjectEdite.fileName, ios::out);
        fstream inputFile(signObjectEdite.fileName, ios::in);
        bool vtrueOrFalseAt = checkObjectEdite.checkAboutAtFun(mail);
        bool vtrueOrFalseIsOpen = checkObjectEdite.isOpenFileFun(signObjectEdite.fileName);
        bool vtrueOrFalseMail = checkObjectEdite.mailTrueFalseFun(mail);

        if(vtrueOrFalseAt == true){ // start check for @ if true
            if (vtrueOrFalseIsOpen == true) { // start check for open
                if (vtrueOrFalseMail == true) { // start check for Mail
                    
                    cout << "Please enter your New Email : ";
                    cin >> signObjectEdite.mail ;
                    cout << "Please enter your New pass : ";
                    cin >> signObjectEdite.pass ;
                    cout << "Please enter your New Name : ";
                    cin >> signObjectEdite.name ;
                    cout << "Please enter your New Id : ";
                    cin >> signObjectEdite.userId ;
                    cout << "Please enter your New age : ";
                    cin >> signObjectEdite.age ;
                    
                    while (getline(inputFile,line)){ // start while
                        if (line == mail){
                            address = &line;
                            *address = mail;
                            cout << "Your mail is Edite = " << address << endl ;
                        }
                        if (line == signObjectEdite.pass){
                            address = &line;
                            *address = mail;
                            cout << "Your mail is Edite = " << address << endl ;
                        }
                        if (line == signObjectEdite.name){
                            address = &line;
                            *address = mail;
                            cout << "Your mail is Edite = " << address << endl ;
                        }
                        if (line == signObjectEdite.userId){
                            address = &line;
                            *address = mail;
                            cout << "Your mail is Edite = " << address << endl ;
                        }
                    } // End while
                    
                    output.close();
                    inputFile.close();
                    
                } else // end if check for Mail
                    cout<<"Sorry This File dosen't open ! " <<signObjectEdite.fileName <<" This message from CheckCls::mailTrueFalseFun \n";
            } else // end if check for open
                cout << "Sorry This E-mail invalid ! "<< mail <<"This message from CheckCls::mailTrueFalseFun \n" <<flush;
        } // end if check for @ if true
        
        delete address;
        address = nullptr;
        return 0;
    } // End fun editeInfo



    // Start shoose fun
    const void EditeCls::chooseFun(const int& choose){
            switch (choose) { // start switch
                case 1:
                    cout << "Enter Your Mail : ";
                    cin >> signObjectEdite.mail;
                    cout << "Enter Your Pass : ";
                    cin >> signObjectEdite.pass;
                    EditeCls::editeInfoFun(signObjectEdite.mail, signObjectEdite.pass);
                    break;
                case 2:
//                    cout << "Enter Your Mail : ";
//                    cin >> signObjectEdite.mail;
//                    cout << "Enter Your Pass : ";
//                    cin >> signObjectEdite.pass;
//                    EditeCls::deleteInfoFun(signObjectEdite.mail, signObjectEdite.pass);
                    break;
                case 3:
                    break;
                default:
                    cout <<"Your choice incorrect !";
                    break;
            } // End switch
    }// End shoose fun

    EditeCls::~EditeCls(){}
}
