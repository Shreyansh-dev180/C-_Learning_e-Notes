#include<iostream>
#include<vector>
using namespace std;

// We simply avoid the negative numbers so that the main subarray will be 
// automatically filtered out 

int main(){
    vector<int> nums = {1,-2,-4,5,7,-1,-2};
    int max_sum = INT_MIN;
    int current_sum = 0;

    for(int i=0; i<nums.size(); i++){
        current_sum+= nums[i];
        max_sum = max(max_sum , current_sum);
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    /*first we compare current_sum with max_sum before resetting current sum 
    to negative because if all the values in array is negative  then 
    answer will always zero so to avoid this we first compare the both values
    and after the max_value updated then we check current sum resseting.*/

    cout<<"The maximum subarray sum is: "<<max_sum<<'\n';

    


    return 0;
}