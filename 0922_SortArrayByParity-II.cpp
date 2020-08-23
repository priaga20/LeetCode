/*Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

 

Note:

    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if(A.size()==0 || A.size()==1)
            return A;
        int e=-1,o=-1;
        for(int i=0;i<A.size();i++)
        {
            if((i+A[i])%2==0)  //even sum then ok
                continue;
            else 
            {
                if(A[i]%2==0 && o==-1)  //even element at odd position
                    o=i;
                else if(A[i]%2==1 && e==-1)           //odd element at even position
                    e=i;
            }
            if(o!=-1 && e!=-1)
            {
                swap(A[o],A[e]);
                i=min(o,e);
                o=-1;
                e=-1;
            }
        }
        return A;
    }
};