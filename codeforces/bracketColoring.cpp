#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        if(n%2){
            cout<<-1<<endl;
            continue;
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
            else cnt2++;
        }
        if(cnt1!=cnt2){
            cout<<-1<<endl;
            continue;
        }
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') v[i]=1;
            else v[i]=-1;
        }
        bool p=0,k=0;
        if(v[0]>0) p=1;
        else k=1;
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
            if(v[i]>0) p=1;
            if(v[i]<0) k=1;
        }
        int cnt=1;
        bool f=0;
        if(p==1 && k==1){
            cout<<2<<endl;
        }else{
            f=1;
            cout<<1<<endl;
        }
        for(int i=0;i<n;i++){
            if(v[i]>0){
                cout<<1<<" ";
            }
            if(v[i]<0){
                if(f){
                    cout<<1<<" ";
                }else{
                    cout<<2<<" ";
                }
            }
            if(v[i]==0){
                if(v[i-1]>0){
                    cout<<1<<" ";
                }else{
                    if(f){
                        cout<<1<<" ";
                    }else{
                        cout<<2<<" ";
                    }
                }   
            }
        }
        cout<<endl;
    }
    
    return 0;
}