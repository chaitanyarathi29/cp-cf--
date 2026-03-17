#include <iostream>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='R'){
                if(s[i]=='L'){
                    cnt++;break;
                }else{
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}