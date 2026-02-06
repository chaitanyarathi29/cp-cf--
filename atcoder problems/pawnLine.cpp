#include <iostream>
#include <vector>
using namespace std;



int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        for(auto&it:v){
            cin>>it;
        }
        int curr,next;
        int cnt=0;
        for(int i=1;i<n-1;i++){
            next=i;curr=i-1;
            if(v[curr]>v[next]+1 || v[curr]<v[next]-1){
                if(v[curr]<v[next]-1){
                    cnt+=v[next]-v[curr]-1;
                    v[next]=v[curr]+1;
                }else{
                    cnt+=v[curr]-v[next]-1;
                    v[curr]=v[next]+1;
                }             
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}