#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        int ans=0;
        int c=0;
        if(s[0]=='u'){
            s[0]='s';
            c++;
        }
        if(s[s.size()-1]=='u'){
            s[s.size()-1]='s';
            c++;
        }
        for(auto&it:s){
            if(it=='u'){
                cnt++;
            }
            if(it=='s'){
                cnt=0;
            }
            if(cnt==2){
                ans++;
                cnt=0;
            }
        }
        cout<<ans+c<<endl;
    }
    return 0;
}