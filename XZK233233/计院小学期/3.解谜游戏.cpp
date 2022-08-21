#include<iostream>  
#include<algorithm>    
using namespace std;  
  
const int N = 20;  
int a[N][N];  
int b[N][N];  
int dx[4] = { -1,0,1,0 };  
int dy[4] = { 0,-1,0,1 };  
int nx, ny;  
int n, m;  
int ans,num;  
int ret=256;  
  
//反转a中的棋子  
void rev(int i,int j) {  
    if (a[i][j] == 1) a[i][j] = 0;  
    else a[i][j] = 1;  
}  
//反转b中的棋子  
void revb(int i, int j) {  
    if (b[i][j] == 1) b[i][j] = 0;  
    else b[i][j] = 1;  
}  
//检查是否完成  
bool check() {  
    for (int i = 1; i <= m; i++) {  
        if (b[n][i] == 1) return false;  
    }  
    return true;  
}  
//按下a中的按钮  
void fun(int x, int y) {  
    rev(x, y);  
    for (int i = 0; i < 4; i++) {  
        nx = x + dx[i];  
        ny = y + dy[i];  
        if (nx > 0 && ny > 0 && nx <= n && ny <= m) {  
            rev(nx, ny);  
        }  
    }  
}  
//按下b中的按钮  
void funb(int x, int y) {  
    revb(x, y);  
    for (int i = 0; i < 4; i++) {  
        nx = x + dx[i];  
        ny = y + dy[i];  
        if (nx > 0 && ny > 0 && nx <= n && ny <= m) {  
            revb(nx, ny);  
        }  
    }  
}  
//对第一行进行dfs  
void dfs(int u) {  
    if (u == m+1) {  
        //复制a数组到b中，方便回溯  
        for (int i = 1; i <= n; i++) {  
            for (int j = 1; j <= m; j++) {  
                b[i][j] = a[i][j];  
            }  
        }  
        //处理下面几行  
        for (int i = 2; i <= n; i++) {  
            for (int j = 1; j <= m; j++) {  
                if (b[i - 1][j] == 1) {  
                    funb(i, j);  
                    num++;  
                }  
            }  
        }  
        if (check()) ret = min(ans+num, ret);  
        num = 0;  
        return;  
    }  
    //按  
    ans++;  
    fun(1, u);  
    dfs(u + 1);  
    //不按（按两次）  
    ans--;  
    fun(1, u);  
    dfs(u+1);  
}  
  
int main() {  
    cin >> n >> m;  
    for (int i = 1; i <= n; i++) {  
        long long t;  
        cin >> t;  
        for (int j = m; j > 0; j--) {  
            a[i][j] = t % 10;  
            t /= 10;  
        }  
    }  
    dfs(1);  
    cout << ret << endl;  
}  
