#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;

class inputType{
    string TYPE;
    int low, high;
public:
    inputType(string t, int l, int h);
    string outPut();
};