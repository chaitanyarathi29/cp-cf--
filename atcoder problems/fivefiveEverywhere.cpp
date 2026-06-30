#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){

    int n;
    cin>>n;
    vector<bool>primes(55555,1);
    primes[0]=0;primes[1]=0;
    for(int i=2;i<primes.size();i++){
        if(primes[i]==0) continue;
        for(ll j=1LL*i*i;j<primes.size();j+=i){
            primes[j]=0;
        }
    }
    vector<vector<int>>ans(5);

    for(int i=1;i<5;i++){
        for(int j=2;j<primes.size();j++){
            if(primes[j] && j%5==i){
                ans[i].push_back(j);
            }
        }
        if(ans[i].size()>=n){
            break;
        }
    }

    for(int i=1;i<5;i++){
        if(ans[i].size()>=n){
            int j=0;
            while(n--){
                cout<<ans[i][j]<<" ";
                j++;
            }
            break;
        }
    }



    cout<<endl;

    return 0;
}