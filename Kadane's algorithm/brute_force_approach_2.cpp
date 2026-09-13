#include<iostream>
#include<vector>
using namespace std;



int main(){
    vector<int> nums = {1,2,-3,-5,8,-1};
    int max_sum = INT_MIN;
    int current_sum = 0;

    for(int start = 0; start<nums.size(); start++){
        for(int end = start; end<nums.size(); end++){
            current_sum += nums[end];
            max_sum = max(current_sum, max_sum);

        }
        current_sum = 0;
        
    }

    cout<<"The maximum subarray sum is: "<<max_sum<<'\n';



    return 0;
}