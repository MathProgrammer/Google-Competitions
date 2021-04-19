#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements; 
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 5);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> prefix(no_of_elements + 1, 0);
    for(int i = 2; i <= no_of_elements; i++)
    {
        prefix[i] = 2;
        
        if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        {
            prefix[i] = max(1 + prefix[i - 1], prefix[i]);
        }
        
        //cout << "P " << i <<"  = " << prefix[i] << "\n";
    }
    
    vector <int> suffix(no_of_elements + 1, 0);
    for(int i = no_of_elements - 1; i >= 1; i--)
    {
        suffix[i] = 2;
        
        if(A[i + 1] - A[i] == A[i + 2] - A[i + 1])
        {
            suffix[i] = max(suffix[i + 1] + 1, suffix[i]);
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        //answer = max(answer, max(prefix[i], suffix[i]));
        
        if(i > 1)
        {
            answer = max(answer, max(prefix[i], prefix[i - 1] + 1));
        }
        
        if(i + 1 <= no_of_elements)
        {
            answer = max(answer, max(suffix[i], suffix[i + 1] + 1));
        }
        //answer = max(answer, max(prefix[i - 1] + 1, suffix[i + 1] + 1));
        
        int previous_d = -1, next_d = -1;
        if(i >= 2)
        {
            previous_d = A[i - 1] - A[i - 2];
            
            if(i + 1 <= no_of_elements && A[i - 1] + 2*previous_d == A[i + 1])
            {
                answer = max(answer, prefix[i - 1] + 2);
            }
        }
        
        if(i + 2 <= no_of_elements)
        {
            next_d = A[i + 2] - A[i + 1];
            
            if(i - 1 >= 1 && A[i + 1] - 2*next_d == A[i - 1])
            {
                answer = max(answer, suffix[i + 1] + 2);
            }
        }
        
        if(previous_d != -1 && previous_d == next_d && 
            A[i - 1] + previous_d == A[i + 1] - next_d)
        {
            answer = max(answer, prefix[i - 1] + 1 + suffix[i + 1]);
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
