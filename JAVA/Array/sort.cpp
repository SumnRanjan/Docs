#include<bits/stdc++.h>
using namespace std;

bool sorted(vector<int>&ans ,int n){
    for(int i = 0 ; i < n -1 ; i++){
        if(ans[i+1] < ans[i])
        return false;
    }
    return true;
}

int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>arr(n);

        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        if(k>1){
            cout<<"YES"<<endl;
        }

        else{
            if(sorted(arr , n)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        
    }
    
return 0;
}