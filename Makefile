CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) test2

run: Main.o
	${CXX} Main.o -o flightPath

test1: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_noNoise.txt

test2: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_big_noNoise.txt

clean:
	/bin/rm -f *.o flightPath

Main.o: Main.cpp
	${CXX} -c Main.cpp