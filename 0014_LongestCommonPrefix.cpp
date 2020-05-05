/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        string s=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int j=0,k=0;
            string s1=strs[i];
            string prefix="";
            while(j<s.size() && s[j]==s1[k])
            {
                prefix+=s[j];
                j++; k++;
            }
            if(k==0)  //nothing common
                return "";
            s=prefix;
        }
        return s;
    }
};


//This question can also be done using tries if we have large number of strings
class node{
    public:
    char c;
    bool terminal;
    unordered_map<char,node*> children;
    
    node(char d)
    {
        this->c=d;
        terminal=false;
    }
};

class trie{
    public:
    node* head;
    
    trie()
    {
        head=new node('\0');
    }
    
    void addEle(string s)
    {
        node* temp=head;
        for(int i=0;i<s.size();i++)
        {
            if(temp->children.count(s[i]))
            {
                temp=temp->children[s[i]];
            }
            else
            {
                node* p=new node(s[i]);
                temp->children[s[i]]=p;
                temp=p;
            }
        }
        temp->terminal=true;
    }
    
    string prefix()
    {
        node* temp=head;
        string ans="";
        while(temp->children.size()==1 && temp->terminal==false)
        {
            unordered_map<char,node*> :: iterator it=temp->children.begin();
            char t=it->first;
            ans+=t;
            temp=temp->children[t];
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        trie t;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()==0)
                return "";
            t.addEle(strs[i]);
        }
        return t.prefix();
    }
};
