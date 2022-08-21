#include<iostream>  
#include<algorithm>  
#include<vector>  
using namespace std;  
  
int n;  
  
vector<int> add(vector<int> &A, vector<int>& B) {  
    vector<int> C;  
    int t = 0;  
    unsigned int i;  
    for (i = 0; i < A.size() || i < B.size(); i++) {  
        if (i < A.size())t += A[i];  
        if (i < B.size())t += B[i];  
        C.push_back(t % 2);  
        t /= 2;  
    }  
    //可能最后仍有进位，最高位增加了  
    if (t)C.push_back(t);  
    return C;  
}  
  
int main() {  
    cin >> n;  
    while (n--) {  
        //输入部分  
        string a, b;  
        cin >> a >> b;  
        vector<int> A, B;  
        for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');  
        for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');  
        auto C = add(A, B);  
        int len=C.size()+2;  
        //第一行  
        for (int i = 0; i < len - A.size(); i++) cout << " ";  
        for (int i = A.size() - 1; i >= 0; i--) cout << A[i];  
        cout << endl;  
        //第二行  
        cout << "+";  
        for (int i = 1; i < len - B.size(); i++) cout << " ";  
        for (int i = B.size() - 1; i >= 0; i--) cout << B[i];  
        cout << endl;  
        //第三行  
        for (int i = 0; i < len; i++) cout << "-";  
        cout << endl;  
        //第四行  
        cout << "  ";  
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];  
        cout << endl;  
    }  
    return 0;  
}  
