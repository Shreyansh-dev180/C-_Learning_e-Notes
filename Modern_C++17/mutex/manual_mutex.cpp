#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//creating a mutex m;
mutex m;
//showing how mutex fix the issue with thread counter++ experiment;

void work(int* counter){
    m.lock();
    for(int i = 1; i<= 1000000; i++){
        (*counter)++;
    }
    m.unlock();
}

int main(){
    int nums = 0;
    thread t1(work, &nums);
    thread t2(work, &nums);
    t1.join();
    t2.join();

    cout<<nums<<'\n';
    
}