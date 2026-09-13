#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int is_target_exists(vector<int> nums, int st, int end, int target){
    if(st > end){
        return -1;
    }
    int mid = st + (end - st)/2;
    if(nums[mid] == target) return mid;

    else if(nums[mid] > target){
        return is_target_exists(nums, st, mid-1, target);
    }
    else{
        return is_target_exists(nums, mid+1, end, target);
    }

}

int main(){
    vector<int> nums = {12,3,4,52,5,2};
    int n = nums.size();
    int st = 0;
    int end = n-1;
    int target;
    cout<<"Enter the target: ";
    cin>>target;

    sort(nums.begin(), nums.end());
    
    cout<<"Your target is at index: "<<is_target_exists(nums, st, end, target)<<'\n';



    return EXIT_SUCCESS;
}