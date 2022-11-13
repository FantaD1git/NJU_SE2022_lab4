#include"inputProgram.h"
#include"judgeProgram.h"
#include"programPair.h"
#include"inputType.h"

int main(){
    judgeProgram J; 
    J.inputPath();
    J.summonInput();
    J.judgeAll();
    cout << "Judging complete!" << endl;
}