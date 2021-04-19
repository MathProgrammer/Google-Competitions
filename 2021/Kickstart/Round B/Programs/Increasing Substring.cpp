#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int length;
    string S; 
    cin >> length >> S;
    
    vector <int> answer(length + 1, 1);
    for(int i = 1; i < length; i++)
    {
        if(S[i] > S[i - 1])
        {
            answer[i] = answer[i - 1] + 1;
        }
    }
    
    for(int i = 0; i < length; i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";
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
