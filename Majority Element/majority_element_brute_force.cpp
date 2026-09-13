#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3, 3, 4};
    // Expected Output: The majority element is: 3
    int n = nums.size();
    int ans{};

    for (int i = 0; i < n; i++)
    {
        int frequency = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                frequency += 1;
            }
        }
        if (frequency > n / 2)
        {
            ans += nums[i];
        }
    }

    cout << "the majority element is: " << ans << '\n';

    return 0;
}