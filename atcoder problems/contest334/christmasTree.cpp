#include <iostream>
using namespace std;
using ll = long long;

int main(){
  
    //remember subtraction does not include the subtraend point ie 13-4=9 (5,6,7,8,9,10,11,12,13)   4 isnt included here  

    ll a,m,l,r;
    cin>>a>>m>>l>>r;
    ll left=0,right=0;
    ll ans=0;
    if(l>a){
        right = (r-a)/m;
        left = (l-a)/m;
        ans += right-left;
        if((l-a)%m==0) ans++; 
    }else{
        if(r>a){
            right = (r-a)/m;
            left = (a-l)/m;
            ans += right+left+1;
        }else{
            right = (a-r)/m;
            left = (a-l)/m;
            ans += left - right;
            if((a-r)%m==0) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}