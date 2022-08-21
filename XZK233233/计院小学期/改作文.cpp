#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<string>  
using namespace std;  
  
const int N = 1000000;  
string str;  
char sign[5] = { ',','.','?','!' };  
  
int main() {  
    while (getline(cin,str)){  
        if (str[0]>='a' && str[0] <= 'z') str[0] -= 32;  
        if (str[1] >= 'A' && str[1] <= 'Z') str[1] += 32;  
        for (int i = 2; i<str.size(); i++) {  
            for (int j = 1; j < 4; j++) {  
                //需要大写的  
                if (str[i - 2] == sign[1] || str[i - 2] == sign[2] || str[i - 2] == sign[3]) {  
                    if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;  
                }  
                //需要小写的  
                else {  
                    if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;  
                }  
            }  
        }  
        cout << str << endl;  
        //重新初始化  
        str.clear();  
    }  
    return 0;  
}  
