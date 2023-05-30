all : blood_bank

blood_bank : datedef.o persondef.o customerdef.o stockdef.o orderdef.o donordef.o hospital_def.o login_def.o admin_def.o
	g++ date.h datedef.cpp person.h persondef.cpp customer.h customerdef.cpp stock.h stockdef.cpp order.h orderdef.cpp donor.h donordef.cpp hospital.h hospital_def.cpp login.h login_def.cpp admin.h admin_def.cpp main_client.cpp -o blood_bank

datedef.o : datedef.cpp
	g++ -c date.h datedef.cpp
	
persondef.o : persondef.cpp
	g++ -c person.h persondef.cpp
	
customerdef.o : customerdef.cpp
	g++ -c customer.h customerdef.cpp

stockdef.o: stockdef.cpp
	g++ -c stock.h stockdef.cpp
	
orderdef.o : orderdef.cpp
	g++ -c order.h orderdef.cpp
	
donordef.o : donordef.cpp
	g++ -c donor.h donordef.cpp
	
hospital_def.o : hospital_def.cpp
	g++ -c hospital.h hospital_def.cpp

login_def.o : login_def.cpp
	g++ -c login.h login_def.cpp
	
admin_def.o : admin_def.cpp
	g++ -c admin.h admin_def.cpp
	
clean :
	rm *.o
	rm *.gch
