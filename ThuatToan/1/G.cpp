#include <bits/stdc++.h>
using namespace std;
string sKey[12] = {
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
    "", " ", ""
};
int main(){
    int T;
    cin >> T;
    string str;
    getline(cin, str);
    for(int t = 1; t <= T; t++){
        getline(cin, str);
        int res = 0;
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < 12; j++){
                for(int k = 0; k < sKey[j].size(); k++){
                    if (str[i] == sKey[j][k]){
                        res += k + 1;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
