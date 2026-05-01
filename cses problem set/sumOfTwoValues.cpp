#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<ll> v1(n), v;
    for(auto &it : v1) cin >> it;

    v=v1;
    sort(v.begin(), v.end());

    int s = 0, e = n - 1;
    bool f = false;

    while(s < e){
        ll sum = v[s] + v[e];
        if(sum > x) e--;
        else if(sum < x) s++;
        else{
            f = true;
            break;
        }
    }

    if(!f){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int idx1 = -1, idx2 = -1;

    for(int i = 0; i < n; i++){
        if(v1[i] == v[s]){
            idx1 = i + 1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(v1[i]==v[e] && i+1!=idx1){
            idx2=i+1;
            break;
        }
    }

    cout << min(idx1, idx2) << " " << max(idx1, idx2) << endl;

    return 0;
}