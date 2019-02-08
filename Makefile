all: main.o Model.o
	cls && g++ main.o Model.o -o app && make clear && app 

main.o: main.cpp
	g++ main.cpp -c 

Model.o: Model.h	Model.cpp	
	g++ Model.h Model.cpp -c 

clear:
	del *.o