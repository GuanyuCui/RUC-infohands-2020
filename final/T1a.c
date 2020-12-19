#include <stdio.h>
int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int dj, sl;
	for(int i = 0; i < n; i++)
	{
		scanf("%*s%d%d", &dj, &sl);
		sum += dj * sl;
	}
	printf("%d", sum);
	return 0;
}