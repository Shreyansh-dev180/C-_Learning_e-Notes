#include<iostream>
using namespace std;

int changex(int x){
    
    x = 10; // The copy of x will be changed and orignal x remain unchanged.
    return x;
}


int main(){
    int x{5};
    changex(x); //Passed the value so a copy of x will be passed to function.
    //verify;
    cout<<"From main orignal x: "<<x<<'\n';




    return 0;
}