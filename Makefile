MinSkewHeap: main.o Executive.o MinSkewHeap.o Node.o
	g++ -g -std=c++11 main.o Executive.o MinSkewHeap.o Node.o -o MinSkewHeap

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp MinSkewHeap.h
	g++ -std=c++11 -g -c Executive.cpp

MinSkewHeap.o: MinSkewHeap.h MinSkewHeap.cpp Node.h
	g++ -std=c++11 -g -c MinSkewHeap.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o MinSkewHeap
