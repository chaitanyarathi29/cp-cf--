#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string ans="";
        bool f=0;
        char c=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==c){
                ans+=s[i];
                f=1;
            }else{
                if(f){
                    c=s[i];
                }
                f=0;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}