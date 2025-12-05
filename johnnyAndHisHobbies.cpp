#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int ans = 1e7;
        int n;
        cin>>n;
        vector<int>v1(n,0);
        vector<int>v(n);
        for(auto&it:v)cin>>it;
        set<int>s(v.begin(),v.end());
        bool flag=0;
        
        for(int i=1;i<n;i++){
            int temp = v[0]^v[i];
            v1[i]=temp;
        }
        for(int i=1;i<n;i++){
            set<int>s1;
            for(int j=0; j<n; j++){
                s1.insert(v[j]^v1[i]);
            }
            if(s==s1){
                if(v1[i]<ans){
                    ans = v1[i];
                    flag=1;
                }
            }
        }
        if(flag){
            cout << ans <<endl;
        }else{
            cout << -1 <<endl;
        }
    }

    return 0;
}