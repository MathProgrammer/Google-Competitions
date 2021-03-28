#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void solve()
{
    string S; 
    vector < vector <int> > cost(100, vector <int> (100, 0));
    cost['C']['C'] = cost['J']['J'] = 0;
    cin >> cost['C']['J'] >> cost['J']['C'] >> S;
    
    char options[2] = {'C', 'J'};
    const long oo = 1e14;
    vector < vector <long long> > min_cost(S.size() + 1, vector <long long> (100, oo));
    for(int i = 0; i < S.size(); i++)
    {
        if(i == 0)
        {
            if(S[i] == '?')
            {
                min_cost[i]['C'] = min_cost[i]['J'] = 0;
            }
            else 
            {
                min_cost[i][S[i]] = 0;
            }
            
            continue;
        }
        if(S[i] != '?')
        {
            for(int o = 0; o < 2; o++)
            {
                long long this_cost = cost[options[o]][S[i]];
                
                min_cost[i][S[i]] = min(min_cost[i][S[i]], 
                                    this_cost + min_cost[i - 1][options[o]]);
            }
        }
        else if(S[i] == '?')
        {
            for(int here_o = 0; here_o < 2; here_o++)
            {
                for(int previous_o = 0; previous_o < 2; previous_o++)
                {
                    long long this_cost = cost[options[previous_o]][options[here_o]];
                    
                    //cout << "Cost(" << options[previous_o] << "," << options[here_o] << " = " << this_cost << "\n";
                    
                    min_cost[i][options[here_o]] = min(min_cost[i][options[here_o]],
                                this_cost + min_cost[i - 1][options[previous_o]]);
                }
            }
        }
        
        //cout << "F(" << i << ",C" << ") = " << min_cost[i]['C'];
        //cout << "F(" << i << ",J" << ") = " << min_cost[i]['J'];
    }
    
    cout << min(min_cost[S.size() - 1]['C'], min_cost[S.size() - 1]['J']) << "\n";
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
