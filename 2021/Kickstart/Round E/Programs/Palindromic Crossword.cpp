#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int get_opposite(int left, int right, int x)
{
    if(right - x + 1 <= x - left + 1)
    {
        int distance = right - x + 1;
        return (left + distance - 1);
    }
    else
    {
        int distance = x - left + 1;
        return (right - distance + 1);
    }
}

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <string> grid(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }

    const char EMPTY = '#', UNFILLED = '.';
    vector <vector <int> > row_beginning(rows, vector <int> (columns));
    vector <vector <int> > row_ending(rows, vector <int> (columns));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(j == 0 || grid[i][j - 1] == EMPTY)
            {
                row_beginning[i][j] = j;
            }
            else
            {
                row_beginning[i][j] = row_beginning[i][j - 1];
            }

        }

        for(int j = columns - 1; j >= 0; j--)
        {
            if(j == columns - 1 || grid[i][j + 1] == EMPTY)
            {
                row_ending[i][j] = j;
            }
            else
            {
                row_ending[i][j] = row_ending[i][j + 1];
            }

        }
    }

    vector <vector <int> > column_beginning(rows, vector <int> (columns));
    vector <vector <int> > column_ending(rows, vector <int> (columns));
    for(int j = 0; j < columns; j++)
    {
        for(int i = 0; i < rows; i++)
        {
            if(i == 0 || grid[i - 1][j] == EMPTY)
            {
                column_beginning[i][j] = i;
            }
            else
            {
                column_beginning[i][j] = column_beginning[i - 1][j];
            }
        }

        for(int i = rows - 1; i >= 0; i--)
        {
            if(i == rows - 1 || grid[i + 1][j] == EMPTY)
            {
                column_ending[i][j] = i;
            }
            else
            {
                column_ending[i][j] = column_ending[i + 1][j];
            }
        }
    }

    int new_letters = 0;
    vector <vector <int> > visited(rows, vector <int> (columns, false));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j] == EMPTY || visited[i][j] || grid[i][j] == UNFILLED)
            {
                continue;
            }

            char current = grid[i][j];
            stack <pair <int, int> > S;
            S.push(make_pair(i, j));

            while(!S.empty())
            {
                pair <int, int> P = S.top();
                S.pop();
                int x = P.first, y = P.second;

                visited[x][y] = true;
                if(grid[x][y] == UNFILLED)
                {
                    new_letters++;
                    grid[x][y] = current;
                }
                

                int next_row_x = x;
                int next_row_y = get_opposite(row_beginning[x][y], row_ending[x][y], y);

                if(!visited[next_row_x][next_row_y])
                {
                    S.push(make_pair(next_row_x, next_row_y));
                }

                int next_column_x = get_opposite(column_beginning[x][y], column_ending[x][y], x);
                int next_column_y = y;

                if(!visited[next_column_x][next_column_y])
                {
                    S.push(make_pair(next_column_x, next_column_y));
                }
            }
        }
    }

    cout << new_letters << "\n";
    for(int i = 0; i < rows; i++)
    {
        cout << grid[i] << "\n";
    }
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
