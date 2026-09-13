#include <iostream>
#include <vector>
using namespace std;



int main(){
    vector <int> nums = {2,7,8,11,4,2,1};
    int target{15};
    vector<int> ans;
    //Brute force approach pair_sum;

    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    for(int i = 0; i<=1; i++){
        cout<<ans[i]<<" ";
    }




    return 0;
}