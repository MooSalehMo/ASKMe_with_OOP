//
//  signinSignup.h
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 26/01/25.
//

#ifndef SIGNINSIGNUP_H // Include Guard
#define SIGNINSIGNUP_H
#include "edite.h"

namespace SigninSignupAsk { // Start Namespace
    class signinSignupCls { // Start class
        public:
            const int signinFun(void);
            int signupFun(void);
            int deleteFun(string userId, string pass);
            int editeFun(string userId);
            const void chooseFun(int choose);
            friend class EditeAsk::EditeCls;
            signinSignupCls();
        private:
            string userId,pass,name, mail, fileName, mailPlusPass;
            int age;
        
    }; // End class
} // End Namespace

#endif
