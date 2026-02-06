#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main(){

    int n;
    cin >>n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<long long> prefix(n);
    long long pre=0;
    for(int i=0; i<n; i++){
        pre += arr[i];
        prefix[i] = pre;
    }
    vector<long long> sorted = arr;
    sort(sorted.begin(),sorted.end());
    vector<long long> prefix1(n);
    long long pre1=0;
    for(int i=0; i<n; i++){
        pre1 += sorted[i];
        prefix1[i] = pre1;
    }
    int t;
    cin >> t;
    while(t--){
        int type, left, right;
        cin >> type >> left >> right;
        long long ans = 0;
        if(type == 1){
            if(left==1){
                ans = prefix[right-1];
            }else{
                ans = prefix[right-1] - prefix[left-2];
            } 
        }else{    
            if(left==1){
                ans = prefix1[right-1];
            }else{
                ans = prefix1[right-1] - prefix1[left-2];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
