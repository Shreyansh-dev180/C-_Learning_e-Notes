#include<iostream>
#include<chrono>
using namespace std;


int main(){
    chrono::seconds s(10);

    //convert sec (s) in milliseconds;

    chrono::milliseconds m = 
    chrono::duration_cast<chrono::milliseconds> (s);

    cout<<"10 sec in millisecond: "<<m.count()<<'\n';

    chrono::hours h(2);

    // 2 hours in minutes 
    chrono::minutes minu = 
    chrono::duration_cast<chrono::minutes> (h);

    cout<<"2 Hours in minutes: "<<minu.count()<<'\n';


    return 0;
}