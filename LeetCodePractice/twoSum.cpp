// problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;

        for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];

            if (numIndices.find(complement) != numIndices.end()){
                return {numIndices[complement], i};
            }
        }



       
        
    }
};