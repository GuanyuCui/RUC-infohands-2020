#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[1024] = {0};
	gets(str);
	int len = strlen(str);
	
	int sum = 0, oddcount = 0, evencount = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			sum += str[i] - '0';
			oddcount += (str[i] - '0') % 2;
			evencount += !((str[i] - '0') % 2);
		}
	}
	printf("%d %d %d", evencount, oddcount, sum);
	return 0;
}