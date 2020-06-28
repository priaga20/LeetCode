/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    
    // O(m^2 * n)
    void preProcessing(vector<string>& wordList, unordered_map<string,vector<string>> &m)
    {
        int n=wordList[0].size();
        for(int i=0;i<wordList.size();i++)
        {
            string s=wordList[i];
            for(int j=0;j<n;j++)
            {
                string is= s.substr(0,j)+"*"+s.substr(j+1);  //intermediate state
                if(m.find(is)!=m.end())
                    m[is].push_back(s);
                else
                {
                    vector<string> t;
                    t.push_back(s);
                    m[is]=t;
                }
            }
        }
        // for(auto it=m.begin();it!=m.end();it++)
        // {
        //     cout<<it->first<<" : ";
        //     for(int i=0;i<it->second.size();i++)
        //     {
        //         cout<<it->second[i]<<" ,";
        //     }
        //     cout<<endl;
        // }
    }
    
    // O(m^2 * n)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        //pre-processing
        unordered_map<string,vector<string>> m;
        preProcessing(wordList,m);
        
        //using BFS
        //string is the word, int is level of node i.e. 1 for beginWord
        queue<pair<string,int>> q;
        
        //to keep track of alreaddy visited words
        unordered_map<string,bool> visited;
        
        q.push(make_pair(beginWord,1));
        visited[beginWord]=true;
        
        while(!q.empty())
        {
            auto f = q.front();
            string cw=f.first;  //current_word
            int level=f.second;
            q.pop();
            if(cw==endWord)
            {
                return level;
            }
            //generate all generic transformations of current_word
            for(int i=0;i<n;i++)
            {
                string is=cw.substr(0,i)+"*"+cw.substr(i+1);
                if(m.find(is)!=m.end())
                {
                    auto v= m[is];
                    for(int j=0;j<v.size();j++)
                    {
                        if(visited[v[j]]==false)
                        {
                            visited[v[j]]=true;
                            q.push(make_pair(v[j],level+1));
                        }
                    }
                }
            }
        }
        return 0;
    }
};