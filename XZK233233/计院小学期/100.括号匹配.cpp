#include<iostream>      
#include<algorithm>      
#include<stack>     
using namespace std;  
  
const int N = 1e5 + 100;  
stack<char> a;  
//记录每一字符串的左括号和右括号个数    
int l;  
int r;  
int ml[N];  
int mr[N];  
int n;  
int sum;  
  
void input(int i) {  
    for (int j = 0;; j++) {  
        //吸收回车字符  
        char ch = getchar();  
        //去除已经成对的  
        if (ch == '\n') break;  
        if (!a.empty()&&a.top() == '(' && ch == ')') a.pop();  
        else a.push(ch);  
    }  
    l = r = 0;  
    //判断类型  
    if (!a.empty() && a.top() == ')') r = a.size();  
    else while(!a.empty()) {  
        if (a.top() != '(') return;  
        l++;  
        a.pop();  
    }  
    if (r == 0) ml[l] ++;  
    if (l == 0) mr[r]++;  
    if (l == r) sum++;  
    return;  
}  
  
  
int main() {  
    //输入部分  
    cin >> n;  
    //吸收回车字符  
    char t = getchar();  
    for (int i = 0; i < n; i++) {  
        input(i);  
        while (!a.empty()) a.pop();  
    }  
    //输出部分  
    sum /= 2;  
    for (int i = 1; i < N; i++) {  
        sum += min(ml[i], mr[i]);  
    }  
    cout << sum << endl;  
    return 0;  
}  
