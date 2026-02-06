#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
set<long long>ans;

void helper(int i, long long prod, vector<long long>&primes){
    if(i==primes.size()){
        ans.insert(prod);
        return;
    }    
    prod*=primes[i];
    helper(i+1,prod,primes);
    prod/=primes[i];
    helper(i+1,prod,primes);
}

int main(){

    long long x;cin>>x;
    vector<long long>primes={1};
    long long ex = x;
    for(long long i=2;i*i<=x;i++){
        while(x%i==0){
            primes.push_back(i);
            x/=i;
        }    
    }
    if(x>1) primes.push_back(x);
    helper(0,1,primes);
    long long ansi=1e12+2;
    vector<long long>vec(ans.begin(),ans.end());
    for(int i=0;i<vec.size();i++){
        long long maxi = max(vec[i],ex/vec[i]);
        if(lcm(vec[i],ex/vec[i])==ex){
            if(ansi>maxi){
                ansi=maxi;
            }
        }
    }
    cout<<ansi<<" "<<ex/ansi<<endl;

    return 0;
}