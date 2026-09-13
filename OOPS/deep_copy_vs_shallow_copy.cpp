#include<iostream>
#include<cstdlib>
using namespace std;

//Problem with shallow copy->
class Teacher{
    public:
        int *password;

        Teacher(int password){
            (*this).password = new int(password);
            //also written as
            // (*this).password = new int(0); //initialize with 0;
            // *((*this).password) = password;
        }

        //copy constructor->
        Teacher(Teacher &obj1){
            // (*this).password = obj1.password; shallow copy!
            password = new int(0);
            *((*this).password) = *(obj1.password);
        }

        // getter ->
        void getinfo(){
            cout<<"password: "<<*password<<"\n";
        }
     
};

/*with shallow copy one object's value is copied to another obj no change
but here we have dynamic variable in heap memory and there is password which
is a pointer which points to heap variable and have address of that var 
now when we do shallow copy  the other obj just get the address of same 
heap var in their password as well as a result whenever they change the value
of heap var then actually both objects have same heap var so one's change
will reflect to other so even one change the value then other's value will 
also change.*/

/* for tackling this we use deep copy when a obj2 calls copy constructor
to copy the obj1 password value then instead of just copy pasting the same 
address we create a separate dynamic variable for that caller obj2 and 
in that heap variable we store the same value of orignal heap var so 
techincally both have same value but they are different var in heap memory 
pointed by different pointer password
pointer password for obj1 will point to other heap var 
and pointer password for obj2 will point to another heap var 
so one's change will not reflect to other.
at last we are actually making them separate*/

int main(){
    Teacher t1(1234);
    t1.getinfo();
    Teacher t2(t1);
    *(t2.password) = 4800000;
    t2.getinfo();
    // cout<<"T1 changed also from 1234 to 48lakh\n";]]
    cout<<"t1 will not change and remain 1234\n";
    t1.getinfo();


    return EXIT_SUCCESS;
}
