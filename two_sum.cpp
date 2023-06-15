#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    vector<int> ans;
    
    map<int, int> hash, indices;
    int remaining;
    for (int i=0; i<nums.size(); i++){
        hash[nums[i]] = 1;
        indices[nums[i]] = i;
    }

    for (int i=0; i<nums.size(); i++){
        remaining = target-nums[i];
        if (hash[remaining] & (indices[remaining] != i)){
            ans.push_back(i);
            ans.push_back(indices[remaining]);
            break;
        }
    }

    return ans;
    }

int main() {
    
    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    std::vector<int> ans = twoSum(nums, target);

    for(int index: ans){
        std::cout << index << ", ";
    }
    
}