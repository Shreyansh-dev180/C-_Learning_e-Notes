#include<iostream>
#include<chrono>
#include<ctime>
using namespace std;

int main(){
    //current_time_ in system clock
    auto now = chrono::system_clock::now();
    //get the raw string
    time_t current = chrono::system_clock::to_time_t(now);

    cout<<ctime(&current)<<'\n'; //convert the raw string to dd-mm-yy
}