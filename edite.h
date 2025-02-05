//
//  edite.h
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 28/01/25.
//
#ifndef MY_Edite_H// Include Guard
#define MY_Edite_H
#include <string>

namespace EditeAsk {
class EditeCls {
        public:
            int editeInfoFun(const string& mail, const string& pass);
            const void chooseFun(const int& choose);
            EditeCls();
            ~EditeCls();
        };
}

#endif // MY_MENUE_H
