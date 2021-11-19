/**
* 메모리: 1112 KB, 시간: 0 ms
* 2021.11.19
* by Alub
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_N 45

int zero[MAX_N];
int one[MAX_N];

int main()
{
	int testcase;
	testcase = 1;
//	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++)
	{
		zero[0] = 1;
		one[0] = 0;

		zero[1] = 0;
		one[1] = 1;

		for (int i = 2; i < MAX_N; i++)
		{
			zero[i] = zero[i - 1] + zero[i - 2];
			one[i] = one[i - 1] + one[i - 2];
		}

		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int idx;
			scanf("%d", &idx);
//			printf("idx : %d\n", idx);
			printf("%d %d\n", zero[idx], one[idx]);
		}
	}
}