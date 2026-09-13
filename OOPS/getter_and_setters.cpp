#include<iostream>
using namespace std;

class coder{
    private:
        int salary;

    public:
        string name;
        string dept;

    //getters and setter should be defined in public access modifier so that
    // can be accessed by main function.


    //setter are used to set the values of private or public properties of class.
    void setname(string n){
        name = n;
    }
    void setdept(string d){
        dept = d;
    }
    void setsalary(int s){
        salary = s;
    }

    //getters are used to get the values of private and public properties

    void getname(){
        cout<<"Name: "<<name<<"\n";
    }
    void getdept(){
        cout<<"Department: "<<dept<<"\n";
    }
    void getsalary(){
        cout<<"Salary: "<<salary<<"\n";
    }
    

};

int main(){

    coder shreyansh;
    shreyansh.setname("Shreyansh Singh");
    shreyansh.setdept("Computer Science");
    shreyansh.setsalary(4800000);

    shreyansh.getname();
    shreyansh.getdept();
    shreyansh.getsalary();

    return 0;
}