#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
  
const int N = 100010;  
long long a[N];  
long long l[N], r[N];  
long long n;  
long long ans;  
bool st[N];  
  
int main() {  
    int t;  
    cin >> t;  
    while (t--) {  
        //重新初始化  
        ans = 0;  
        n = 0;  
        memset(a, 0, sizeof a);  
        memset(l, 0, sizeof l);  
        memset(r, 0, sizeof r);  
        memset(st, false, sizeof st);  
  
        scanf("%lld", &n);  
        for (int i = 1; i <= n; i++) {  
            scanf("%lld", &a[i]);  
            if (a[l[i - 1]] > a[i - 1]) {  
                l[i] = l[i - 1];  
            }  
            else l[i] = i - 1;  
            st[l[i]] = true;  
        }  
        for (int i = n; i > 0; i--) {  
            if (a[r[i + 1]] > a[i + 1]) {  
                r[i] = r[i + 1];  
            }  
            else r[i] = i + 1;  
            st[r[i]] = true;  
        }  
        //最两侧不可能蓄水  
        //高柱子不蓄水  
        for (int i = 2; i < n; i++) {  
            if (!st[i]) ans += min(a[l[i]], a[r[i]])- a[i];  
        }  
        cout << ans << endl;  
    }  
      
    return 0;  
}  
