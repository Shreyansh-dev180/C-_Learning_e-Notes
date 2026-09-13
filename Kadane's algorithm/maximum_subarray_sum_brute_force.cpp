#include<iostream>
using namespace std;

// Continuous part of array is called subarray;
int main(){
    int array[7]={3,-4,5,4,-1,7,-8};
    int n = sizeof(array)/sizeof(array[1]);
    int max_sum= INT_MIN;
    int temproary_sum{};
    // Printing all subarrays;
    //BruteForce;
    for(int start = 0; start<n; start++){//start from 0th index 
        for(int end = start ; end<n ; end++){//end will move till last index 
            for(int i = start; i<=end; i++){
                temproary_sum+=array[i];
            }
            if(temproary_sum > max_sum){
                max_sum = temproary_sum;
            }
            temproary_sum = 0;
        }
        
    }
    cout<<max_sum<<'\n';//ANS: 15;

    return 0;
}