#include<iostream>
#include<cstdlib>
using namespace std;

class Teacher{
    public:
        string name;
        int* salary; //pointer in stack memory pointing at heap memory var.

        // parameterised Constructor
        Teacher(string name , int salary){
            (*this).name = name;
            // also written as 
            // (*this).salary = new int(salary);
            (*this).salary = new int(0);//initialize heap memory var with 0;
            //and store it to salary pointer.

            *((*this).salary) = salary; //dereference the obj1 and access
            //the salary property now salary is also a pointer so dereference 
            // it again now we get the heap var.

            //can also be written as->
            // *(this->salary) = 211;
        }

        //getter->
        void getinfo(){
            cout<<"Name: "<<name<<'\n';
            cout<<"Salary: "<<*salary<<'\n';
        }

        //destructor 
        ~Teacher(){
            cout<<"Destructor Called\n";
            delete salary;
            // no delete salary;  statement will result in memory leak
        }

};

/*How to create heap memory called dynamic memory so 
for this we do it using new operator 
first we create a pointer property in class which store the address of 
heap memory var now in constructor we do this->pointer = new int(value of var)
*/

/*A destructor can deallocate memory from object whose properties 
are in stack memeory but they are in heap memory lets say 
property of class is pointer salary pointing at the variable with value 
of salary in heap memeory now normal destructor cannot deallocate the 
memory it will delete the pointer salary now the heap memeory variable 
address will be lost and now that space cant be used again and result in 
memory leak now for deleting dynamic properties having pointers we use 
delete statement it safely deallocates the heap variable memory first then 
delets the stack memory salary pointer*/

int main(){
    Teacher t1("Shreyansh Singh", 4800000);
    
    t1.getinfo();



    return EXIT_SUCCESS;
}