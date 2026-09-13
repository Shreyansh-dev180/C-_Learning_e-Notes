#include<iostream>
using namespace std;


int gcd(int a, int b){
    if(a == b){
        return a;
    }

    while(a > 0 && b > 0){
        if(a > b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a == b){
        return a;
    }
    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }
    return -1;
}


int main() {
    cout<<gcd(0,4);
}