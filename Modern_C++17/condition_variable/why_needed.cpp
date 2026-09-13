#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

/*here in this program t2 has to check continously whether t1 
finished calculating the sum and it goes for 10 seconds which is 
waste of cpu power instead we need something like t2 sleep and 
if the ready condition changes from false to true then t2 wakes and 
cout the sum this is more efficient and this could be done by 
conditional variable which allows the thread to sleep until a 
specific condition becomes true.*/

mutex m;

bool ready = false;

void work1(int* sum){
    for(int i = 1; i <= 100000; i++){
        (*sum)+= i;
    }

    this_thread::sleep_for(chrono::seconds(2));
    lock_guard<mutex> lock(m);
    ready = true;
}

void work2(int* sum){
    while(!ready){
        cout<<"T1 is doing its work\n";
    }
    cout<<"Sum of 1 to 100000 num is : "<<sum<<'\n';
}

int main(){
    int sum = 0;

    thread t1(work1, &sum);    
    thread t2(work2, &sum);

    t1.join();
    t2.join();


    return EXIT_SUCCESS;
}