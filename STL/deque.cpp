#include<iostream>
#include<deque>
using namespace std;

/*Deque is very similar to list deque is double ended tree
means it also has both ends accessibles push at front and end
emplace at both and pop at both ends 

one major difference is that in deque we can access specific index
like using d.begin()+1,2,3,...n or by d[idx] or d.at[idx]*/

int main(){
    //most functions are same as list so we see only unique functions
    //1. insertion at specific idx and using d[] and d.at() 
    //rest things are same as list so you can visit there;
    deque<int> d;

    d.push_back(1); //d = {1};
    d.emplace_back(2); //d = {1,2};
    d.push_front(0); //d = {0,1,2};
    d.emplace_front(-1); //d = {-1,0,1,2};

    //insert value at idx 2;
    d.insert(d.begin()+2 , 0); //d = {-1,0,0,1,2};

    cout<<"Value at index 2 is: "<<d[2]<<'\n';
    cout<<"Value at index 3 is: "<<d.at(3)<<'\n';

}