#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n,q;
    cin >> n >> q;
    vector<long long> arr(n,0);
    vector<long long> freq(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    while(q--){
        long long l,r;
        cin >> l >> r;
        freq[l-1] += 1;
        if(r<n){
            freq[r] += -1;
        }    
    }
    long long sumf=0;
    for(int i=0; i<n; i++){
        sumf += freq[i];
        freq[i]=sumf;
    }
    
    sort(freq.begin(),freq.end());
    sort(arr.begin(),arr.end());

    long long sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i]*freq[i];
    }
    
    cout << sum ;

    return 0;
}