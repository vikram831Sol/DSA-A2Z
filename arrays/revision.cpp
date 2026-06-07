#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> solution;
    for (int i = 0; i < nums.size(); i++){
        if((i>0)&&nums[i]==nums[i-1])continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                solution.push_back({nums[i], nums[j], nums[k]});j++;k--;
                while ((j<k)&&(nums[j] == nums[j - 1])) {
                    j++;
                }
                while ((j<k)&&(nums[k - 1] == nums[k])) {
                    k--;
                }
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    return solution;
}

int main() {
    int size;
    cin >>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}