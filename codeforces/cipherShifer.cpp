#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        int i = 0;
        while(i < n){
            char c = s[i];
            for(int j = i+1; j < n; j++){
                if(s[j] == c){
                    ans += c;
                    i = j + 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}