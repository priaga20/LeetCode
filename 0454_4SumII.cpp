/*Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be 
at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    
    void addToHash(vector<vector<int>> &v,unordered_map<int,int> &m,int i,int sum)
    {
        if(i==v.size()/2)   //k/2 vectors accessed
            m[sum]++; 
        else
        {
            for(auto a : v[i])
            {
                addToHash(v,m,i+1,sum+a);
            }
        }
    }
    
    int countComplements(vector<vector<int>> &v,unordered_map<int,int> &m,int i,int complement)
    {
        if(i==v.size())
        {
            if(m.find(complement)!=m.end())
                return m[complement];
            else
                return 0;
        }
        int c=0;
        for(auto a : v[i])
        {
            c+=countComplements(v,m,i+1,complement-a);
        }
        return c;
    }
    
    int kSumCount(vector<vector<int>> &v)
    {
        unordered_map<int,int> m;
        addToHash(v,m,0,0);  //0-index of current list  , 0-value of sum
        return countComplements(v,m,v.size()/2,0);
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        vector<vector<int>> v {A,B,C,D};
        return kSumCount(v);
    }
    
    // int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    //     int n=A.size(),ans=0;
    //     unordered_map<int,int> m;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             m[A[i]+B[j]]++;
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             if(m.find(-(C[i]+D[j]))!=m.end())
    //                 ans+=m[-(C[i]+D[j])];
    //         }
    //     }
    //     return ans;
    // }
};