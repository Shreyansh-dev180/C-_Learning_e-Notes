#include<iostream>
using namespace std;

void changex(int* x){ // x ke address ko store karne ke liye pointer chahiye na.
    *x = 12;// x ke location pe jo value hai usko 12 kardo;
}

int main(){
    int x{6};

    //if we want to reflect the function changes to our orignal x 
    // so we pass the address of x so chnage took place at orignal x ;

    changex(&x); // x ke address ko pass kar do function ko;

    cout<<"x from main: "<<x<<"\n"; // ab changed value aayegi x ki;

    //yahi pass by referece hota hai means arguments ke address ko pass karna 
    // uski copy ke aalawa;

    return 0;
}