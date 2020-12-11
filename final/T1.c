#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct _GOODS
{
    char Name[128];
    int Price;
    int Count;
}Goods;
 
int main()
{
    Goods Gds[100];
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s%d%d", Gds[i].Name, &Gds[i].Price, &Gds[i].Count);
    }
    int Sum = 0;
    for(int i = 0; i < N; i++)
    {
        Sum += Gds[i].Price * Gds[i].Count;
    }
    printf("%d", Sum);
    return 0;
}