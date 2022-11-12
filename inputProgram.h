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
    void setInputPath(string p);
    void getFiles();
    void getStdin(vector<inputType>& input_types);
    void createPairs(vector<programPair>& program_pairs);
};