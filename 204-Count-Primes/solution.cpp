class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=2)    return 0;
        int c=1;
        bool *isPrime=new bool[n]; //[0,n)
        
        for(int i=2;i<n;i++)
        {
            isPrime[i]=true;
        }
        
        for(int i=3;i*i<n;i++)  //Sieve of Eratosthenes
        {
            if(isPrime[i])
            {
                for(int s=i*i;s<n;s+=i)
                {
                    isPrime[s]=false;
                }
            }
        }
        
        for(int i=3;i<n;i+=2)
        {
            if (isPrime[i]) c++;
        }
        return c;
    }
};