/*Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/

class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2)
            return 0;
        int *prime=new int[n]();  //0 indicates not prime
        //all even numbers are not prime
        //odd numbers can be prime
        for(int i=3;i<n;i+=2)
        {
            prime[i]=1;
        }
        for(int i=3;i*i<n;i++)
        {
            if(prime[i])
            {
                //making multiples of curr no as non-prime
                for(int j=i*i;j<n;j=j+i)
                {
                    prime[j]=0;
                }
            }
        }
        //corner cases
        prime[2]=1;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(prime[i])
                c++;
        }
        return c;
    }
};