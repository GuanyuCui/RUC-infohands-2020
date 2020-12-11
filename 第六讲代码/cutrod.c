#include <stdio.h>

// 递归打印解
void printSolution(int cut[], int i)
{
	// 没得切
	if(i == 0)
	{
		return;
	}
	// 第一段
	printf("%d ", cut[i]);
	// 后面一段
	printSolution(cut, i - cut[i]);
}

int main(int argc, char *argv[])
{
	// 不同长度的价值
	int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	
#define n sizeof(p) / sizeof(p[0])
	
	// 最优切割收益
	int r[n] = {0};
	// 第一段切割长度
	int cut[n] = {0};
	
	// 填表 1 ~ n-1
	for(int k = 1; k < n; k++)
	{
		// 动态更新最大收益和第一段长度
		int maxValue = p[k];
		int cutl = k;
		// 遍历第一段的长度
		for(int i = 1; i < k; i++)
		{
			if(p[i] + r[k - i] > maxValue)
			{
				maxValue = p[i] + r[k - i];
				cutl = i;
			}
		}
		r[k] = maxValue;
		cut[k] = cutl;
	}
	
	// 打印结果
	for(int i = 1; i < n; i++)
	{
		printf("长度为 %d 的钢条切割方案:", i);
		printSolution(cut, i);
		printf("\n");
		printf("价值: %d\n", r[i]);
	}
	return 0;
}