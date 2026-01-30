class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < n && j < m) {
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                res.push_back(a[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
