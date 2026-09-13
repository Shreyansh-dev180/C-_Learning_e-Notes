#include<iostream>
using namespace std;

class teacher{
    public:
        teacher(){
            cout<<"Constructor called"<<"\n";
        }; //constructor for obj

        // copy constructor
        teacher(const teacher &obj1){ //means obj will be from teacher class
            this->name = obj1.name; //set this name to obj1.name
            this->password = obj1.password;
        }

        //can be also written as->
        // teacher(const teacher* obj1){
        //     (*this).name = (*obj1).name;
        //     (*this).password = (*obj1).password;
        // }

        string name;
        int password;

        void getinfo(){
            cout<<"Name: "<<name<<"\n";
            cout<<"password: "<<password<<"\n";
        }

};

/* Why use const teacher& obj1 ?

1. Passing by reference avoids making a copy.
2. const ensures that the original object cannot be modified accidentally.
3. const references can bind to temporary objects, making them more flexible.
*/


/*Q1. Why pass by reference not pass by value?
Ans: Because if we do pass by value then a copy of parameter obj1 
will be created and for creating this copy constructor will be called 
by default and then that constructor will also see that obj1 copy should be 
created so it will call another copy constructor so on and leads to undefined 
behaviour. */

/*1. We used teacher& obj1 this means the obj1 will always be from 
teacher class and we used & operator because if we use this then 
when we pass obj1 then instead of creating its copy the & operator 
will tell c++ that its the orignal obj and we are just going to call it
by this name obj1 hence we dont need to dereference it or do 
anything extra we can just type obj1.name and other properties*/

/*2. there is another way of pass by reference, in main function we will
pass the address of obj whose we want copy lets say obj1 now in class constructor
parameter we need pointer to store that address like 'teacher* s' now it has the 
address of orignal object whose copy we want now for accessing values of obj1 
first we need to dereference it like (*s).name means first find all properties 
which are at the address stored in s and then find name property there 
for dereferencing we can also use -> operator like "s->name" it is same like 
(*s).name*/

/* A reference is not a pointer.
   Mental model:
   teacher& obj1 ≈ hidden pointer automatically dereferenced by C++.

   So:

   obj1.name

   is conceptually similar to:

   (*ptr).name

   but references have cleaner syntax and cannot be null. */

int main(){\
    teacher shreyansh;
    shreyansh.name = "Shreyansh Singh";
    shreyansh.password = 1234;

    teacher rohan(shreyansh);

    shreyansh.getinfo();
    rohan.getinfo();
    



    return 0;
}