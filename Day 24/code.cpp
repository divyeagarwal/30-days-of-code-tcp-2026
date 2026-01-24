#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        long long n, d;
        cin >> n >> d;
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for(int i = 0; i < n; ) {
            long long leader = a[i];
            long long max_size = 1 + d / leader;
            long long team_size = min(max_size, (long long)(n - i));
            if(team_size >= 1) {
                ans++;
                i += team_size;
            } else {
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
