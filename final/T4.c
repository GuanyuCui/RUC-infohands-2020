//
// Query函数参数说明
// int n, 表示学生总人数
// char *id 指向待查学生学号的字符指针
// int *prk 存放查询结果的地址
//================程序开始===================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct _STU
{
    char Num[21];
    int Grade;
    int Rank;
}Students;
 
int Cmp(const void * A, const void *B)
{
    Students * StuA = (Students *) A;
    Students * StuB = (Students *) B;
    return -(StuA[0].Grade - StuB[0].Grade);
}
 
// Query函数，它本身可再调用其它子函数。
void Query(int n, char *id, int *prk)
{
    Students Stus[200];
    for(int i = 0; i < n; i++)
        scanf("%s%d", Stus[i].Num, &Stus[i].Grade); 
     
    qsort(Stus, n, sizeof(Students), Cmp);
    Stus[0].Rank = 1;
    if(strcmp(id, Stus[0].Num) == 0)
    {
        *prk = Stus[0].Rank;
        return;
    }
    for(int i = 1; i < n; i++)
    {
        if(Stus[i].Grade == Stus[i - 1].Grade)
        {
            Stus[i].Rank = Stus[i - 1].Rank;
        }
        else Stus[i].Rank = i + 1;
         
        if(strcmp(id, Stus[i].Num) == 0)
        {
            *prk = Stus[i].Rank;
            return;
        }
    }
     
}
  
int main(){
  
    char stu_id[21];        //学生学号，以字符表示
    int rank = 0;           //名次
    int n;              //总人数
  
    scanf("%d%s", &n, stu_id);
    Query(n, stu_id, &rank);
  
    printf("%d\n", rank);
    return 0;
}
//================程序结束===================