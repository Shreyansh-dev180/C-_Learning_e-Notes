#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/* For counting all primes within a range we can use SIEVE OF ERATHONES
Algo in this we assume all the numbers in from 0 to n are prime and
we start a loop till n starting from 2 now if for each value of i we
check if ith value is prime if yes then count++ and then a loop 
again till i's multiple less than n for keeping all multiples 
of i to false means non prime*/

int countPrime(int num){
    int count{0};
    vector<bool> state(num+1,true); //num+1 because 0 to n not 1 to n;

    for(int i = 2; i <= num; i++){
        if(state[i]){
            count++;
            for(int j = i*2; j <= num ; j+=i){//i = 2 , j=4; next 4+i = j=4+2;
                state[j] = false;
            }
        }
    }
    return count;

}

int main(){ 
    int n = 10;
    cout<<countPrime(n) <<'\n';
    


    return EXIT_SUCCESS;
}