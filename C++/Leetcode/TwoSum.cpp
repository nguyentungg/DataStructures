#include <iostream>
#include <vector>
#include <algorithm>
#include "TwoSum.h"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]) > 0)
        {
            v.push_back(m[target - nums[i]]);
            v.push_back(i);

            return v;
        }
        m[nums[i]] = i;
    }
    return v;
}