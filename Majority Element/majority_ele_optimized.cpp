#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;



int main(){
    vector<int> nums = {1, 2, 3, 3, 3, 3, 4};
    // Expected Output: The majority element is: 3
    int n = nums.size();
    int ans{nums[0]};
    sort(nums.begin(), nums.end());
    int freq{1};

    for(int i=1; i<n; i++){
        if(freq>n/2){
            cout<<"The majority element is: "<<ans<<'\n';
            break;

        }
        
        if(nums[i] == nums[i-1]){
            freq++;
        }
        
        else{
            freq = 1;
            ans = nums[i];
        }

    }





    return 0;
}
