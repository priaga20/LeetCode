/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

 

Example 2:

Input: "FlaG"
Output: False

 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n= word.size();
        
        //first letter small
        if(word[0]>='a' && word[0]<='z')
        {
            //all must be small
            for(int i=1;i<n;i++)
            {
                if(word[i]<'a' || word[i]>'z')
                    return false;
            }
        }
        else if(word[0]>='A' && word[0]<='Z')
        {
            //if second also capital
            if(word[1]>='A' && word[1]<='Z')
            {
                //all must be capital
                for(int i=2;i<n;i++)
                {
                    if(word[i]<'A' || word[i]>'Z')
                        return false;
                }
            }
            //second small 
            else if(word[1]>='a' && word[1]<='z')
            {
                //all must be small
                for(int i=2;i<n;i++)
                {
                    if(word[i]<'a' || word[i]>'z')
                        return false;
                }
            }
        }
       return true;
    }
};