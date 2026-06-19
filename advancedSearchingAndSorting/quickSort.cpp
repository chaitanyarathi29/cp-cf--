#include <iostream>
#include <vector>
using namespace std;


void quickSort(int pivot, vector<int>vec, int s, int e){
    
    


}

int main(){


    int n;cin>>n;
    vector<int>vec(n,0);
    
    for(auto&it:vec){
        cin >>it;
    }

    quickSort(0,vec,0,n-1);

    for(auto&it:vec){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}