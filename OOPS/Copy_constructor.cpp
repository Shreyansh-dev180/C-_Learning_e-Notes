#include<iostream>
using namespace std;

class student{
    public:
        student(string n , int pass){
            cout<<"Constructor called and value assigned."<<"\n";
            name = n;
            password = pass;
        };
        string name;
        int password;

        void getproperties(){
            cout<<"Name: "<<name<<"\n";
            cout<<"password: "<<password<<"\n";
        }
};

int main(){
    student shreyansh("Shreyansh Singh" , 1234);

    /*Suppose we create obj 1 so now if we want to copy all values of name and 
    password to another obj2 then we do student obj2(obj1) after that copy 
    constructor will be called by c++ by default and copy obj1 property values
    exactly in another obj2;*/

    student shubham(shreyansh);
    //properties value will be same in both cases because we have copied them;

    shreyansh.getproperties();
    shubham.getproperties();
    



    return 0;
}