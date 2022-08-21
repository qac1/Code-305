#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<string>  
using namespace std;  
  
string a, b;  
vector<int> c1, c2;  
int la, lb, lc;  
int ra, rb, rc;  
int lm, rm;  
bool fa, fb;  
  
int main() {  
    cin >> a >> b;  
    for (int i = 0; i < a.size(); i++) {  
        if (a[i] == '.') {  
            fa = true;  
            break;  
        }  
        la++;  
    }  
    ra = a.size() - 1 - la;  
    for (int i = 0; i < b.size(); i++) {  
        if (b[i] == '.') {  
            fb = true;  
            break;  
        }         
        lb++;  
    }  
    rb = b.size() - 1 - lb;  
    int t = 0;  
    //计算小数部分  
    t = 0;  
    for (int i = max(ra, rb); i > 0; i--) {  
        if (i <= ra) t += a[la + i] - '0';  
        if (i <= rb) t += b[lb + i] - '0';  
        c2.push_back(t % 10);  
        t /= 10;  
    }  
    //最高位的进位放到c1中  
    //if (t)c1.back() += 1;  
    reverse(c2.begin(), c2.end());  
    rc = c2.size();  
    //计算整数部分  
    for (int i = 1; la - i >= 0|| lb - i >= 0; i++) {  
        if (la - i >= 0) t += a[la - i]-'0';  
        if (lb - i >= 0) t += b[lb - i]-'0';  
        c1.push_back(t % 10);  
        t /= 10;  
    }  
    if (t)c1.push_back(t);  
    //除前导0  
    while (c1.size()>1 && c1.back() == 0)c1.pop_back();  
    reverse(c1.begin(), c1.end());  
    lc = c1.size();  
    /*//计算小数部分 
    t = 0; 
    for (int i =max(ra,rb); i>0; i--) { 
        if (i<=ra) t += a[la+i]-'0'; 
        if (i<=rb) t += b[lb+i]-'0'; 
        c2.push_back(t % 10); 
        t /= 10; 
    } 
    //最高位的进位放到c1中 
    if (t)c1.back() += 1; 
    reverse(c2.begin(), c2.end()); 
    rc = c2.size();*/  
    //输出  
    lm = max(la, lb);  
    lm = max(lm, lc);  
    rm = max(ra, rb);  
    rm = max(rm, rc);  
    lm += 3;  
    //第一行  
    for (int i = 0; i < lm - la; i++) cout << ' ';  
    cout << a;  
    for (int i = 0; i < rm-ra; i++) cout << ' ';  
    cout << endl;  
    //第二行  
    cout << "+";  
    for (int i = 1; i < lm - lb; i++) cout << ' ';  
    cout << b;  
    for (int i = 0; i < rm - rb; i++) cout << ' ';  
    cout << endl;  
    //第三行  
    for (int i = 0; i < lm + rm + 1; i++) cout << '-';  
    cout << endl;  
    //第四行  
    for (int i = 0; i < lm - lc; i++) cout << ' ';  
    for (int i = 0; i < c1.size(); i++) cout << c1[i];  
    if(fa||fb)cout << '.';  
    for (int i = 0; i < c2.size(); i++) cout << c2[i];  
    for (int i = 0; i < rm - rc; i++) cout << ' ';  
    cout << endl;  
    return 0;  
}  
