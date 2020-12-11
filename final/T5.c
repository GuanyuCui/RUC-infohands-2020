//================程序开始===================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void my_strlwr(char Str[])
{
    int Len = strlen(Str);
    for(int i = 0; i < Len; i++)
        if(Str[i] >= 'A' && Str[i] <= 'Z')
            Str[i] += 32;
}

typedef struct _RECORD
{
    char Word[32];
    int Times;
    int Latest;
}Record;
   
Record RcdTb[1024];
int NowWdCnt = 0;
   
int Cmp(const void * A, const void * B)
{
    Record * RcdA = (Record *)A;
    Record * RcdB = (Record *)B;
    if((RcdA -> Times) != (RcdB -> Times))
        return -((RcdA -> Times) - (RcdB -> Times));
    else return strcmp(RcdA -> Word, RcdB -> Word);
}
 
void InputWord(int NowD, char * In)
{
    char * Token = strtok(In, " ");
    bool IsMatched = false;
    while(Token != NULL)
    {
        IsMatched = false;
        for(int i = 0; i < NowWdCnt; i++)
        {
            if(strcmp(Token, RcdTb[i].Word) == 0)
            {
                IsMatched = true;
                if(NowD > RcdTb[i].Latest)
                {
                    RcdTb[i].Times++;
                    RcdTb[i].Latest = NowD;
                }
                break;
            }
        }
        if(!IsMatched)
        {
            strcpy(RcdTb[NowWdCnt].Word, Token);
            RcdTb[NowWdCnt].Times = 1;
            RcdTb[NowWdCnt++].Latest = NowD;
        }
        Token = strtok(NULL, " ");
    }
}
int main(){
    int D, K;
    scanf("%d%d", &D, &K);
    getchar();
    for(int i = 0; i < 1024; i++)
    {
        RcdTb[i].Latest = -1;
        memset(RcdTb[i].Word, 0, sizeof(RcdTb[0].Word));
        RcdTb[i].Times = 0;
    }
    for(int i = 0; i < D; i++)
    {
        char Tmp[1024] = {0};
        gets(Tmp);
        my_strlwr(Tmp);
        InputWord(i, Tmp);
    }
    //printf("%d\n", NowWdCnt);
    qsort(RcdTb, NowWdCnt, sizeof(Record), Cmp);
    for(int i = 0; i < K; i++)
        printf("%s %d\n", RcdTb[i].Word, RcdTb[i].Times);
    return 0;
}
//================程序结束===================