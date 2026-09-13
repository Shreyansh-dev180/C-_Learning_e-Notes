#include<iostream>
#include<cstdlib>
using namespace std;

class teacher{
    public:
        //Constructor->
        teacher(string name , int salary){
            //Constructor Called;
            cout<<"Constructor Called.\n";
            (*this).name = name;
            (*this).salary = salary;
        }
        string name;
        int salary;

        void getinfo(){
            cout<<"Getinfo called\n";
            cout<<"Name: "<<name<<'\n';
            cout<<"Salary: "<<salary<<'\n';
        }

        //Destructor->
        ~teacher(){
            cout<<"Destructor Called\n";
        }



};

/*Just like constructor is called to initialize an object and
allocate memory to it similarly --
destructor is called at the end of program to deallocate the memory 
occupied by the objects*/

int main(){
    teacher t1("Shreyansh Singh" , 4800000);
    t1.getinfo();

    return EXIT_SUCCESS;
}