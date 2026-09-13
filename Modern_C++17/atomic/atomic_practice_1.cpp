#include<iostream>
#include<thread>
#include<atomic>
using namespace std;


void thread1(atomic<int>* count){
    for(int i = 1; i<=1000000; i++){
        (*count)++;
    }
}

void thread2(atomic<int> *nums){
    for(int i = 1; i<=1000000; i++){
        (*nums)++;
    }
}


int main(){
    atomic<int> counter = 0;

    thread t1(thread1, &counter);
    thread t2(thread2, &counter);

    t1.join();
    t2.join();

    cout<<"Counter = "<<counter<<'\n';

    return EXIT_SUCCESS;
}



/*
==================== std::atomic ====================

std::atomic provides thread-safe operations on a shared
variable without needing a mutex for those operations.

    atomic<int> counter = 0;
    atomic<bool> ready = false;

Multiple threads can safely read/write/modify the same
atomic variable.

Example:

    counter++;

With a normal int, multiple threads doing counter++ can
cause a data race because the operation involves
read -> modify -> write.

With atomic<int>, the operation is performed atomically,
so threads cannot corrupt each other's atomic operation.

-------------------------------------------------------

ATOMIC vs MUTEX

atomic:
    -> Safely performs individual operations on a shared
       atomic variable.
    -> Often uses CPU hardware atomic instructions.
    -> Good for simple shared state/counters/flags.

mutex:
    -> Protects a larger critical section.
    -> Useful when multiple variables/operations must
       be treated as one unit.

IMPORTANT:

atomic does NOT mean "tiny mutex".
They are different synchronization mechanisms.

condition_variable:
    -> Allows a thread to sleep until something happens.

atomic:
    -> Makes operations on the atomic object thread-safe.

sleep_for():
    -> Only changes thread timing.
    -> Does NOT prevent data races.

Example:

    atomic<int> counter = 0;

    void work(atomic<int>* counter) {
        for(int i = 0; i < 1000000; i++)
            (*counter)++;
    }

Two threads can safely modify the same counter.

-------------------------------------------------------

IMPORTANT:
atomic does not guarantee that an entire sequence of
multiple operations is atomic.

For complex related operations, a mutex may still be
required.

========================================================
*/