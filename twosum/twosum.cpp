#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::vector;
using std::unordered_map;

 vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> sums;

    for(int i=0;;++i){
        auto it = sums.find(target - nums[i]);

        if(it != sums.end()){
            return vector<int> {it->second,i};
        }

        sums[nums[i]] = i;
    }
    return {};
 }



int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> res = twoSum(nums, target);

    cout << '[' << res[0] << ", " << res[1] << ']';

    return 0;
}