#include<iostream>
#include<memory>
using namespace std;

/*shared ptr is similar to unique ptr but in unique ptr there was lacking that
if we want to give ownership to multiple ptrs then its not possible and shared 
ptr solves the exact problem it allows multiple ownerships of same object.*/

/*when the object is destroyed?
in shared ptr object is not destroyed until it is owned by even a single ptr;
lets say we have p1 and p2 and p3 pointing and owing the same obj then if p2 and p3 
destroyed then object will not be destroyed because p1 still owns it.
same goes for reset if we say p1.reset then p1 = nullptr but p2 and p3 still owns it*/


int main(){
    //syntax
    shared_ptr<int> p1 = make_shared<int>(20);

    //multiple owners
    shared_ptr<int> p2 = p1;
{//created
    shared_ptr<int> p3 = p1;
}    //p3 will be destroyed not the object

    cout<<"P1: "<<*p1<<'\n';
    cout<<"P2: "<<*p2<<'\n';

    *p1 = 60; //p1=60;
    cout<<"P2 new value: "<<*p2<<'\n'; //60;

    //reset
    p1.reset(); //p1 = nullptr but p2 have the ownership.
    cout<<"P1 is Nullptr\n";

    cout<<"P1 gets the ownership\n";
    p1 = p2;

    //use_count to know how many owners are there of same obj

    cout<<"Owners: "<<p2.use_count()<<'\n';
    cout<<"Owners with p1: "<<p1.use_count()<<'\n';
    

    return 0;
}