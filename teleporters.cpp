#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>v(n,0);
        for(auto&it:v)cin>>it;
        for(int i=0;i<n;i++){
            v[i] = v[i]+i+1;
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(c>=v[i]){
                cnt++;c-=v[i];
            }else{
                break;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
