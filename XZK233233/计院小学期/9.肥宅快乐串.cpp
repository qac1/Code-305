#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<string>  
using namespace std;  
  
int n;  
int l, r=9;  
string a;  
string b = "fattyhappy";  
  
bool check_same() {  
    int i;  
    bool flag = true;  
    for (i = 0; i <= 9; i++) {  
        if (a[l + i] != b[i]) {  
            flag = false;  
            break;  
        }  
    }  
    if (flag) {  
        cout << l + 3 << ' ' << l + 4 << endl;  
        return true;  
    }  
    return false;  
}  
  
//内部两个字母交换  
bool check_inside() {  
    int sum = 0;  
    int x, y;  
    for (int i = 0; i <= 9; i++) {  
        if (a[l + i] != b[i]) {  
            sum++;  
            if (sum == 1)x = i;  
            if (sum == 2)y = i;  
        }  
    }  
    //内部可以交换  
    if (sum == 2 && b[x] == a[y+l] && a[x+l] == b[y]) {  
        x+=l+1;  
        y+=l+1;  
        cout << x << ' ' << y << endl;  
        return true;  
    }  
    return false;  
}  
//内部和外部的字母交换  
bool check_outside() {  
    int sum = 0;  
    int x;  
    for (int i = 0; i <= 9; i++) {  
        if (a[l + i] != b[i]) {  
            sum++;  
            if (sum == 1)x = i;  
        }  
    }  
    if (sum == 1) {  
        for (int i = 0; i < a.size(); i++) {  
            if (i < l) {  
                if (a[i] == b[x]) {  
                    i++;  
                    x++;  
                    cout << i << ' ' << x+l << endl;  
                    return true;  
                }  
            }  
            else if (i > r) {  
                if (a[i] == b[x]) {  
                    i++;  
                    x++;  
                    cout << l+x << ' ' << i << endl;  
                    return true;  
                }  
  
            }  
        }  
    }  
    return false;  
}  
  
int main() {  
    cin >> n;  
    while (n--) {  
        l = 0;  
        r = 9;  
        cin >> a;  
        //长度不够  
        if (a.size() < 10) {  
            cout << -1 << endl;  
            continue;  
        }  
        while (r < a.size()) {  
            if (check_same())break;  
            if(check_inside()) break;  
            if(check_outside())break;  
            //查下一个字符串  
            l++;  
            r++;  
        }  
        if (r==a.size())cout << -1 << endl;  
    }  
    return 0;  
}  
