#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<int> nums = {1,4,8,2,6,10,7};
    int target(8);
    int ans{};
    
    int start = 0;
    int end = nums.size() - 1;

    //Sort the array first
    sort(nums.begin(), nums.end());

    while(start <= end){ //both can point to same index.
        //used to avoid int overflow because in worst case INT_MAX+INT_MAX will fail.
        int mid = start + (end - start) / 2; //same to (start+end)/2 

        if(nums[mid] == target){ //if mid value is the target then best case return it.
            ans = mid;
            break;
        }
        /*if mid value is greater than target means all right
        side values will be also greater than our target so no need 
        to search there so set end to mid-1*/
        else if(nums[mid] > target){
            end = mid-1;
        }
        /*if mid value is small than target means all left values of 
        mid are also small than target so we need to search to right so 
        we move our start to mid+1*/
        else if(nums[mid] < target){
            start = mid+1;
        }
    }

    for(auto x: nums){
        cout<<x<<",";
    }
    cout<<"\n";
    cout<<"The target is at index: "<<ans<<"\n";


    return 0;
}