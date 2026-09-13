#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

using namespace std;

mutex m;

void work(int* counter){
    lock_guard<mutex> lock(m);
    for(int i = 1; i <= 1000000; i++){
        (*counter)++;
    }
}

int main(){
    int nums = 0;
    thread t1(work , &nums);
    cout<<"T1 just started working\n t1-->mutex\n";
    //main thread check
    if(m.try_lock() == true){
        cout<<"Main Thread got the mutex\n";
    }

    else{
        cout<<"Mutex is busy and Main is waiting\n";
    }

    t1.join();


    return 0;
}