#include"inputType.h"

inputType::inputType(string t, int l, int h){
    TYPE = t;
    low = l;
    high = h;
}

string inputType::outPut(){
    string s;
    srand((unsigned)time(NULL));
    if(TYPE == "int"){
        int r = (rand() % (high - low + 1)) + low;
        s = to_string(r);
    }
    else if(TYPE == "char"){
        char r = ((rand() % 2) ? 'A' : 'a') + (rand() % 26);
        s = r;
    }
    else if(TYPE == "string"){
        int len = (rand() % (high - low + 1)) + low;
        for(int i = 0; i < len; i++){
            char r = ((rand() % 2) ? 'A' : 'a') + (rand() % 26);
            s += r;
        }
    }    
    return s;
}