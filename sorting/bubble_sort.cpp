#include<iostream>
#include<vector>
using namespace std;

/*Bubble sort is a way to sort a container with int values in 
acesding or decending order by comparing the adjacent values 
we use nested loops o(n^2) thats why each time the inner loop runs
the largest value got pushed to the end 
by continuosly doing it eventually we sort the container in acending order
vice versa for decending order.*/

auto ascending_sort(vector<int>& nums){

    for(int i=0; i<nums.size(); i++){
        for(int j = 1; j<nums.size(); j++){
            if(nums[j-1] > nums[j]){
                swap(nums[j-1], nums[j]);
            }
        }
    }
}


auto decending_sort(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        for(int j = 1; j<nums.size(); j++){
            if(nums[j-1] < nums[j]){
                swap(nums[j-1], nums[j]);
            }
        }
    }

}

int main(){
    vector<int> nums = {4,2,3,1,6,7,2};
    vector<int> nums1 = {4,11,7,5,6,8,2};

    ascending_sort(nums);

    decending_sort(nums1);

    for(auto num: nums){
        cout<<num<<" ";
    }
    cout<<'\n';
    

    for(auto num: nums1){
        cout<<num<<" ";
    }
    cout<<'\n';





    return 0;
}