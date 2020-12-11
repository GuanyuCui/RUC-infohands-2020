#include <stdio.h>

int v[] = {2, 4, 3, 7};
int w[] = {2, 3, 5, 5};

#define n sizeof(v) / sizeof(v[0])
#define W 10

void printSolution(int path[][W + 1], int k, int weight)
{
	// 已经到头了
	if(k == 0 || weight == 0)
	{
		return;
	}
	// 没有标记，就不选
	if(path[k][weight] == 0)
	{
		printSolution(path, k - 1, weight);
	}
	// 有标记，选，同时减少背包容量
	else
	{
		printSolution(path, k - 1, weight - w[k - 1]);
		printf(" %d", k);
	}
}

int main(int argc, char *argv[])
{
	
	int knap[n + 1][W + 1] = {0};
	int path[n + 1][W + 1] = {0};
	
	for(int i = 0; i <= n; i++)
	{
		knap[i][0] = 0;
	}
	for(int i = 0; i <= W; i++)
	{
		knap[0][i] = 0;
	}
	
	// 依次考虑前 i 个物品
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			// 装不下本物品，就是子问题 k[i - 1][j]
			if(j < w[i - 1])
			{
				knap[i][j] = knap[i - 1][j];
			}
			else
			{
				// 不选本物品比较好
				if(knap[i - 1][j] > knap[i - 1][j - w[i - 1]] + v[i - 1])
				{
					knap[i][j] = knap[i - 1][j];
				}
				// 选本物品比较好
				else
				{
					knap[i][j] = knap[i - 1][j - w[i - 1]] + v[i - 1];
					path[i][j] = 1;
				}
			}
		}
	}
	
	printf("value: %d\n", knap[n][W]);
	printf("choose:");
	printSolution(path, n, W);
	return 0;
}