#include <iostream>
#include <vector>
using namespace std;

int main(){
    //iteratively
    int n;cin>>n;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }
    int target;cin>>target;
    int si=0;int ei=n-1;

    /*inbuilt function
    int index = lower_bound(v.begin(),v.end(),target); -> returns index if not there returns size ie last index+1
    returns first element that is NOT less than target(either equal or greater)
    int index = upper_bound(v.begin(),v.end(),target); -> returns index if not there returns size ie last index+1
    returns just first greater than target value
    */
    while(si<=ei){
        int mid = si + (ei-si)/2;
        if(v[mid]==target){
            cout<<"Yes"<<endl;
            return 0;
        }else{
            if(v[mid]>target){
                ei=mid-1;
            }else{
                si=mid+1;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}

//recursively
/* 
    int helper(int target, vector<int>arr, int low, int high){
        if(low>high){
            return -1;
        }
        int mid = low + (high-low)/2;
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]<target){
            return helper(target,arr,mid+1,high);
        }
        else{
            return helper(target,arr,low,mid-1);
        }
    }
*/ 