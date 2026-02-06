#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long mex(vector<long long>arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    long long expected = 0;
    for (long long x : arr) {
        if (x == expected) expected++;
        else if (x > expected) break;
    }
    return expected;
}

int main(){
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long>v(n,0);
        for(auto&it:v)cin>>it;
        long long m = mex(v);
        int freqans = 0;
        int freql = 0;
        int freqg = 0;
        for(int i=0;i<n;i++){
            if(v[i]==m+1){
                freqans++;
            }
            if(v[i]<m){
                freql++;
            }
            if(v[i]>m){
                freqg++;
            }
        }
        if(freqans){
            int s,e=0;
            for(int i=0;i<n;i++){
                if(v[i]==m+1){
                    s=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(v[i]==m+1){
                    e=i;
                    break;
                }
            }
            for(int i=s;i<=e;i++){
                v[i]=m;
            }
            long long newm = mex(v);
            if(newm==m+1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        if(freql>m || freqg){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
