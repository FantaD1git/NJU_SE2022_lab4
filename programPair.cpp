#include"programPair.h"
#include<stdlib.h>
using namespace std;

programPair::programPair(string a, string b){
    Pair = make_pair(a, b);
    ifEqual = 0;
}

void programPair::judgeSelf(){    
    string cmd;    
    cmd = "g++ " + Pair.first + " -o programA.out";
    if(system(cmd.c_str()) != 0){
        cout << "ProgramPair.first compile error." << endl;
        exit(-1);
    }
    cmd = "g++ " + Pair.second + " -o programB.out";
    if(system(cmd.c_str()) != 0){
        cout << "ProgramPair.second compile error." << endl;
        exit(-1);
    }
    for(int i = 0; i < 10; i++){
        //summon output
            //summon a
        cmd = "./programA.out <i_txt/input_" + to_string(i) + ".txt >o_txt_a/output_" + to_string(i) + "_a.txt";
        if(system(cmd.c_str()) != 0)continue;
            //summon b
        cmd = "./programB.out <i_txt/input_" + to_string(i) + ".txt >o_txt_b/output_" + to_string(i) + "_b.txt";
        if(system(cmd.c_str()) != 0)continue;
        
        //judge output
        string o_a = "o_txt_a/output_" + to_string(i) + "_a.txt";
        string o_b = "o_txt_b/output_" + to_string(i) + "_b.txt";
        string a = readFileIntoString(o_a);
        string b = readFileIntoString(o_b);
        if(a != b){
            system("rm -f *.out");
            ifEqual = false;
            return;
        }
    }
    system("rm -f *.out");
    ifEqual = true;
}

string programPair::readFileIntoString(string filename){
    ifstream in_file(filename.c_str());
    string ret;
    in_file.seekg(0, ios::end);
    ret.resize(in_file.tellg());
    in_file.seekg(0, ios::beg);
    in_file.read(&ret[0], ret.size());
    in_file.close();
    return ret;
}

bool programPair::getEquality(){
    return ifEqual;
}

pair<string, string> programPair::getPair(){
    return Pair;
}