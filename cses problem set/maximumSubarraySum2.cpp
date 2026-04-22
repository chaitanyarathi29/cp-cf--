#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int n,a,b;
    cin>>n>>a>>b;

    vector<ll>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }
    multiset<ll>m;
    for(int i=a-1;i<b;i++){
        m.insert(v[i]);
    }
    ll ans =*m.rbegin();
    int left=a-1,right=b;
    for(int i=1;i<=n-a;i++){
        auto it = m.find(v[left]);
        m.erase(it);
        if(right<n) m.insert(v[right]);
        ans=max(ans,*m.rbegin()-v[i-1]);
        left++;right++;
    }
    
    cout<<ans<<endl;

    return 0;
}