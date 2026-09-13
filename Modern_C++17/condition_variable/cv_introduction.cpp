#include<iostream>
#include<condition_variable>
#include<thread>
#include<mutex>

using namespace std;

condition_variable cv;


mutex m; 

bool ready = false;

void thread1(int* sum){
    for(int i = 1; i <= 10000; i++){
        (*sum) += i;
    }
    this_thread::sleep_for(chrono::seconds(10));
    {
        lock_guard<mutex> lock(m);
        ready = true;
    }
    cv.notify_one();
}

bool isReady(){
    return ready;
}

void thread2(int*sum){
    unique_lock<mutex> lock(m);

    cv.wait(lock , isReady);

    cout<<"T1 has finished its task\n";
    cout<<"The Sum Of 1 to 10000 Numbers is: "<<(*sum)<<'\n';

}

int main(){
    int sum = 0;

    thread t1(thread1, &sum);
    thread t2(thread2, &sum);

    t1.join();
    t2.join();


    return EXIT_SUCCESS;
}


/*
==================== CONDITION VARIABLE ====================

A condition_variable allows a thread to SLEEP instead of
continuously checking a condition (busy waiting).

Example problem:

    while(!ready) {
        // continuously checking -> wastes CPU
    }

Instead, a condition variable allows the thread to sleep
until another thread notifies it that something may have changed.

------------------------------------------------------------
1. BASIC COMPONENTS
------------------------------------------------------------

    mutex m;
    condition_variable cv;
    bool ready = false;

- mutex:
    Protects the shared variable "ready".

- ready:
    Represents the actual condition/state.
    In our program:
        ready == true  -> Thread 1 has finished.

- cv:
    Allows Thread 2 to sleep and Thread 1 to wake it.

IMPORTANT:
The condition_variable does NOT know what "ready" means.
We define the condition ourselves.

------------------------------------------------------------
2. cv.wait()
------------------------------------------------------------

    unique_lock<mutex> lock(m);

    cv.wait(lock, isReady);

This means:

    "Put this thread to sleep until the predicate
     (isReady) returns true."

If isReady() returns false:

    Thread sleeps.

If the thread is notified:

    Thread wakes up
        ↓
    checks isReady() again
        ↓
    if false -> waits again
    if true  -> continues

The predicate version is preferred:

    cv.wait(lock, isReady);

or:

    cv.wait(lock, [] {
        return ready;
    });

The lambda:

    [] {
        return ready;
    }

is simply a small unnamed function that tells wait()
whether the condition is currently satisfied.

------------------------------------------------------------
3. WHY "return ready"?
------------------------------------------------------------

    bool isReady() {
        return ready;
    }

"return ready" gives the condition_variable the answer
to the question:

    "Is the condition satisfied?"

If:

    ready = false;

isReady() returns false -> keep waiting.

If:

    ready = true;

isReady() returns true -> stop waiting and continue.

------------------------------------------------------------
4. IMPORTANT: isReady vs isReady()
------------------------------------------------------------

    cv.wait(lock, isReady);     // CORRECT

We pass the function itself so wait() can call it whenever
it needs to check the condition.

    cv.wait(lock, isReady());   // WRONG

The () means "call the function NOW" and pass its result.

So:

    isReady      -> give the function to wait()
    isReady()    -> execute the function immediately

------------------------------------------------------------
5. cv.notify_one()
------------------------------------------------------------

    cv.notify_one();

Means:

    "Wake up ONE thread that is currently waiting on cv."

It does NOT mean:

    "ready is now true."

These are two separate things.

    ready = true;       // Change the actual condition/state
    cv.notify_one();    // Wake a waiting thread

Typical pattern:

    {
        lock_guard<mutex> lock(m);
        ready = true;
    }

    cv.notify_one();

Thread 1 changes the condition and then tells Thread 2
that it should wake up and check the condition.

------------------------------------------------------------
6. cv.notify_all()
------------------------------------------------------------

    cv.notify_all();

Wakes ALL threads currently waiting on that condition variable.

notify_one() -> wake one
notify_all() -> wake all

------------------------------------------------------------
7. WHY DO WE NEED THE MUTEX?
------------------------------------------------------------

"ready" is shared between multiple threads.

Thread 1 writes:

    ready = true;

Thread 2 reads:

    ready

Without synchronization, this can cause a DATA RACE.

Therefore both threads use the same mutex when accessing
the shared state.

Thread 1:

    {
        lock_guard<mutex> lock(m);
        ready = true;
    }

Thread 2:

    unique_lock<mutex> lock(m);
    cv.wait(lock, isReady);

------------------------------------------------------------
8. WHY UNIQUE_LOCK IN cv.wait()?
------------------------------------------------------------

We cannot normally use lock_guard with wait() because
wait() needs to temporarily UNLOCK the mutex while the
thread is sleeping and LOCK it again when the thread wakes.

unique_lock supports this.

Conceptually:

    lock mutex
        ↓
    check condition
        ↓
    condition false
        ↓
    unlock mutex
        ↓
    sleep
        ↓
    notification
        ↓
    wake up
        ↓
    lock mutex again
        ↓
    check condition
        ↓
    condition true
        ↓
    continue

This is why:

    unique_lock<mutex> lock(m);

is used with:

    cv.wait(lock, predicate);

------------------------------------------------------------
9. CONDITION VARIABLE DOES NOT PERIODICALLY CHECK
------------------------------------------------------------

A condition variable is NOT:

    check
    sleep
    check
    sleep
    check...

That would just be slower busy waiting.

Instead:

    check condition
        ↓
    false
        ↓
    sleep indefinitely
        ↓
    another thread calls notify_one()
        ↓
    wake up
        ↓
    check condition again

The waiting thread does not continuously consume CPU
while waiting.

------------------------------------------------------------
10. OVERALL FLOW OF OUR PROGRAM
------------------------------------------------------------

Thread 2:

    lock mutex
        ↓
    cv.wait(lock, isReady)
        ↓
    ready == false
        ↓
    sleep

Thread 1:

    finish calculating
        ↓
    lock mutex
        ↓
    ready = true
        ↓
    unlock mutex
        ↓
    cv.notify_one()

Thread 2:

    wake up
        ↓
    lock mutex again
        ↓
    isReady() -> true
        ↓
    continue
        ↓
    print the result

------------------------------------------------------------
11. MOST IMPORTANT THINGS TO REMEMBER
------------------------------------------------------------

condition_variable:
    Allows threads to efficiently wait for a condition.

cv.wait(lock, predicate):
    Sleep until the predicate becomes true.
    The predicate is checked when needed.

cv.notify_one():
    Wake one waiting thread.

cv.notify_all():
    Wake all waiting threads.

mutex:
    Protects shared data/state.

unique_lock:
    Used with wait() because wait() must be able to
    unlock and re-lock the mutex.

ready:
    The actual condition/state in our program.

isReady:
    Function that tells wait() whether the condition
    is currently true.

isReady():
    Calls the function immediately.

isReady:
    Passes the function itself to wait().

MAIN IDEA:

    mutex          -> protects the shared state
    condition_variable -> lets threads sleep/wake
    predicate      -> tells whether the condition is satisfied
    notify_one()   -> wakes one waiting thread

============================================================
*/