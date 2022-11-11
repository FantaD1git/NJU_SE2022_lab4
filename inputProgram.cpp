#include "inputProgram.h"
using namespace std;

inputProgram::inputProgram(string p){
    path = p;
    IN.getFiles();
}

void inputProgram::setInputPath(string p){
    //cin >> path;
    path = p;
    IN.getFiles();
}

void inputProgram::getFiles(){
    DIR *dirp;
    struct dirent *direntp;
    if((dirp = opendir(path.c_str())) == NULL){
        cout << "Open Directory " << path << " Error." << endl;
        exit(-1);
    }
    while((direntp = readdir(dirp)) != NULL){
        string name = direntp->d_name;
        if(name[0]=='.')continue;
        all_files.push_back(name);
        //if (get_file_size_time(buf) == -1)break;
    }
    closedir(dirp);
}

void inputProgram::getStdin(vector<inputType>& input_types){
    vector<string>::iterator it;
    for(it = all_files.begin(); it != all_files.end(); it++){
        if(*it == "stdin_format.txt"){
            all_files.erase(it);
            break;
        }
    }
    string stdinPath = path + "/stdin_format.txt";
    ifstream in_file(stdinPath.c_str(), ios::in);
    if(!in_file) exit(-1);
    string iType;
    in_file >> iType;
    while(!in_file.fail()){
        //cout << iType << endl;
        int left,mid,right;
        if((left = iType.find('(')) != string::npos){
            right = iType.find(')');
            mid = iType.find(',');
            string _type = iType.substr(0, left);
            string _low = iType.substr(left + 1, mid - left - 1);
            string _high = iType.substr(mid + 1, right - mid - 1);
            int l = atoi(_low.c_str());
            int h = atoi(_high.c_str());
            //cout << _type << " " << l << " " << h << endl;
            inputType t(_type, l, h);
            input_types.push_back(t);
        }
        else{
            inputType t(iType, 0, 0);
            input_types.push_back(t);
        }
        in_file >> iType;
    }
    in_file.close();
}

void inputProgram::createPairs(vector<programPair>& program_pairs){
    vector<string>::iterator it;
    vector<string>::iterator _it;
    for(it = all_files.begin(); it != all_files.end(); it++){
        for(_it = it + 1; _it != all_files.end(); _it++){
            programPair p(*it, *_it);
            program_pairs.push_back(p);
            //cout << *it << " " << *_it << endl;
        }
    }
}
/*
int main(){
    inputProgram IN;
    IN.inputPath();
}
*/