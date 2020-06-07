/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2. 

Note: You may assume the string contain only lowercase English letters.*/

class Solution {
public:
    int firstUniqChar(string s) {
        int *arr=new int[26]();
        int indx=-1;
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]-'a']==1)
            {
                indx=i;
                break;
            }     
        }
        return indx;
    }
    
};
