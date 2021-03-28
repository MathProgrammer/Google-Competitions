#include <iostream>
#include <vector>

using namespace std;

int count_L(int x, int y)
{
    if(min(x, y) < 2)
    {
        return 0;
    }

    int horizontal_L = min(x - 1, y/2 - 1) ;
    int vertical_L = min(y - 1, x/2 - 1);

    return (horizontal_L + vertical_L);
}

int count(int up, int down, int left, int right)
{
    return ( count_L(up, left) + count_L(up, right) +
            count_L(down, left) + count_L(down, right) );
}

void compute(vector <vector <int> > &up, vector <vector <int> > &down,
vector <vector <int> > &left, vector <vector <int> > &right,
vector <vector <int> > &G, int rows, int columns)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(G[i][j] == 0)
            {
                continue;
            }

            up[i][j] = (G[i][j] == 1) + up[i - 1][j];

            left[i][j] = (G[i][j] == 1) + left[i][j - 1];
        }
    }

    for(int i = rows; i >= 1; i--)
    {
        for(int j = columns; j >= 1; j--)
        {
            if(G[i][j] == 0)
            {
                continue;
            }

            down[i][j] = (G[i][j] == 1) + down[i + 1][j];

            right[i][j] = (G[i][j] == 1) + right[i][j + 1];
        }
    }
}

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <vector <int> > G(rows + 1,
        vector <int> (columns + 1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> G[i][j];
        }
    }

    vector <vector <int> > up(rows + 5, vector <int> (columns + 5, 0)),
    down(rows + 5, vector <int> (columns + 5, 0)),
    left(rows + 5, vector <int> (columns + 5, 0)),
    right(rows + 5, vector <int> (columns + 5, 0));
    compute(up, down, left, right, G, rows, columns);

    long long answer = 0;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(G[i][j] == 0)
            {
                continue;
            }

            answer += count(up[i][j], down[i][j],
                            left[i][j], right[i][j]);
        }
    }

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
