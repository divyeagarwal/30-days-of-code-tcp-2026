class Solution {
  public:
    void merge(vector<int>& arr ,int low,int mid,int high){
        int left=low,right=mid+1;
        vector<int> temp;
        while(left<=mid && right <=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return ;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};