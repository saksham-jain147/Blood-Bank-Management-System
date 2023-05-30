all : test

test : main.o test_def.o hospital_def.o stockdef.o orderdef.o test_def.o
	g++ main.o test_def.o -lcppunit -ldl hospital.h hospital_def.cpp stock.h stockdef.cpp order.h orderdef.cpp -o test

main.o: main.cpp
	g++ -c main.cpp
	
hospital_def.o : hospital_def.cpp
	g++ -c hospital.h hospital_def.cpp
	
stockdef.o: stockdef.cpp
	g++ -c stock.h stockdef.cpp

orderdef.o : orderdef.cpp
	g++ -c order.h orderdef.cpp
	
test_def.o: test_def.cpp
	g++ -c test_def.cpp

clean :
	rm *.o
	rm *.gch
   
