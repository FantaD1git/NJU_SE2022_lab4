main: main.o inputType.o programPair.o inputProgram.o judgeProgram.o
	g++ main.o inputType.o programPair.o inputProgram.o judgeProgram.o -o main
main.o: main.cpp
	g++ -g -c main.cpp
judgeProgram.o: judgeProgram.cpp judgeProgram.h
	g++ -g -c judgeProgram.cpp
inputProgram.o: inputProgram.cpp inputProgram.h
	g++ -g -c inputProgram.cpp
inputType.o: inputType.cpp inputType.h
	g++ -g -c inputType.cpp
programPair.o: programPair.cpp programPair.h
	g++ -g -c programPair.cpp
clean:
	rm -f *.o *.out i_txt/*.txt o_txt_a/*.txt o_txt_b/*.txt main
