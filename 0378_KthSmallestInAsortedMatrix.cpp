/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/


//using binary search
class Solution {
public:
    
    int getCount(vector<vector<int>>& matrix, int mid,int n)
    {
        int ans=0;
        int i=n-1 , j=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j] <= mid)
            {
                ans += i+1; //all elements in this column above are less than equal to mid
                j++;
            }
            else
                i--;  //all elements in this row are greater than mid
        }
        return ans;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k){
        
        int n=matrix.size();
    
        if(k==1)
            return matrix[0][0];
        if(k==n*n)
            return matrix[n-1][n-1];
        
        //monotoninc search space
        int low=matrix[0][0],high=matrix[n-1][n-1];
        int ans=0;
        while(low<=high)
        {
            int mid = (high+low)/2;
            //getting count of elements less than equal to mid
            int count=getCount(matrix,mid,n);
            if(count < k)
                low=mid+1;
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};


//using heaps
/*#define customPair pair<int,pair<int,int>>

class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k){
        
        int n=matrix.size();
    
        if(n==1)
            return matrix[0][0];
        if(k==n*n)
            return matrix[n-1][n-1];
        
        int **visited=new int* [n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new int[n]();
        }
        
        //at any time the top left corner ele will be the smallest in that particualr submatrix
        priority_queue<customPair, vector<customPair>, greater<customPair> > pq;
        //adding first row to min heap bcoz that has the min elements of each column
        for(int j=0;j<n;j++)
        {
            customPair p = make_pair(matrix[0][j],make_pair(0,j));
            pq.push(p);
            visited[0][j]=1;
        }
        
        while(k>1)
        {
            //removing root element 
            customPair p = pq.top();
            pq.pop();
            k--;
            
            int i=p.second.first;
            int j=p.second.second;
            
            if(j+1<n && !visited[i][j+1])
            {
                customPair t = make_pair(matrix[i][j+1],make_pair(i,j+1));
                pq.push(t);
                visited[i][j+1]=1;
            }
            if(i+1<n && !visited[i+1][j])
            {
                customPair t = make_pair(matrix[i+1][j],make_pair(i+1,j));
                pq.push(t);
                visited[i+1][j]=1;
            }
        }
        
        return pq.top().first;
        
    }
};*/