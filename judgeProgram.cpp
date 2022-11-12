#include"judgeProgram.h"

void judgeProgram::inputPath(){
    cout << "Please enter a DIRECTORY: ";
    string path;
    cin >> path;
    inputProgram IN;
    IN.setInputPath(path);
    IN.getStdin(input_types);
    IN.createPairs(program_pairs);
}

void judgeProgram::summonInput(){
    vector<inputType>::iterator it;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++){
        string out_name;
        out_name = "i_txt/input_" + to_string(i) + ".txt";
        ofstream out_file(out_name.c_str(), ios::out);
        for(it = input_types.begin(); it != input_types.end(); it++){
            string input = it->outPut();
            out_file << input << " ";
        }
        out_file.close();
    }    
}

void judgeProgram::judgeAll(){
    vector<programPair>::iterator it;
    ofstream out_equal("output/equal.csv", ios::out | ios::trunc);
    ofstream out_inequal("output/inequal.csv", ios::out | ios::trunc);
    out_equal << "file1" << "," << "file2" << endl;
    out_inequal << "file1" << "," << "file2" << endl;
    for(it = program_pairs.begin(); it != program_pairs.end(); it++){
        it->judgeSelf();
        //cout << boolalpha;
        //cout << it->getEquality() << endl;
        pair<string, string> p = it->getPair();
        if(it->getEquality()){
            out_equal << p.first << "," << p.second << endl;
        }
        else{
            out_inequal << p.first << "," << p.second << endl;
        }
    }
    out_equal.close();
    out_inequal.close();
}