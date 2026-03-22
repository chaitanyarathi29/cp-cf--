#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,l,r;
    cin>>n>>l>>r;
    string s;cin>>s;
    long long ans=0;
    for(int i=0;i<26;i++){
        int cnt=0;
        char ch='a'+i;
        vector<int>v(n,0);
        int n=s.size();
        for(int i = 0; i < n; i++){
            v[i] = (i > 0 ? v[i-1] : 0) + (s[i] == ch);
        }
        for(int i=0;i+l<n;i++){
            int right=min(i+r,n-1);
            if(l+i>right) continue;
            if(s[i]==ch){
                ans+=v[right]-v[l+i-1];
            }            
        }
    }
    cout<<ans<<endl;
    return 0;
}
//correct sol
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int n, l, r;
//     cin >> n >> l >> r;
//     string s;
//     cin >> s;
//     long long ans = 0;
//     for(int c = 0; c < 26; c++){
//         char ch = 'a' + c;
//         vector<int> v(n, 0);
//         for(int i = 0; i < n; i++){
//             v[i] = (i > 0 ? v[i-1] : 0) + (s[i] == ch);
//         }
//         for(int i = 0; i < n; i++){
//             if(s[i] != ch) continue;
//             int left = i + l;
//             int right = min(i + r, n - 1);
//             if(left > right) continue;
//             ans += v[right] - (left > 0 ? v[left - 1] : 0);
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }