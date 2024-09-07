#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Valid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                if (ch == ')' && st.top() == '(')
                    st.pop();

                else if (ch == '}' && st.top() == '{')
                    st.pop();

                else if (ch == ']' && st.top() == '[')
                    st.pop();

                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.size() == 0)
        return true;

    else
        return false;
}
int main()
{
    string s;
    cin >> s;

    bool ans = Valid(s);
    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}