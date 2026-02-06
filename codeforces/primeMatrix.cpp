
#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    vector<int>isPrime(1e5+4,1);
    isPrime[0]=0;isPrime[1]=0;
    for(int i=2;i*i<1e5+4;i++){
        for(int j=i*i;j<1e5+4;j+=i){
            isPrime[j]=0;
        }
    }
    int prime = -1;
    for (int i = 100003; i >= 0; i--) {
        if (isPrime[i]) prime = i;
        isPrime[i] = prime;
    }
    int min=1e5+3;
    for(int i=0;i<n;i++){
        int num=0;
        for(int j=0;j<m;j++){
            if(isPrime[vec[i][j]]!=1){
                num+=(isPrime[vec[i][j]]-vec[i][j]);
            }
        }
        if(min>=num){
            min=num;
        }
    }
    for(int i=0;i<m;i++){
        int num=0;
        for(int j=0;j<n;j++){
            if(isPrime[vec[j][i]]!=1){
                num+=(isPrime[vec[j][i]]-vec[j][i]);
            }
        }
        if(min>num){
            min=num;
        }
    }
    cout<<min<<endl;
    return 0;
}