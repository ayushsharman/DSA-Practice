#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int size = 6;

    sort(nums, nums + size);
    int target = 0;

    for (int i = 0; i < size - 2; i++)
    {
        int low = i + 1;
        int high = size - 1;

        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];
            cout << sum << endl;
            if (sum < target)
            {
                low++;
            }
            else if (sum > target)
            {
                high--;
            }
            else
            {
                // Found a triplet that sums to zero
                cout << nums[i] << " " << nums[low] << " " << nums[high] << endl;
                low++;
                high--;
                // Skip duplicates for low
                while (low < high && nums[low] == nums[low - 1])
                {
                    low++;
                }
                // Skip duplicates for high
                while (low < high && nums[high] == nums[high + 1])
                {
                    high--;
                }
            }
        }

        // Skip duplicates for i
        while (i < size - 2 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }

    return 0;
}
