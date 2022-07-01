all: chart assign4
chart: LinkedList.h chart.o
	g++ -std=c++11 LinkedList.h chart.o -o chart
assign4: LinkedList.h assign4.o
	g++ -std=c++11 LinkedList.h assign4.o -o assign4
chart.o: chart.cpp
	g++ -std=c++11 chart.cpp -c
assign4.o: assign4.cpp
	g++ -std=c++11 assign4.cpp -c
clean:
	rm -rf *.o dist
