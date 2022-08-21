#include<iostream>  
#include<algorithm>    
using namespace std;  
  
int main() {  
    int n;  
    cin >> n;  
    while (n--) {  
        long long x;  
        cin >> x;  
        for (int i = 0;; i++) {  
            if (x <= pow(2, i)) {  
                cout << i << endl;  
                break;  
            }  
        }  
    }  
    return 0;  
}  
