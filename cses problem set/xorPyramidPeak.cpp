#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;cin>>n;
    vector<long long>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt1=0;
        int k=n-1;
        while((k)!=0){
            cnt1 += k/2;
            k = (k)/2;
        }
        int cnt2=0;
        int kr=n-1-i;
        while((kr)!=0){
            cnt2 += (kr)/2;
            kr = (kr)/2;
        }
        int cnt3=0;
        kr=i;
        while((kr)!=0){
            cnt3 += kr/2;
            kr = kr/2;
        }
        if((cnt1-cnt2-cnt3)==0){
            ans^=v[i];
        } 
    }
    cout<<ans<<endl;

    return 0;
}


//to find n! whther it is even or odd divide n with 2 and add the number until n becomes zero 