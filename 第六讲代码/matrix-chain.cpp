#include <iostream>
#include <limits.h>
int p[] = {5, 10, 3, 12, 5, 50, 6};

#define n sizeof(p) / sizeof(p[0]) - 1

void printSolution(int c[][n + 1], int from, int to)
{
	int l = to - from + 1;
	// 单矩阵
	if(l == 1)
	{
		printf("A%d", from);
		return;
	}
	// 递归
	printf("(");
	printSolution(c, from, c[from][to]);
	printSolution(c, c[from][to] + 1, to);
	printf(")");
}

int main(int argc, char *argv[])
{
	int m[n + 1][n + 1] = {0};
	int c[n + 1][n + 1] = {0};
	
	// 链长度
	for(int l = 2; l <= n; l++)
	{
		// 左端点
		for(int i = 1; i <= n - l + 1; i++)
		{
			// l = j - i + 1
			// 右端点
			int j = l - 1 + i;
			
			int minMul = INT_MAX;
			int cut = i;
			// 枚举断开点
			for(int k = i; k < j; k++)
			{
				int mul = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(mul < minMul)
				{
					minMul = mul;
					cut = k;
				}
			}
			m[i][j] = minMul;
			c[i][j] = cut;
		}
	}
	// 打印解
	printSolution(c, 1, n);
	printf("\nCost: %d", m[1][n]);
	return 0;
}