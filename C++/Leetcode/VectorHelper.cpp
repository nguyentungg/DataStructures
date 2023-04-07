#include"VectorHelper.h"
#include<iostream>

int VectorHelper::GetIndex(vector<int> nums, int number)
{
    vector<int>::iterator itr = find(nums.begin(), nums.end(), 2);
    auto result = 0;
    if (itr != nums.cend())
    {
        cout << "Element present at index " << distance(nums.begin(), itr);
        result = distance(nums.begin(), itr);
    }
    else
    {
        cout << "Element not found";
        result = -1;
    }
    return result;
}

int VectorHelper::GetIndexOther(vector<int> nums, int number)
{
    for (auto i = nums.begin(); i != nums.end(); ++i)
    {
        cout << "I am at position: " << i - nums.begin() << endl;
        cout << "contents here is: " << *i << endl;
    }
}