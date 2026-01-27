#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long sum = 0;
    for(int i = 0; i < k; i++) {
        sum += a[i];
    }
    
    double total = sum;
    for(int i = 1; i <= n - k; i++) {
        sum = sum - a[i-1] + a[i + k - 1];
        total += sum;
    }
    
    printf("%.12f\n", total / (n - k + 1));
    return 0;
}
