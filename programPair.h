#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
class programPair{
    pair<string, string> Pair;
    bool ifEqual;
public:
    programPair(string a, string b);
    void judgeSelf();
    string readFileIntoString(string filename);
    bool getEquality();
    pair<string, string> getPair();
};