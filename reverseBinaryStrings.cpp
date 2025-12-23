#include <iostream>
#include <string>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;int max=0;
        int cnt1=1;int cnt0=1;
        int ans1=0;int ans0=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1' && s[i+1]=='1'){
                cnt1++;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                ans1+=(cnt1-1);

                cnt1=1;
            }
            if(s[i]=='0' && s[i+1]=='0'){
                cnt0++;
            }
            if(s[i]=='0' && s[i+1]=='1'){
                ans0+=(cnt0-1);
                cnt0=1;
            }
            if(s[i+1]=='0' && i==n-2){
                ans0+=(cnt0-1);
            }
            if(s[i+1]=='1' && i==n-2){
                ans1+=(cnt1-1);
            }
        }
        if(ans1>ans0){
            cout<<ans1<<endl;
        }else{
            cout<<ans0<<endl;
        }
        
    }

    return 0;
}