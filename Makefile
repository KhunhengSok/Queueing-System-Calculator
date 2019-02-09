all: main.o Queue.o SingleQueue.o
	g++ main.o Queue.o SingleQueue.o -o app && make clear  && app 

main.o: main.cpp
	g++ main.cpp -c 

Queue.o: Queue.h	Queue.cpp	
	g++ Queue.h Queue.cpp -c 

SingleQueue.o: SingleQueue.h SingleQueue.cpp	
	g++ SingleQueue.h SingleQueue.cpp -c 

clear:
	del *.o