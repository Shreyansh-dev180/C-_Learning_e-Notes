#include<iostream>
using namespace std;

// Continuous part of array is called subarray;
int main(){
    int array[5]={1,2,3,4,5};
    int n = sizeof(array)/sizeof(array[1]);
    
    // Printing all subarrays;
    //BruteForce;
    for(int start = 0; start<n; start++){//start from 0th index 
        for(int end = start ; end<n ; end++){//end will move till last index 
            for(int i = start; i<=end; i++){
                cout<<array[i];
            }
            cout<<" ";
        }
        cout<<'\n';
    }

    return 0;
}