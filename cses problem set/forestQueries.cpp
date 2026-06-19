// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
        
//     int n,q;
//     cin >>n >> q;
//     vector<vector<char>> forest(n, vector<char>(n));
//     vector<vector<int>> prefix(n, vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0; j<n;j++){
//             cin >> forest[i][j];
//             int val=0;
//             if(forest[i][j]=='*')
//                 val=1;
//             if(i==0 && j==0){
//                 prefix[i][j] = val;
//             }
//             if(i==0 && j!=0){
//                 prefix[i][j] = prefix[i][j-1] + val;
//             }
//             if(i!=0 && j==0){
//                 prefix[i][j] = prefix[i-1][j] + val;
//             }
//             if(i!=0 && j!=0){
//                 prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + val;
//             }
//         }
//     }
//     while(q--){
//         int x1,y1,x2,y2;
//         cin >> y1 >> x1 >> y2 >> x2;
//         y1--;x1--;y2--;x2--;
//         int ans=0;
//         ans=prefix[y2][x2];
//         if (y1 > 0) 
//             ans -= prefix[y1-1][x2];
//         if (x1 > 0) 
//             ans -= prefix[y2][x1-1];
//         if (y1 > 0 && x1 > 0) 
//             ans += prefix[y1-1][x1-1];
//         cout << ans <<endl;
//     }
    
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n,q;cin>>n>>q;
	vector<vector<char>>forest(n,vector<char>(n));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
    	    cin>>forest[i][j];
    	}
	}
	vector<vector<int>>ans(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
    	    int left=0;
    	    int top=0;
    	    int diagonal=0;
    	    if(i-1>=0){
    	        top=ans[i-1][j];
    	    }
    	    if(j-1>=0){
    	        left=ans[i][j-1];
    	    }
    	    if(i-1>=0 && j-1>=0){
    	        diagonal=ans[i-1][j-1];
    	    }
    	    int curr=0;
    	    if(forest[i][j]=='*') curr=1;
    	    ans[i][j] = top+left-diagonal+curr;
    	}
	}
	
	
	while(q--){
	    int y1,x1,y2,x2;
	    cin>>y1>>x1>>y2>>x2;
	    y1--;x1--;y2--;x2--;
	    int answer=ans[y2][x2];
	    if(x1-1>=0){
	        answer-=ans[y2][x1-1];
	    }
	    if(y1-1>=0){
	        answer-=ans[y1-1][x2];
	    }
	    if(x1-1>=0 && y1-1>=0){
	        answer+=ans[y1-1][x1-1];
	    }
	    cout<<answer<<endl;
	}

}
