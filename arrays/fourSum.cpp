#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, long long target) {
    if (nums.size() < 4)
        return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        for (int i = 0; i < nums.size()-3; i++)
        {
            if (i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            
            for (int j = i+1; j < nums.size()-2; j++)
            {
                if((j>i+1)&&(nums[j]==nums[j-1]))continue;

                int k=j+1;
                int l=nums.size()-1;
                while (k<l)
                {
                    long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum==target)
                    {
                        solution.push_back({nums[i], nums[j], nums[k], nums[l]});k++;l--;
                        while (k<l&&nums[k]==nums[k-1])
                        {
                            k++;
                        }
                        while (k<l&&nums[l]==nums[l+1])
                        {
                            l--;
                        }
                               
                    }
                    else if(sum<target){k++;}
                    else{l--;};
                    
                }
                
            }
            
        }
        return solution;
    }

int main() {
    int size;
    long long target;
    cin >>size>>target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = fourSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}