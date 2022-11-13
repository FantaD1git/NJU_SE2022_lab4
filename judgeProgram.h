#pragma once
#include"inputProgram.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<vector>
#include<utility>
#include"inputType.h"
#include"programPair.h"
class judgeProgram{
    vector<programPair> program_pairs;
    vector<inputType> input_types;
public:
    void inputPath();
    void summonInput();
    void judgeAll();
};