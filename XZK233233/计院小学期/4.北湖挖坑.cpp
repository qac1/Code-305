#include<iostream>  
#include<algorithm>  
using namespace std;  
  
const int N = 100010;  
long long h[N];  
long long n;  
long long height;  
  
  
int main() {  
    cin >> n >> height;  
    for (long long i = 1; i <= n; i++) {  
        cin >> h[i];  
        h[i] = height - h[i];  
    }  
    long long ans = h[1];  
    for (long long i =2; i<=n; i++) {  
        if (h[i] > h[i - 1]) ans += h[i] - h[i - 1];  
    }  
    cout << ans << endl;  
    return 0;  
}  
