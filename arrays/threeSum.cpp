#include <bits/stdc++.h>
using namespace std;

// Brute force approach O(n^3logn) O(n^2)
//  vector<vector<int>> threeSum(vector<int>& nums) {
//      set<vector<int>> result;
//      for (int i = 0; i < nums.size(); i++) {
//          for (int j = i+1; j < nums.size(); j++) {
//              for (int k = j+1; k < nums.size(); k++) {
//                  if (nums[i]+nums[j]+nums[k]==0)
//                  {
//                      vector<int> temp={nums[i], nums[j], nums[k]};
//                      sort(temp.begin(), temp.end());
//                      result.insert(temp);
//                  }
//              }
//          }
//      }
//      vector<vector<int>> ans(result.begin(), result.end());
//      return ans;
//  }

// better approach
//  vector<vector<int>> threeSum(vector<int>& nums) {
//      set<vector<int>> st;
//       for (int i = 0; i < nums.size(); i++)
//       {
//          set<int> hashmap;
//          for (int j = i+1; j < nums.size(); j++)
//          {
//              int sum=-(nums[i]+nums[j]);
//              if (hashmap.find(sum)!=hashmap.end())
//              {
//                  vector<int> temp={nums[i], nums[j], sum};
//                  sort(temp.begin(), temp.end());
//                  st.insert(temp);
//              }

//             hashmap.insert(nums[j]);

//         }

//      }
//      vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
                
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && (nums[j] == nums[j - 1])) {
                    j++;
                }
                while (j < k && (nums[k] == nums[k - 1])) {
                    k--;
                }
            }
        }
    }

    return result;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}