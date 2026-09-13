#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<int> nums = {2,7,8,11,4,2,1};
    int target{6};
    int i = 0;
    int j = nums.size() - 1;
    vector<int> ans;

    //Sort the vector first->
    sort(nums.begin(), nums.end());

    while(i<j){
        int pair_sum = nums[i] + nums[j];

        if(pair_sum > target){
            j--;
        }
        else if(pair_sum < target){
            i++;
        }
        else if(pair_sum == target){
            ans.push_back(i);
            ans.push_back(j);
            break;
        }
        else{
            return -1;
        }
    }

    for(int val: ans){
        cout<<val<<" ";
    }

    



    return 0;
}