//
//  check.h
//  AskApp
//
//  Created by Mohamed Saleh Mohamed Ragab on 27/01/25.
//

#ifndef MY_CHECK_H // include guard
#define MY_CHECK_H
#include <string>
using namespace std;

// Start namespace Eeducation_sCheck
namespace Check_Ask {
    class CheckCls {
        public:
            bool checkAboutAtFun(string mail);
            bool mailTrueFalseFun(string mail);
            bool isOpenFileFun(string nameFile);

            CheckCls();
            ~CheckCls();
    private:
        bool bFindAt, bFindMail, bIsOpen;
        string sLine ,mailPass, fileName;
        char* pArr;
    };
}// End namespace Eeducation_sCheck
#endif /* MY_STRUCTCHECK_H */
