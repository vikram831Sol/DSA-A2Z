#include <bits/stdc++.h>
using namespace std;
//TC--->o(n+m)
//SC--->o(n+m)
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, k=0;
        vector<int> temp;
        
        while(i<nums1.size() && j<nums2.size()){
            if (nums1[i]<nums2[j])
            {
                if(temp.empty()){
                temp.push_back(nums1[i]);i++;
                }
                else{
                    if(temp.back()!=nums1[i]){
                        temp.push_back(nums1[i]);i++;
                    }
                    else{i++;}
                }
            }
            else if (nums1[i]>nums2[j])
            {
                if(temp.empty()){
                temp.push_back(nums2[j]);j++;
                }
                else{
                    if(temp.back()!=nums2[j]){
                        temp.push_back(nums2[j]);j++;
                    }
                    else{j++;}
                }
            }
            else
            {
                if(temp.empty()){
                temp.push_back(nums1[i]);i++;j++;
                }
                else{
                    if(temp.back()!=nums2[j]){
                        temp.push_back(nums2[j]);j++;i++;
                    }
                    else{i++;j++;}
                }
            }
            
        }
        while(i<nums1.size()){
            if(temp.empty()){
                temp.push_back(nums1[i]);i++;
            }
            else{
                    if(temp.back()!=nums1[i]){
                        temp.push_back(nums1[i]);i++;
                    }
                    else{i++;}
                }
        }
        while(j<nums2.size()){
            if(temp.empty()){
                temp.push_back(nums2[j]);j++;
            }
            else{
                    if(temp.back()!=nums2[j]){
                        temp.push_back(nums2[j]);j++;
                    }
                    else{j++;}
                }
        }
        return temp;
    }


//much cleaner version of code--->
/*
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

    int i = 0, j = 0;
    vector<int> temp;

    while(i < nums1.size() && j < nums2.size()) {

        int val;

        if(nums1[i] < nums2[j]) {
            val = nums1[i++];
        }
        else if(nums1[i] > nums2[j]) {
            val = nums2[j++];
        }
        else {
            val = nums1[i];
            i++;
            j++;
        }

        if(temp.empty() || temp.back() != val) {
            temp.push_back(val);
        }
    }

    while(i < nums1.size()) {

        if(temp.empty() || temp.back() != nums1[i]) {
            temp.push_back(nums1[i]);
        }

        i++;
    }

    while(j < nums2.size()) {

        if(temp.empty() || temp.back() != nums2[j]) {
            temp.push_back(nums2[j]);
        }

        j++;
    }

    return temp;
}
*/

int main()
{
    int size1, size2;
    cin>>size1;
    cin>>size2;
    vector<int> nums1(size1), nums2(size2);
    for (int i = 0; i < size1; i++)
    {
        cin>>nums1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        cin>>nums2[i];
    }

    vector<int> result=unionArray(nums1, nums2);
    for(auto it:result){
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}