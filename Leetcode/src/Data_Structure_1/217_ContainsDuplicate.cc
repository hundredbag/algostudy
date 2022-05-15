#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time : O(N), Space : O(N)
    bool containsDuplicate1(vector<int>& nums) {
        std::unordered_set<int> s;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            auto it = s.find(nums[i]);
            if (it == s.end()) {
                s.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }

    // Time : O(N), Space : O(N)
    bool containsDuplicate2(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        return nums.size() != s.size();
    }

    // Time : O(NlogN) , Space : O(1)
    bool containsDuplicate3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> input = {1,1,1,3,3,4,3,2,4,2};

    Solution s1;
    cout << s1.containsDuplicate1(input) << endl;
    cout << s1.containsDuplicate2(input) << endl;
    cout << s1.containsDuplicate3(input) << endl;

    return 0;
}