/*Linear Table On Sequence Structure*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define MAX 10
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

//数据元素类型定义
typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

//顺序表（顺序结构）的定义
typedef struct{
	ElemType * elem;
	int length;
	int listsize;
}SqList;


status IntiaList(SqList & L);
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e);
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L,int i,ElemType & e);
status ListTrabverse(SqList L);
status Load_File(SqList &L);
status Save_File(SqList &L);


int main(){
  SqList L[MAX];//存储多个线性表的数组
  int op=1;
  FILE *fin, *fout;
  int m = 0;
  ElemType i,j,e,k = 1;

  while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       9. NextElem\n");
	printf("    	  2. DestroyList     10. ListInsert\n");
	printf("    	  3. ClearList       11. ListDelete\n");
	printf("    	  4. ListEmpty       12. ListTrabverse\n");
	printf("    	  5. ListLength      13.Save_Data\n");
	printf("    	  6. GetElem         14.Load_Data\n");
    printf("          7. LocateElem      15.Change\n");
    printf("          8. PriorElem       0.Exit\n");
	printf("-------------------------------------------------\n");
	if(k!=0)
	    printf("您正在对表%d进行操作\n",k);
        printf("    请选择你的操作[0~15]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList功能待实现！\n");
		 if(IntiaList(L[m])){
           ++m;
           printf("线性表创建成功！该表编号为%d\n",m);
		 }
		 else
           printf("线性表创建失败\n");
		 getchar();getchar();
		 break;
	   case 2:
		  if(DestroyList(L[k-1])==OK)
            printf("线性表销毁成功！");
          else
            printf("线性表销毁失败");
          getchar();getchar();
		  break;
	   case 3:
          if(ClearList(L[k-1]))
            printf("\n线性表已经清空！\n");
          else
            printf("\n线性表不存在！\n");
          getchar();getchar();
		  break;
	   case 4:
		 if(ListEmpty(L[k-1]) == OK)
            printf("\n该线性表是空表\n");
         else
            printf("该线性表不是空表！\n");
		 getchar();getchar();
		 break;
	   case 5:
         i = ListLength(L[k-1]);
         if(i >= 0)
            printf("当前表的长度为%d",i);
         if(i == -1)
            printf("该线性表不存在！");
		 getchar();getchar();
		 break;
	   case 6:
         if(!L[k-1].elem)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入想要查找的数值的位置：\n");
		 scanf("%d",&i);
		 if(GetElem(L[k-1],i,e)==ERROR)
            printf("ERROR!");
         else
            printf("您查找的值为：%d",e);
         }
		 getchar();getchar();
		 break;
	   case 7:
	     if(!L[k-1].elem)
            printf("该线性表不存在！");
         else{
	     printf("\n请输入你想要查找的位置的数值：\n");
	     scanf("%d",&i);
	     if(LocateElem(L[k-1],i))
            printf("%d的位置为：%d",i,LocateElem(L[k-1],i));
         else
            printf("ERROR!");
         }
		 getchar();getchar();
		 break;
	   case 8:
         if(!L[k-1].elem)
            printf("该线性表不存在！");
        else{
		 printf("\n请输入你想要查找前驱元素的数值：\n");
		 scanf("%d",&i);
		 if(PriorElem(L[k-1],i,e) == ERROR)
            printf("ERROR!");
         else
            printf("%d的前驱是%d",i,e);
        }
		 getchar();getchar();
		 break;
	   case 9:
         if(!L[k-1].elem)
            printf("该线性表不存在！");
         else{
         printf("\n请输入你想要查找后驱元素的数值\n");
 		 scanf("%d",&i);
 		 if(NextElem(L[k-1],i,e) == ERROR)
            printf("ERROR!");
         else
            printf("%d的后驱是%d",i,e);
         }
 		 getchar();getchar();
		 break;
	   case 10:
         if(!L[k-1].elem)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入你想插入的位置与数据值\n");
		 scanf("%d %d",&i,&j);
		 ListInsert(L[k-1],i,j);
         }
		 getchar();getchar();
		 break;
	   case 11:
         if(!L[k-1].elem)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入你想删除的数据的位置\n");
		 scanf("%d",&i);
		 if(ListDelete(L[k-1],i,e))
            printf("您想要删除的值是：%d",e);
         else
            printf("ERROR!");
         }
		 getchar();getchar();
		 break;
	   case 12:
        if(!L[k-1].elem)
            printf("该线性表不存在！");
        else{
		 if(!ListTrabverse(L[k-1]))
            printf("线性表是空表！\n");
        }
		 getchar();getchar();
		 break;
       case 13:
         Save_File(L[k-1]);
         getchar();getchar();
         break;
       case 14:
         Load_File(L[k-1]);
         getchar();getchar();
         break;
       case 15:
         printf("请输入您想要操作的表编号：\n");
         scanf("%d",&i);
         k = i;
	   case 0:
         break;

	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()


status IntiaList(SqList & L)
{
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
	L.length = 0;
    L.listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList & L)
{
    if(L.elem)
        free(L.elem);
    else
        return ERROR;
    L.elem = NULL;
    L.length = -1;
    L.listsize = -1;
    return OK;

}

status ClearList(SqList & L)
{
    if(!L.elem)
        return ERROR;
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
{
    if(!L.elem)
        return ERROR;
    if(L.length == 0)
      return TRUE;
    else
      return FALSE;
}

status ListLength(SqList L)
{
    if(!L.elem)
        return -1;
    return L.length;
}

status GetElem(SqList L,int i,ElemType & e)
{
    if(!L.elem)
        return ERROR;
    if(i < 1||(i > L.length ))
        return ERROR;
    e = L.elem[i-1];
    return OK;
}

status LocateElem(SqList L,ElemType e)
{
    int i;
    if(!L.elem)
        return ERROR;
    for(i = 0;i < L.length;i++){
        if(e == L.elem[i])
            return i+1;
    }
    if(i == L.length)
        return FALSE;
}


status PriorElem(SqList L,ElemType cur,ElemType & pre_e)
{
    int i;
    if(!L.elem)
        return ERROR;
    if(LocateElem(L,cur) == 0)
        return ERROR;
    for(i = 1;i < L.length;i++){
        if(cur == L.elem[i]){
            pre_e = L.elem[i-1];
            return pre_e;
        }
    }
    if(i == L.length)
        return FALSE;
}

status NextElem(SqList L,ElemType cur,ElemType & next_e)
{
    int i;
    if(!L.elem)
        return ERROR;
    if(LocateElem(L,cur) == L.length)
        return ERROR;
    for(i = 0;i < L.length-1;i++){
        if(cur == L.elem[i]){
            next_e = L.elem[i+1];
            return OK;
        }
    }
    if(i == L.length-1)
        return FALSE;

}

status ListInsert(SqList & L,int i,ElemType e)
{
    if(!L.elem)
        return ERROR;
    if(i < 1||i > L.length+1)
        return ERROR;
    if(L.length >= L.listsize){
        int *newbase = (ElemType *)realloc(L.elem,LIST_INIT_SIZE + LISTINCREMENT * sizeof (ElemType));
        if(!newbase)
           exit(OVERFLOW);
        L.elem = newbase;
        L.listsize +=LISTINCREMENT;
    }
    ElemType *q = &L.elem[i-1];
    ElemType *p;
    for(p = &(L.elem[L.length-1]);p >=q;p--)
        *(p+1) = *p;
    *q = e;
    L.length++;
    return OK;
}

status ListDelete(SqList & L,int i,ElemType & e)
{
   if(!L.elem)
        return ERROR;
   if(i < 1||i > L.length)
        return ERROR;
   ElemType *p = &(L.elem[i-1]);
   e = *p;
   ElemType *q = L.elem + L.length - 1;
   for(++p;p <= q;++p)
    *(p-1) = *p;
   --L.length;
   return OK;
}

status Save_File(SqList &L)
{
    FILE *fp;
    char filename[30];
    printf("请输入文件名：\n");
    scanf("%s",filename);
    getchar();
    if((fp = fopen(filename,"w")) == NULL){
        printf("File open error\n");
        getchar();
        return ERROR;
    }
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    fclose(fp);
    printf("保存成功！");
    return OK;
}

status Load_File(SqList &L)
{
    FILE *fp;
    char filename[30];
    L.length = 0;
    printf("请输入文件名:\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"rb")) == NULL){
        printf("没有找到该文件！\n");
        return ERROR;
    }
    while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
          L.length++;
    fclose(fp);
    printf("加载成功！");
    return OK;
}

status ListTrabverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i = 0;i < L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}

