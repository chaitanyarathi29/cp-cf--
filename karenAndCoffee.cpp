#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,k,q;
    cin>>n>>k>> q;
    const int MAXN = 2e5+1; 
    vector<int>freq(MAXN,0);
    while(n--){
        int l,r;
        cin >>l>>r;
        freq[l]++;
        freq[r+1]--;
    }
    int sum=0;
    for(int i=0; i<MAXN; i++){
        sum += freq[i];
        freq[i]=sum;
    }
    for(int i=0; i<MAXN; i++){
        if(freq[i]>=k)
            freq[i]=1;
        else
            freq[i]=0;
    }
    sum=0;
    for(int i=1; i<MAXN; i++){
        freq[i] += freq[i-1];
    }
    while(q--){
        long long a,b;
        cin >> a >> b;
        int ans = freq[b]-freq[a-1];
        cout << ans << endl;
    }

    return 0;
}