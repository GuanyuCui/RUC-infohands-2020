#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N / 2; i++)
    {
        for(int j = i; j <= N / 2 + 1; j++)
        {
            if((i + j) * (j - i + 1) == 2 * N)
            {
                printf("[%d, %d]\n", i, j);
            }
            if((i + j) * (j - i + 1) > 2 * N)
                break;
        }
    }
    return 0;
}