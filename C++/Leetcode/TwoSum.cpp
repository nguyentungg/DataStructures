#include <iostream>
#include <vector>
#include <algorithm>
#include "TwoSum.h"

using namespace std;

int main()
{
    vector<int> nums = {2, 7, 11, 15};

    // for(const int& i : nums){

    // }

    // for(auto i = nums.begin(); i != nums.end(); ++i){

    // }

   

    system("pause");
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {2,7,11,15};
    vector<int> filter;
    int target = 9;
    for(int i = 0; i < nums.size(); ++i){
        if(target < nums[i]){
        
            continue;
        }
        int result = target - nums[i];
        if (find(filter.begin(), filter.end(), result) == filter.end()) {
            
            cout << "Element not found ";
            cout << "nums: " << nums[i] << endl;
            cout << "result: " << result << endl;
            nums.erase(nums.begin());
            // filter.push_back(nums[i]);
            // filter.push_back(result);
        }
    }
    
    
    
    
    for(const int& i : nums){
        cout << i << " ";
    }
    
    // vector<int>::iterator itr = find(nums.begin(), nums.end(), 2);
 
    // if (itr != nums.cend()) {
    //     cout << "Element present at index " << distance(nums.begin(), itr);
    // }
    // else {
    //     cout << "Element not found";
    // }

    return 0;
}
