#include<iostream>
#include<chrono>
using namespace std;


int main(){
    //counting time in diff time ms, ns, s,m,h etc;

    //Create an object representing 10 seconds.
    chrono::seconds s(12); //12 sec timer
    //count it;
    cout<<"Seconds: "<<s.count()<<'\n'; // 12 output

    // diff units
    chrono::milliseconds m(500);

    chrono::microseconds ms(1000);

    cout<<"Milliseconds: "<<m.count()<<'\n';
    cout<<"Microsecond: "<<ms.count()<<'\n';



    return 0;
}