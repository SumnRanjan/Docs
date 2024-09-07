#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ans(string &s){
    stack<char>st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else if (ch != ' ')
        {
            int opt2 = st.top();
            st.pop();
            int opt1 = st.top();
            st.pop();

            switch (ch){
                case '+' : 
                st.push(opt1+opt2);
                break;

                case '-' : 
                st.push(opt1-opt2);
                break;

                case '*' : 
                st.push(opt1*opt2);
                break;
                
                case '/' : 
                st.push(opt1/opt2);
                break;


            }


        }
        
    }
    return st.top();
    
}

int main(){
    string s;
    cin>>s;

    int total = ans(s);
    cout<<total<<endl;

return 0;
}