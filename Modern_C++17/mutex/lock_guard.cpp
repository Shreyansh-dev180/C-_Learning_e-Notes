#include<iostream>
#include<thread>
#include<mutex>
// #include<chrono>
using namespace std;

mutex m;

/*lock_guard is more flexible way to use mutex
we only need to create a lock guard and then whenever it goes out
of the scope it automatically unlocks the mutex.

work()
  ↓
lock_guard<mutex> lock(m)
  ↓
Acquire m 🔒
  ↓
for loop
  ↓
counter++
counter++
counter++
  ↓
work() ends
  ↓
lock_guard destroyed
  ↓
Release m 🔓*/

void work(int *counter){
    lock_guard<mutex> lock(m); //locked mutex m;
    for(int i = 1; i <= 1000000; i++){
        (*counter)++;
    }
}//mutex unlocked


int main(){
    int nums = 0;
    thread t1(work, &nums);
    thread t2(work, &nums);
    t1.join();
    t2.join();
    // t1.detach();
    // t2.detach();
    // this_thread::sleep_for(chrono::seconds(2));
    cout<<nums<<'\n';
}