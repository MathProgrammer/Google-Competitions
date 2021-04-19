#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_prime(long long n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    
    return true;
}

long long root(long long n)
{
    long long left = 0, right = 1e9; 
    
    //L^2 < n <= R^2
    while(right - left > 1)
    {
        long long mid = (left + right)/2;
        
        if(mid*mid < n)
        {
            left = mid;
        }
        else 
        {
            right = mid;
        }
    }
    
    return right;
}

void solve()
{
    long long n;
    cin >> n; 
    
    long long p1 = -1, p2 = -1;
    
    //At most 564 iterations
    for(long long i = root(n); p1 == -1 || p2 == -1; i--)
    {
        if(is_prime(i))
        {
            if(p1 == -1)
            {
                p1 = i;
            }
            else 
            {
                p2 = i;
            }
        }
    }
    
    long long answer = p1*p2;
    
    for(long long i = root(n) + 1; ; i++)
    {
        if(is_prime(i))
        {
            p2 = i;
            
            if(p1*p2 <= n)
            {
                answer = p1*p2;
            }
            
            break;
        }
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    for(int i =1 ; i <= no_of_test_cases; i++)
    {
        cout << "Case #" << i << ": "; 
        solve();
    }
    
    return 0;
}
