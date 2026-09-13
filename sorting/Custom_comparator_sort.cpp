#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*We can define our own comparators for defining how we want to sort our container
we will take example of vector pairs in which our target is to sort it according
to its second value which is frequency and if frequency of two elements are same then
sort the first values in decreasing order */

bool comparator(const pair<int, int> p1, const pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if(p1.second > p2.second){
        return false;
    }

    else{
        if(p1.first > p2.first){
            return true;
        }
        else{
            return false;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 1, 1, 3, 3};
    unordered_map<int, int> freq;

    for (auto num : nums)
    {
        freq[num]++;
    }

    vector<pair<int, int>> pairs;

    for (auto p : freq)
    {
        pairs.push_back({p.first,p.second});
    }

    sort(pairs.begin(), pairs.end(), comparator);

    for(auto p: pairs){
        cout<<p.first<<" "<<p.second;
    }
    cout<<'\n';

    return EXIT_SUCCESS;
}
