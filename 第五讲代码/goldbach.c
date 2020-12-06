#include <stdio.h>
#include <stdbool.h>

#define N 1000000

// 筛法
void sieve(bool arr[], unsigned int n)
{
	// 均初始化成 1
	for(unsigned int i = 0; i < n + 1; i++)
	{
		arr[i] = 1;
	}
	// 0 和 1 不是质数
	arr[0] = 0;
	arr[1] = 0;
	// 从 2 开始
	for(unsigned int i = 2; i < n + 1; i++)
	{
		// 已经被筛掉了
		if(!arr[i])
			continue;
		// 将其所有倍数筛掉
		for(unsigned int j = 2 * i; j < n + 1; j += i)
		{
			arr[j] = 0;
		}
	}
}

// m 的哥德巴赫分解
void goldbach(bool prime[], int m)
{
	// 最小质数分解，尽可能接近的质数分解，计数
	int minFactor = -1, equalFactor = 3, count = 0;
	// 为什么是 m / 2
	for(int i = 2; i <= m / 2; i++)
	{
		// 如果找到一组分解
		if(prime[i] && prime[m - i])
		{
			// 还没找到过最小分解
			if(minFactor == -1)
			{
				minFactor = i;
			}
			// 动态更新最接近分解
			equalFactor = i;
			// 计数增加
			count++;
		}
	}
	printf("%d+%d %d+%d %d\n", minFactor, m - minFactor, equalFactor, m - equalFactor, count);
}

int main(int argc, char *argv[])
{
	// 1...N
	bool isPrime[N + 1] = {0};
	// 预处理：筛法
	sieve(isPrime, N);
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		int num;
		scanf("%u", &num);
		goldbach(isPrime, num);
	}
	return 0;
}