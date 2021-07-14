#Demetra Drizis
#Project 1
#09/24/19


-std=c++11

all:
	g++ -g -c -std=c++11 Cell.cpp
	g++ -g -c -std=c++11 TestCell.cpp
	g++ -g -o TestCell Cell.o TestCell.o

	g++ -g -c -std=c++11 MaxSubRange.cpp
	g++ -g -o MaxSubRange MaxSubRange.o Cell.o

	g++ -g -c -std=c++11 TestSeq.cpp
	g++ -g -o TestSeq TestSeq.o Cell.o

	g++ -g -c -std=c++11 dmd16e_driver.cpp
	g++ -g -o Driver dmd16e_driver.o Cell.o
clean:
	rm *.o
	rm TestCell
	rm MaxSubRange
	rm TestSeq
	rm Driver
