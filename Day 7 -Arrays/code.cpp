#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            int maxi=0;
            int base=0;
            int temp = num;
            for(int x=temp;x>0;x/=10 ){
                maxi=max(maxi,x%10);
            }
            for(int x=num;x>0;x/=10 ){
                base= base*10 +1;
            }
            ans+=base*maxi;
        }
        return ans;
    }
};

int main() {
    // Test case 1: [1,2,3] -> 6
    vector<int> nums1 = {1,2,3};
    cout << Solution().sumOfEncryptedInt(nums1) << endl;  // Expected: 6

    // Test case 2: [10,21,31] -> 66
    vector<int> nums2 = {10,21,31};
    cout << Solution().sumOfEncryptedInt(nums2) << endl;  // Expected: 66
    
    return 0;
}
