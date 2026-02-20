#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// bool helper(ll mid,ll target){
//     return (mid*mid<=target);
// }

// for two cases 

//1 -> TTTTTTTTTFFFFFFFFFFFFFFF
//2 -> FFFFFFFFFTTTTTTTTTTTT 

int main(){

    ll n;cin>>n;
    ll si=1;int ei=1e9;int ans=-1;

    auto helper = [&](ll mid)->bool{
        return (mid*mid<=n);
    }; //lambda functions

    while(si<=ei){
        ll mid = si + (ei-si)/2;
        if(helper(mid)){
            ans=mid;
            ei=mid-1; //TTTTFFFFF
            //si = mid+1 FFFFFTTTT
        }else{
            si = mid+1; // TTTTTTFFFF
            //ei = mid-1 FFFFFFTTTTT
        }
    }
    cout<<ans<<endl;

    return 0;
}