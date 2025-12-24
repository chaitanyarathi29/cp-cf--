#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        for(auto&it:a)cin>>it;
        int sum=0;
        for(int i=0; i<n-1; i++){
            sum+=abs(a[i]-a[(i+1)]);
        }
        int ans=sum;
        int abs2=sum-abs(a[0]-a[1]);
        ans=min(ans,abs2);
        int abs1=sum-abs(a[n-1]-a[n-2]);
        ans=min(ans,abs1);
        for(int i=1;i<n-1;i++){
            ans=min(ans,sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}