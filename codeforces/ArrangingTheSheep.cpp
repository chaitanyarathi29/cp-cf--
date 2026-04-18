#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;

        vector<int> v1;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                v1.push_back(i);
            }
        }

        int k = v1.size();
        if(k == 0){
            cout << 0 << endl;
            continue;
        }

        // transform positions
        vector<int> v2(k);
        for(int i = 0; i < k; i++){
            v2[i] = v1[i] - i;
            
        }

        // median of transformed
        int med = v2[k / 2];

        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += abs(v2[i] - med);
        }

        cout << ans << endl;
    }
    return 0;
}