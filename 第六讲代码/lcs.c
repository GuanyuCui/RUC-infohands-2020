#include <stdio.h>

// acefh
int A[] = {1, 3, 4, 5, 6, 7, 7, 8};
int B[] = {3, 5, 7, 4, 8, 6, 7, 8, 2};

#define m sizeof(A) / sizeof(A[0])
#define n sizeof(B) / sizeof(B[0])

typedef enum _Dir
{
	EDGE, LEFT, UP, LEFTUP
}Dir;

void printSolution(int A[], int p[][n + 1], int i, int j)
{
	// 到头了
	if(i == 0 || j == 0)
	{
		return;
	}
	else if(p[i][j] == LEFTUP)
	{
		printSolution(A, p, i - 1, j - 1);
		printf("%d", A[i]);
	}
	if(p[i][j] == LEFT)
	{
		printSolution(A, p, i, j - 1);
	}
	else if(p[i][j] == UP)
	{
		printSolution(A, p, i - 1, j);
	}
}

int main(int argc, char *argv[])
{
	int c[m + 1][n + 1] = {0};
	int p[m + 1][n + 1] = {0};
	
	// 初始值
	for(int i = 0; i <= m; i++)
	{
		c[i][0] = 0;
		p[i][0] = EDGE;
	}
	for(int i = 0; i <= n; i++)
	{
		c[0][i] = 0;
		c[0][i] = EDGE;
	}
	
	// 填表
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(A[i - 1] == B[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				p[i][j] = LEFTUP;
			}
			else 
			{
				if(c[i][j - 1] > c[i - 1][j])
				{
					c[i][j] = c[i][j - 1];
					p[i][j] = LEFT;
				}
				else
				{
					c[i][j] = c[i - 1][j];
					p[i][j] = UP;
				}
			}
		}
	}
	// 打印
	printf("lcs: ");
	printSolution(A, p, m, n);
	printf("\nlength: %d", c[m][n]);
	return 0;
}