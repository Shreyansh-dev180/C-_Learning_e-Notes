#include<iostream>
#include<chrono>
#include<thread>
using namespace std;


int main(){
    auto start = chrono::steady_clock::now();

    int sum{};

    for(int i = 0; i<10000020; i++){
        sum+=i;
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout<<"This program ran for: "<<duration<<" milliseconds\n";

}