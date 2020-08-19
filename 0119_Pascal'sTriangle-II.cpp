/*Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?*/


class Solution {
public:
    vector<int> getRow(int rowIndex){
        vector<int> v;
        v.push_back(1);
        if(rowIndex==0)
            return v;
        v.push_back(1);
        if(rowIndex==1)
            return v;
        
        for(int i=2;i<=rowIndex;i++)
        {
            int a,b,c;
            for(int j=1;j<i;j++)
            {
                if(j==1)
                {
                    a = v[j-1];
                    b = v[j];
                }
                else
                {
                    a=b;
                    b=v[j];
                }
                c = a+b;
                v[j]=c;
            }
            v.push_back(1);
        }
        return v;
    }
};