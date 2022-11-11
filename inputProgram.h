#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<utility>
#include<sys/types.h>
#include<dirent.h>
#include"inputType.h"
#include"programPair.h"
using namespace std;
class inputProgram{
    string path;
    vector<string> all_files;
public:
    inputProgram(string p);
    void setInputPath(string p);
    void getFiles();
    void getStdin(vector<inputType>& input_types);
    void createPairs(vector<programPair>& program_pairs);
};
/*
programPair::programPair(string a, string b){
    Pair = make_pair(a,b);
    ifEqual = 0;
}

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
*/