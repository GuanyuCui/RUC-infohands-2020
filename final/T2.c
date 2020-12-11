#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    char Raw[10] = {0};
    gets(Raw);
    int Outs[10];
    int OutLen = 0, TmpLen = strlen(Raw);
    char First;
    while(TmpLen > 0)
    {
        char Tmp[10] = {0};
        Outs[OutLen++] = Raw[0] - '0';
        First = Raw[1];
        strcpy(Tmp, Raw + 2);
        memset(Raw, 0, 10);
        strcpy(Raw, Tmp);
        Raw[strlen(Raw)] = First;
        TmpLen--;
    }
    for(int i = 0; i < OutLen; i++)
    {
        printf("%d",Outs[i]);
    }
    return 0;
}