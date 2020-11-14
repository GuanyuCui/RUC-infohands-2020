#include <stdio.h>

int main(int argc, char *argv[])
{
	int w1, w2, w3;
	scanf("%d%d%d", &w1, &w2, &w3);
	int c1, c2, c3;
	scanf("%d%d%d", &c1, &c2, &c3);
	
	int totalWeight[10001] = {0};
	for(int i = 0; i <= c1; i++)
	{
		for(int j = 0; j <= c2; j++)
		{
			for(int k = 0; k <= c3; k++)
			{
				totalWeight[w1 * i + w2 * j + w3 * k]++;
			}
		}
	}
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		int w;
		scanf("%d", &w);
		printf("%d ", totalWeight[w]);
	}
	return 0;
}