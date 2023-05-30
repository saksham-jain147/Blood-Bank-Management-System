all: test

test: main.o test_def.o datedef.o persondef.o donordef.o stockdef.o 
	g++ main.o test_def.o -lcppunit -ldl date.h datedef.cpp person.h persondef.cpp donor.h donordef.cpp stock.h stockdef.cpp -o test
		
main.o: main.cpp
	g++ -c main.cpp

test_def.o: test_def.cpp
	g++ -c test_def.cpp
	
datedef.o : datedef.cpp
	g++ -c date.h datedef.cpp
	
persondef.o : persondef.cpp
	g++ -c person.h persondef.cpp
	
donordef.o : donordef.cpp
	g++ -c donor.h donordef.cpp

stockdef.o: stockdef.cpp
	g++ -c stock.h stockdef.cpp

clean :
	rm *.o
	rm *.gch
    
