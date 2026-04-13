#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>v(n,0);
    for(auto&it:v){
        cin>>it;
    }    
    sort(v.begin(),v.end());
    int c=0;
    for(int i=0;i<n-1;i+=2){
        swap(v[i],v[i+1]);
        c++;
    }
    if(n&1){
        cout<<c<<endl;
    }
    else{
        cout<<c-1<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int n;
// 	cin>>n;
// 	vector<int>v(n);
// 	for(int i=0;i<n;i++){
// 	    cin>>v[i];
// 	}
// 	sort(v.begin(),v.end());
// 	int a=0,b=n-1;
// 	vector<int>ans;
// 	int c=1;
	
// 	while(b>=a){
// 	    if(c&1){
// 	        ans.push_back(v[b--]);
// 	    }
// 	    else{
// 	        ans.push_back(v[a++]);
// 	    }
// 	    c++;
	    
// 	}
// 	if(n&1){
// 	cout<<a<<endl;
// 	}
// 	else{
// 	    cout<<a-1<<endl;
// 	}
// 	for(int i=0;i<n;i++){
// 	    cout<<ans[i]<<" ";
// 	}
//     cout<<endl;
// }
