#include<iostream>
#include<list>
using namespace std;

/* we can access the digits of number by two methods
1. by converting int to string
2. by taking modulo % with 10 continously*/

void digits(int num){
    list<int> l;
    while(num != 0){
        int dig = num % 10;
        l.push_front(dig); //last digit so for avoid reversing;
        num/= 10;
    }

    for(auto nums: l){
        cout<<nums<<' ';
    }
}

int main(){
    int n = 123213;

    digits(n);


    return 0;
}