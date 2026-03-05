#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){

    int a,b,q;
    cin>>a>>b>>q;
    vector<ll>s(a+2,0);
    vector<ll>t(b+2,0);
    for(int i=1;i<=a;i++){
        cin>>s[i];
    }
    for(int i=1;i<=b;i++){
        cin>>t[i];
    }
    s[0]=t[0]=-1e18;
    s[a+1]=t[b+1]=1e18;
    while(q--){
        ll q;cin>>q;
        ll ans = 1e18;
        ll ls = *(--upper_bound(s.begin(),s.end(),q));
        ll lt = *(--upper_bound(t.begin(),t.end(),q));
        ll rs = *(lower_bound(s.begin(),s.end(),q));
        ll rt = *(lower_bound(t.begin(),t.end(),q));

        ans = min(ans,q-min(ls,lt));
        ans = min(ans,rt-ls+min(q-ls,rt-q));
        ans = min(ans,rs-lt+min(rs-q,q-lt));
        ans = min(ans,max(rs,rt)-q);

        cout<<ans<<endl;

    }


    return 0;
}