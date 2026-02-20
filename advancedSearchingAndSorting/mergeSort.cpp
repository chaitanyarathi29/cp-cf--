#include <iostream>
#include <vector>
using namespace std;
vector<int>v;

void mergeSort(int start, int end,int cnt){
    if(start>=end){
        return;
    }
    int si=start;int ei=start+((end-start)/2);
    mergeSort(start,ei,cnt);
    mergeSort(ei+1,end,cnt);

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
    cout<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){

    int n;cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        v.push_back(num);
    }
    mergeSort(0,n-1,cnt);
    cout<<endl;
    for(auto&it:v){
        cout<<it<<" ";
    }
    return 0;
}