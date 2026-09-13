#include<iostream>
#include<cstdlib>
using namespace std;

//inheritance means accessing property from parent to child class
class Student{ //parent class
    public: 
        Student(string name, string roll_number){
            this->name = name;
            this->roll_number = roll_number;
        }
        string name;
        string roll_number;

        void getinfo(){
            cout<<"Name is: "<<name<<'\n';
            cout<<"Roll_number is: "<<roll_number<<'\n';
            
        }
};

/* When we create a College_student object, the compiler cannot directly
construct the child object. It must first construct the Student (parent)
part because College_student inherits from Student.

If we do not specify which Student constructor to call, the compiler
automatically tries to call the default constructor Student().

In our Student class, only a parameterized constructor exists, so
Student() does not exist. Therefore, the compiler gives a compilation
error.

To fix this, we explicitly tell the compiler to call the parameterized
parent constructor by writing:

    : Student(name, roll_number)

This is called the member initializer list.

Another way to avoid the error is to create a default constructor
Student(). Then, if we do not specify a parent constructor, the compiler
can successfully call Student() automatically. */


// Create College_student object.

// ↓

// Before I can create College_student,
// I must first create its Student part.

// ↓

// Did the programmer tell me which Student constructor to use?

// ↓

// YES
// → Student(name, roll_number)

// NO
// → I'll try Student()

// ↓

// Does Student() exist?

// YES
// → Continue.

// NO
// → Compilation Error.

class College_student: public Student{ //child class inherit name and rn.
    public: 
        College_student(string name, string roll_number, int salary)
        :Student(name,roll_number){
            this->salary = salary;
        }

        int salary; //its own unique property along with two other property
        void getinfo(){
            cout<<"Name is: "<<name<<'\n';
            cout<<"Roll_number is: "<<roll_number<<'\n';
            cout<<"Salary is: "<<salary<<'\n';
        }

};

//use case-->

/*Inheritance is the process to access the same properties of parent class
in child class lets say we have student class with name and roll no.
property then in college_student class instead of declaring things again 
i just inherited it from student class and it also has its unique 
property salary. It increases readablity and makes our code look clean
and follows the dont repeat yourself principle well.*/

//syntax explanation-->

/*here we created a normal student class now we created a second class
College_Student and wrote its syntax like this we added an extra thing
":public Student" this means inherit the properties of Student class in 
this College_Student class and make these inherited properties as public
syntax for inheritance is access modifier then parent class name."*/


int main(){
    Student s1("Shreyansh Singh", "48 lakh");
    s1.getinfo();
    College_student cs1("Ram", "1234" , 4800000);
    cs1.getinfo();





    return EXIT_SUCCESS;
}