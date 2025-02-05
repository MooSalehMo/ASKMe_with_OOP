//
//  check.cpp
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 27/01/25.
//
#include <iostream>
#include <fstream>
#include  <string>
#include "check.h"
#include "signinSignup.h"
#include "menue.h"
using namespace std;

//Start define objects
SigninSignupAsk::signinSignupCls singObjectInCheckCls;
MenueAsk::MenueCls menueObjectInCheckCls;
//End define objects

// Start namespace Eeducation_sCheck
namespace Check_Ask {
    // Start define CheckCls
    CheckCls::CheckCls(): pArr(new char[0]), sLine(""), fileName(""), mailPass(""), bFindMail(false),bFindAt(false), bIsOpen(false) {}
    // End define CheckCls

    // Start fun isOpen with parameter string
    bool CheckCls::isOpenFileFun(string fileName){
        fstream output(fileName, ios::out | ios::app | ios::in);
        CheckCls::bIsOpen = false ;
        if(output.is_open()) {
            CheckCls::bIsOpen = true ;
        }
        output.close();
        return CheckCls::bIsOpen ;
    }
    // Start fun isOpen with parameter string

    // Strat fun check @
    bool CheckCls::checkAboutAtFun(string mail) {
        double size =0;
        CheckCls::bFindAt = false;
        size = mail.length();
        strcpy(CheckCls::pArr, mail.c_str());

        for (int i = 0; i < size; i++)
            if(CheckCls::pArr[i] == '@')
                CheckCls::bFindAt = true;
        return CheckCls::bFindAt;
    } // End fun check @
    
    // Srart fun mail and pass true or false
    bool CheckCls::mailTrueFalseFun(string smail){
            CheckCls::bFindMail = false;
            CheckCls::sLine = "";
            string line ;
            CheckCls::fileName = "data.txt" ;
            fstream inputFile(CheckCls::fileName, ios::in);
            bool vAtTrueFalse = CheckCls::checkAboutAtFun(smail);
            bool vOpenTrueFalse = CheckCls::isOpenFileFun(CheckCls::fileName);
            if(vAtTrueFalse == true){ // start check for @ if true
                if (vOpenTrueFalse == true) { // Start check for open
                    while (getline(inputFile,line))  // Start while loop getting mail and pass
                        if (line == smail)  // Start check Email and pass
                            CheckCls::bFindMail = true;
                }else  // End check for open
                    cout<<"Sorry This File isn't open ! " <<fileName <<" This message from CheckCls::mailTrueFalseFun \n";
            } else  { // End check for @ if true
                cout << "Sorry This E-mail invalid ! "<< smail <<" This message from CheckCls::mailTrueFalseFun \n";
                cout << "Do you wanna to try agin? (if you want choose number 1 , if not choose any number !) : ";
                int tryAgbin, choose=0 ;
                cin >> tryAgbin ;
                switch (tryAgbin) {
                    case 1:
                        menueObjectInCheckCls.signinSignupFun();
                        cin>> choose;
                        singObjectInCheckCls.chooseFun(choose);
                        break;
                    default:
                        cout << "Good bye .\n";
                        break;
                }
            }// End check for open
            inputFile.close();
        return CheckCls::bFindMail;
    } // End fun mail True or False

    // Start define destructor CheckCls
    CheckCls::~CheckCls(){
        cout << "We are finished this message from destructor CheckCls\n";
        delete [] CheckCls::pArr;
        CheckCls::pArr = nullptr;
    } // End define destructor CheckCls

} // End namespace Eeducation_sCheck

