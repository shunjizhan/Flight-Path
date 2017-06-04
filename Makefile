CXX=clang++
# CXX=g++

all:
	$(MAKE) cm
	$(MAKE) test1
	$(MAKE) test2
	$(MAKE) test3
	$(MAKE) test4
	$(MAKE) test5
	$(MAKE) test6

run: Main.o
	${CXX} Main.o -o flightPath

test1: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_noNoise.txt

test4: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_big_noNoise.txt

test2: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_someNoise.txt

test5: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_big_someNoise.txt

test3: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_moreNoise.txt

test6: Main.o
	${CXX} Main.o -o flightPath
	./flightPath < tests/input_big_moreNoise.txt

cm:
	/bin/rm -f *.o flightPath

Main.o: Main.cpp
	${CXX} -c Main.cpp