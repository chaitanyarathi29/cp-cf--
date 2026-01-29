#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,q;
    cin>>n>>q;
    long long* vec = new long long[n]; 

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    int* start = new int[q];
    int* end = new int[q];

    for(int i=0; i<q; i++){
        cin >> start[i] >> end[i];
    }

    long long prefix = 0;
    long long* pre = new long long[n];
    for(int i=0; i<n; i++){
        prefix += vec[i];
        pre[i]=prefix;
    }
    cout << endl;
    long long ans=0;
    for(int i=0; i<q; i++){
        if(start[i] ==1){
            cout << pre[end[i]-1]<<endl;;
        }else{
            ans=pre[end[i]-1]-pre[start[i]-2];   
            cout <<ans<<endl;
        }
    }

    return 0;
}