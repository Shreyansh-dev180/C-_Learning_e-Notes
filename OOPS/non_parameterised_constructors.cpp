#include<iostream>
using namespace std;

class student{
    public:
        //NON-PARAMETERISED CONSTRUCTOR->
        //student(); //Constructor but if we want it to print something when called then

        student(){
            cout<<"Constructor is called now"<<"\n";
            name = "Shreyansh Singh"; //also set name to Shreyansh Singh 
        }

        string name;
        int salary;


};

/*A constructor is a function which is used to initialize an object
c++ compiler by default calls it at the time of object creation
but we can manually create one.
1. constructor dont have any return type
2. they have same name as the class
3. a memory is allocated to an object after the contructors are called
4. They are of 3 types
1. non parameterised contructor
2. parameterised constructor
3. copy constructor.
manual constructor should be created in public access modifier.

Constructor can be used to set the values of any property lets say name 
just after creation of object 
if we do student(){
            name = "Shreyansh"; then it will set the name to shreyansh when it 
            it called for object creation so we dont need to do it in main
            function.
}*/

int main(){
    student shreyansh;
    shreyansh.salary = 1200;
    //name already set to given string when shreyansh obj was created so no need 

    cout<<"Name: "<<shreyansh.name<<"\n";
    cout<<"Salary: "<<shreyansh.salary<<"\n";


    return 0;
}