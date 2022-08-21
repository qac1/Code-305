#include<iostream>  
#include<algorithm>  
using namespace std;  
  
const int N = 3010;  
int n, v;  
//在第a天有b颗果子成熟  
int a[N], b[N];  
//记录在第i天有多少果子成熟  
int t[N];  
//摘到的果子总数  
int sum;  
  
int main() {  
    cin >> n >> v;  
    int end=0;//找到结束的一天  
    for (int i = 1; i <= n; i++) {  
        cin >> a[i]>>b[i];  
        t[a[i]] += b[i];  
        end = max(end, a[i]);  
    }  
    for (int i = 1; i <= end+1; i++) {  
        //每日的体力值  
        int day = v;  
        //处理前一天的果子  
        if (t[i - 1] != 0) {  
            if (t[i - 1] >= day) {  
                sum += day;  
                continue;  
            }  
            else {  
                sum += t[i - 1];  
                day -= t[i - 1];  
            }  
        }  
        //处理今天的果子  
        if (day >= t[i]) {  
            sum += t[i];  
            t[i] = 0;  
        }  
        else {  
            sum += day;  
            t[i] -= day;  
        }  
    }  
    cout << sum << endl;  
    return 0;  
}  
跳至...
