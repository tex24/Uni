#include "network.h"
#include <string>
using namespace list;

Network createEmptyNetwork(){
    return emptyNetwork;
}

bool isEmpty(const Network& net){
    return (!net || !net->members);
}

bool user_Login_correct(string usr_Log){
    if(usr_Log == "")
        return false;
    if((usr_Log < 'a' || usr_Log > 'z') && (usr_Log < 'A' || usr_Log > 'Z'))
        return false;
    return true;
}

