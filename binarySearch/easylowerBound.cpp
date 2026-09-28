#include <iostream>
#include <vector>
using namespace std;

int lower_bound(int target, vector<int>vec){
    int s=0,e=vec.size()-1;
    int ans=0;
    while(s<=e){
        int mid = s + (e-s)/2;
        
        if(target<=vec[mid]){
            e=mid-1;
            ans=mid;
        }else{
            s=mid+1;
        }
    }
    return ans;
}
//upperBound ke liye just remove = in the condition

int main(){
    
    vector<int>vec = {1, 4, 7, 8, 12, 14, 19, 21, 33, 43, 46, 51, 65};
    int target;cin>>target;
    
    int idx = lower_bound(target,vec);
    cout<<idx<<endl;
    
    return 0;
}