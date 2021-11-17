/*
* 메모리: 1116 KB, 시간: 0 ms
* 타이머 시간: null
* 2021.11.17
* by Alub
**/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 55

int N, M, K;
char board[MAX_N][MAX_N];
int res;

void solution(int sr, int sc, char startColor)
{
    char anotherColor = (startColor == 'B'? 'W' : 'B');

    int k = 0;
    int cnt = 0;
    for (int i = sr; i < sr + 8; i++)
    {
        for (int j = sc; j < sc + 8; j++)
        {
            char correctColor = (k%2 == 0? startColor : anotherColor);
            if (board[i][j] != correctColor)
                cnt++;
            k++;
        }
        k++;
    }
    res = min(res, cnt);
}

int main()
{
    res = 1e9;

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%s", board[i]);

    for (int i = 0; i < N-7; i++)
    {
        for (int j = 0; j < M-7; j++)
        {
            solution(i, j, 'B');
            solution(i, j, 'W');
        }
    }
    printf("%d\n", res);
    return 0;
}