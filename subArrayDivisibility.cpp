#include <iostream>
#include <vector>
using namespace std;
int N=2*1e5;
int main(){
    
    int n;
    cin>>n;
    vector<long long> vec(n,0);
    vector<long long> prefix(n,0);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    long long pre=0;
    for(int i=0; i<n; i++){
        pre += vec[i];
        prefix[i]=pre;
    }
    vector<long long> cnt(N,0);
    cnt[0]=1;
    long long ans=0;
    for(int i=0; i<n; i++){
        int mod=prefix[i]%n;
        if(mod<0){
            mod += n;   
        }
        if(cnt[mod]){
            ans+=cnt[mod];
        }
        cnt[mod]++;
    }
    cout << ans;
    
    return 0;
}