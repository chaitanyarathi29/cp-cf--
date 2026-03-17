#include <iostream>
#include <numeric>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll m;cin>>m;

        ll l1=lcm(a,b);
        ll l2=lcm(b,c);
        ll l3=lcm(c,a);
        ll all=lcm(a,l2);
        ll dall = m/all;
        ll lab = lcm(l1,all);
        ll dab = (m/l1)-(m/lab);
        ll lbc = lcm(l2,all);
        ll dbc = (m/l2)-(m/lbc);
        ll lca = lcm(l3,all);
        ll dca = (m/l3)-(m/lca);
        ll da = (m/a)-(dab+dca+dall);
        ll db = (m/b)-(dab+dbc+dall);
        ll dc = (m/c)-(dbc+dca+dall);
        cout<<((da*6)+((dab+dca)*3)+(dall*2))<<" ";
        cout<<((db*6)+((dab+dbc)*3)+(dall*2))<<" ";
        cout<<((dc*6)+((dbc+dca)*3)+(dall*2))<<" "<<endl;
    }
    
    return 0;
}