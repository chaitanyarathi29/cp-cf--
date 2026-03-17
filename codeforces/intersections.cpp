#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int start, int end,long long &cnt,vector<int>&v){
    if(start>=end){
        return;
    }
    int si=start;int ei=start+((end-start)/2);
    mergeSort(start,ei,cnt,v);
    mergeSort(ei+1,end,cnt,v);

    int i=si;int j=ei+1;
    vector<int>temp(end-start+1,0);
    int idx=0;
    while(i<=ei && j<=end){
        if(v[i]>v[j]){
            temp[idx]=v[j];
            cnt+=(ei-i+1);
            j++;
        }else{
            temp[idx]=v[i];
            i++;
        }
        idx++;
    }
    while(i<=ei){
        temp[idx]=v[i];i++;idx++;
    }
    while(j<=end){
        temp[idx]=v[j];j++;idx++;
    }
    for(int i=start;i<=end;i++){
        v[i]=temp[i-start];
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
     
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n,0);
        vector<int>b(n,0);
        vector<int>mpa(n,0);
        vector<int>mpb(n,0);
        for(auto&it:a){
            cin>>it;
        }
        for(auto&it:b){
            cin>>it;
        }
        for(int i=0;i<n;i++){
            mpa[a[i]-1]=i;
            mpb[b[i]-1]=i;
        }
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            int t=a[i];
            v[mpa[t-1]] = mpb[t-1];
        }
        long long cnt=0;
        mergeSort(0,n-1,cnt,v);
        cout<<cnt<<endl;
    }
    
    return 0;
}