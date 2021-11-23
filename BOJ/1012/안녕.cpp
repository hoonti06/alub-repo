/**
* 메모리: 1232 KB, 시간: 0 ms
* 2021.11.23
* by Alub
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 55

int N, M, K;
bool isVisited[MAX_N][MAX_N];
bool board[MAX_N][MAX_N];

int dx[4] = { 0 , 0, -1, 1};
int dy[4] = {-1 , 1,  0, 0};


void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;

    q.push(make_pair(sr, sc));
    isVisited[sr][sc] = true;

    while (!q.empty())
    {
        int qSize = q.size();
        for (int qs = 0; qs < qSize; qs++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                if (isVisited[nr][nc] || !board[nr][nc])
                    continue;

                isVisited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    for (int tc = 0; tc < testcase; tc++)
    {
        memset(isVisited, 0, sizeof(isVisited));
        memset(board, 0, sizeof(board));


        scanf("%d%d%d", &M, &N, &K);

        for (int i = 0; i < K; i++)
        {
            int r, c;
            scanf("%d%d", &c, &r);
            board[r][c] = true;
        }

        int res = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] && !isVisited[i][j])
                {
                    bfs(i, j);
                    res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}