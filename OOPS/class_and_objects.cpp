#include<iostream>
using namespace std;
//basic class syntax ->
//class is like a blueprint for how the objects will look like?

class Student{
    //can be accessed from anywhere in the program;
    public:
    string name;
    string stream;
    string standard;
    int networth;

    // public methods(functions in class to do some tasks like changing newworth or name);

    // 1. for changing the name 
    void change_name(string newName){
        name = newName;
    }

    //change private properties bankpin and banknumber-->
    void change_bank_details(int newpin , int newnum){
        bankpin = newpin;
        banknumber = newnum;
    }

    void display_private_details(){
        cout<<"Bankpin is: "<<bankpin<<"\n"; //private properties can be accessed with methods.
        cout<<"New Banknumber is: "<<banknumber<<"\n";
    }


    //cannot be accessed in main() function only used in class methods or inside this class;
    private:
    int bankpin;
    int banknumber;
    


};



int main(){
    //Creating an object ->
    Student shreyansh;
    //public properties-->
    shreyansh.name = "Shreyansh";
    shreyansh.networth = 1200;
    shreyansh.standard = "10th";
    shreyansh.stream = "PCM";

    // changing name using methods

    shreyansh.change_name("Shreyansh Don");

    cout<<"Name: "<<shreyansh.name<<"\n";
    cout<<"Networth: "<<shreyansh.networth<<"\n";
    cout<<"Standard: "<<shreyansh.standard<<"\n";
    cout<<"Stream: "<<shreyansh.stream<<"\n";

    //trying to access private properties-->
    // shreyansh.bankpin = 1223;
    // shreyansh.banknumber = 505050;
    //Both will give error because they are private properties
    //but we can change or assign them new values with the help of methods.


    //Assigning new values to private bankdetails properties:
    shreyansh.change_bank_details(12,10);


    //accessing private property by method;
    shreyansh.display_private_details();




    return 0;
}