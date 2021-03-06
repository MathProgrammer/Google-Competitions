#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void get_all_maximum(queue <pair <int, int> > &Q,
vector <vector <int> > &G, vector <vector <int> > &visited,
int R, int C)
{
    int largest = 0;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            largest = max(largest, G[i][j]);
        }
    }

    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(largest == G[i][j])
            {
                Q.push(make_pair(i, j));
            }
        }
    }
}

int is_inside(int x, int y, int R, int C)
{
    return (1 <= x && x <= R && 1 <= y && y <= C);
}

void solve()
{
    const int NO_OF_NEIGHBOURS = 4;
    int x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
    int y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};

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

    vector <vector <int> > visited(rows + 1,
    vector <int> (columns + 1, false));
    queue <pair <int, int> > Q;
    get_all_maximum(Q, G, visited, rows, columns);

    long long answer = 0;
    while(!Q.empty())
    {
        int current_x = Q.front().first, current_y = Q.front().second;
        visited[current_x][current_y] = true;
        Q.pop();

        for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
        {
            int next_x = current_x + x[n];
            int next_y = current_y + y[n];

            if(!is_inside(next_x, next_y, rows, columns) ||
            visited[next_x][next_y])
            {
                continue;
            }

            if(G[next_x][next_y] < G[current_x][current_y])
            {
                answer += (G[current_x][current_y] - G[next_x][next_y]) - 1;

                G[next_x][next_y] = G[current_x][current_y] - 1;

                Q.push(make_pair(next_x, next_y));
            }
            else if(G[next_x][next_y] == G[current_x][current_y])
            {
                Q.push(make_pair(next_x, next_y));
            }
            else if(G[next_x][next_y] > G[current_x][current_y])
            {
                answer += (G[next_x][next_y] - G[current_x][current_y]) - 1;

                G[current_x][current_y] = G[next_x][next_y] - 1;

                visited[current_x][current_y] = false;

                Q.push(make_pair(current_x, current_y));
            }
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
