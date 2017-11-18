all:fork_test thread_test

fork_test:fork_test.o
	g++ -o fork_test fork_test.o
fork_test.o: fork_test.cpp
	g++ -c fork_test.cpp
thread_test:thread_test.o
	g++ -std=c++11 -pthread -o thread_test thread_test.o
thread_test.o:thread_test.cpp
	g++ -std=c++11 -pthread -c thread_test.cpp 
clean:
	rm -f *.o fork_test thread_test
