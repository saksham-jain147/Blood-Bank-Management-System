# Blood-Bank-Management-System
Blood banking management system is an application-based project which is developed using C++ programming language and its concepts including file handling and data structures.

### Purpose:
The purpose of this project is to provide was to assist the information of blood bags during its handling in the blood bank. This system is designed to store, process, retrieve and analyse information concerned with the administrative and inventory management within a blood bank. It aims to maintain all the information related to the blood donors, different blood groups available in the blood bank and help them manage in a better way.

### Architecture:
This project consist of 5 main entities for which 5 main classes has been created as follows:
1.	Login
2.	Admin
3.	Customer
4.	Donor
5.	Hospital

Remaining classes are created to reduce complexity of code. In this application there are 4 roles namely Admin, Customer, Donor, Hospital. Admin is supervising the customer, donor and hospital. A person class has been created which contains all the person attributes and since donor and customer are persons, they have ‘is-a’ relationship between them and hence these two classes are inherited the person class. Order and stock have a ‘has-a’ relationship with the customer, donor and hospital modules. Person class has containment relation with date class.
