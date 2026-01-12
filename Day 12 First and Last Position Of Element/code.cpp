class Solution {
public:
    int first(vector<int> &arr,int n,int target){
        int first=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                first=mid;
                high=mid-1;
            }else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    int last(vector<int> &arr,int n,int target){
        int last=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                last=mid;
                low=mid+1;
            }else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        int first1=first(nums,n,target);
        if(first1==-1){
            ans.push_back(-1);
            ans.push_back(-1);
        }else {
            ans.push_back(first1);
            int last1=last(nums,n,target);
            ans.push_back(last1);
        }
        return ans;
        
    }
};