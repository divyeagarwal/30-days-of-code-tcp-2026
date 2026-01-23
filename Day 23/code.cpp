class Solution {
public:
    string frequencySort(string s) {
        map<int,int> mp;
        auto cmp = [](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second; 
        };
         for(char c : s){
            mp[c]++;
         }
         vector<pair<char,int>> vec(mp.begin(),mp.end());
         sort(vec.begin(),vec.end(),cmp); 
         string ans = "";

         for(const auto& i : vec){ 
            ans.append(i.second,i.first); 
         }
         return ans;
    }
};