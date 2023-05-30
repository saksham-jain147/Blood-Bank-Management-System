all: test

test: main.o TestAdmin.o datedef.o persondef.o admin_def.o login_def.o stockdef.o hospital_def.o orderdef.o  
	g++ main.o TestAdmin.o -lcppunit -ldl admin.h admin_def.cpp date.h datedef.cpp person.h persondef.cpp login.h login_def.cpp stock.h stockdef.cpp order.h orderdef.cpp hospital.h hospital_def.cpp -o test
		
main.o: main.cpp
	g++ -c main.cpp

TestAdmin.o: TestAdmin.cpp
	g++ -c TestAdmin.cpp

admin_def.o: admin_def.cpp
	g++ -c admin.h admin_def.cpp

login_def.o: login_def.cpp
	g++ -c login.h login_def.cpp
	
datedef.o : datedef.cpp
	g++ -c date.h datedef.cpp
	
persondef.o : persondef.cpp
	g++ -c person.h persondef.cpp

stockdef.o: stockdef.cpp
	g++ -c stock.h stockdef.cpp
	
orderdef.o: orderdef.cpp
	g++ -c order.h orderdef.cpp
	
hospital_def.o: hospital_def.cpp
	g++ -c hospital.h hospital_def.cpp

clean :
	rm *.o
	rm *.gch
    
