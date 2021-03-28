#include <iostream>

using namespace std;

void solve()
{
    int length, k;
    string S;
    cin >> length >> k >> S;
    
    int score = 0;
    for(int front = 0, back = S.size() - 1; front < back; front++, back--)
    {
        if(S[front] != S[back])
        {
            score++;
        }
    }
    
    int answer = abs(score - k);
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    for(int i = 1; i <= no_of_test_cases; i++)
    {
        cout << "Case #" << i << ": "; 
        solve();
    }
    
    return 0;
}
