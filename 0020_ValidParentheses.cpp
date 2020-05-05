/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

    1.Open brackets must be closed by the same type of brackets.
    2.Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.*/

#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
                return false;
            char p=st.top();
            st.pop();
            if(s[i]==')' && p=='(')
                continue;
            else if(s[i]=='}' && p=='{')
                continue;
            else if(s[i]==']' && p=='[')
                continue;
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};