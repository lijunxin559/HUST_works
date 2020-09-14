#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 10
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;



//将元素多样化
typedef struct{
   int No;
   char others[30];
}ElemType;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,* Linklist;

//管理多个单链表的总线性表
typedef struct{
   struct {char name[20];
           Linklist List;
   }elem[100];
   int number = 0;
}table;



status IntiaList(Linklist & L);
status DestroyList(Linklist & L);
status ClearList(Linklist & L);
status ListEmpty(Linklist L);
status ListLength(Linklist L);
status GetElem1(Linklist L,int i,int & e);
status GetElem2(Linklist L,int i,char *str );
status LocateElem1(Linklist L,int e);
status LocateElem2(Linklist L,char *str);
status PriorElem1(Linklist L,int cur,int & pre_e,char *pre_str);
status PriorElem2(Linklist L,char *cur_str,int & pre_e,char *pre_str);
status NextElem1(Linklist L,int cur,int & next_e,char *next_str);
status NextElem2(Linklist L,char *cur_str,int & next_e,char *next_str);
status ListInsert(Linklist & L,int i,int e,char *str);
status ListDelete(Linklist & L,int i,int & e,char *str);
status ListTrabverse(Linklist L);
status TableTrabverse(table T);
status Save_File(table T);
status Load_File(table &T);

int main()
{
    table T;
    int op = 1;
    FILE *fin, *fout;
    int k = 1,m = 0,i,j,e;
    char Str[30],Str1[30];
    char file_name[20];
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
    printf("          8. PriorElem       16.TableTraverse\n");
	printf("          0.Exit\n");
	printf("-------------------------------------------------\n");

    printf("现在建立了一个管理所有链表的总表Table，可以进行建表了。\n");
    if(k != 0)
        printf("您正在对表%d进行操作\n",k);
        printf("    请选择你的操作[0~15]:\n");
	scanf("%d",&op);
	switch(op){
    case 1:
        if(IntiaList(T.elem[m].List)){
            printf("输入单链表的名字：\n");
            scanf("%s",T.elem[m].name);
            ++m;
            ++T.number;
            printf("链表创建成功！该表的编号为%d\n",m);
        }
        else
            printf("线性表创建失败！");

        getchar();getchar();
        break;
     case 2:
		  if(DestroyList(T.elem[k-1].List)==OK)
            printf("线性表销毁成功！");
          else
            printf("线性表销毁失败");
          T.number--;
          getchar();getchar();
		  break;
     case 3:
          if(ClearList(T.elem[k-1].List))
            printf("\n线性表已经清空！\n");
          else
            printf("\n线性表不存在！\n");
          getchar();getchar();
		  break;
	   case 4:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！\n");
         else{
		 if(ListEmpty(T.elem[k-1].List) == OK)
            printf("\n该线性表是空表\n");
         else
            printf("该线性表不是空表！\n");
         }
		 getchar();getchar();
		 break;
	   case 5:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！\n");
         else{
         i = ListLength(T.elem[k-1].List);
         printf("当前表的长度为%d",i);
         }
		 getchar();getchar();
		 break;
	   case 6:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入想要查找的数值的位置：\n");
		 scanf("%d",&i);
		 if(GetElem1(T.elem[k-1].List,i,e)==ERROR||GetElem2(T.elem[k-1].List,i,Str)==ERROR)
            printf("ERROR!");
         else
            printf("数值：%d\n字符串%s\n",e,Str);
         }
		 getchar();getchar();
		 break;
	   case 7:
	     if(!T.elem[k-1].List)
            printf("该线性表不存在！");
         else{
         printf("\n查找数值输入1，查找字符串输入2：\n");
         scanf("%d",&j);
         if(j==1){
	     printf("\n请输入你想要查找的位置的数值：\n");
	     scanf("%d",&i);
	     if(LocateElem1(T.elem[k-1].List,i))
            printf("%d的位置为：%d",i,LocateElem1(T.elem[k-1].List,i));
         else
            printf("ERROR!");
         }
        if(j==2){
         printf("\n请输入你想要查找的位置的字符串：\n");
         scanf("%s",Str);
         if(LocateElem2(T.elem[k-1].List,Str))
            printf("%s的位置为：%d",Str,LocateElem2(T.elem[k-1].List,Str));
         else
            printf("ERROR!");
         }
		 getchar();getchar();
		 break;
	   case 8:
        if(!T.elem[k-1].List)
            printf("该线性表不存在！");
        else{
         printf("\n查找数值输入1，查找字符串输入2：\n");
         scanf("%d",&j);
         if(j==1){
		 printf("\n请输入你想要查找前驱元素的数值：\n");
		 scanf("%d",&i);
		 if(PriorElem1(T.elem[k-1].List,i,e,Str) == ERROR)
            printf("ERROR!");
         else
            printf("前驱是:%d %s",e,Str);
        }
        if(j==2){
		 printf("\n请输入你想要查找前驱元素的字符串：\n");
		 scanf("%s",Str);
		 if(PriorElem2(T.elem[k-1].List,Str,e,Str1) == ERROR)
            printf("ERROR!");
         else
            printf("前驱是:%d %s",e,Str1);
        }
		 getchar();getchar();
		 break;
	   case 9:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！");
         printf("\n查找数值输入1，查找字符串输入2：\n");
         scanf("%d",&j);
         if(j==1){
         printf("\n请输入你想要查找后驱元素的数值\n");
 		 scanf("%d",&i);
 		 if(NextElem1(T.elem[k-1].List,i,e,Str) == ERROR)
            printf("ERROR!");
         else
            printf("后驱是:%d %s",e,Str);
         }
         if(j==2){
		 printf("\n请输入你想要查找后驱元素的字符串：\n");
		 scanf("%s",Str);
		 if(NextElem2(T.elem[k-1].List,Str,e,Str1) == ERROR)
            printf("ERROR!");
         else
            printf("后驱是:%d %s",e,Str1);

         }
 		 getchar();getchar();
		 break;
	   case 10:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入你想插入的位置：\n");
		 scanf("%d",&i);
		 printf("\n请输入你想插入的数值：\n");
		 scanf("%d",&j);
   		 printf("\n请输入你想插入的字符串：\n");
         scanf("%s",Str);
		 if(ListInsert(T.elem[k-1].List,i,j,Str))
            printf("插入成功！\n");
         else
            printf("插入失败！\n");
         }
		 getchar();getchar();
		 break;
	   case 11:
         if(!T.elem[k-1].List)
            printf("该线性表不存在！");
         else{
		 printf("\n请输入你想删除的数据的位置\n");
		 scanf("%d",&i);
		 if(ListDelete(T.elem[k-1].List,i,e,Str)){
            printf("您想要删除位置上值是：%d %s\n",e,Str);
		    printf("删除成功！");
		 }
         else
            printf("ERROR!");
         }
		 getchar();getchar();
		 break;
	   case 12:
        if(!T.elem[k-1].List)
            printf("该线性表不存在！");
        else{
		 if(!ListTrabverse(T.elem[k-1].List))
            printf("线性表是空表！\n");
        }
		 getchar();getchar();
		 break;
       case 13:
         Save_File(T);
         getchar();getchar();
         break;
       case 14:
         Load_File(T);
         getchar();getchar();
         break;
       case 15:
         printf("请输入您想要操作的表编号：\n");
         scanf("%d",&i);
         if(T.number >= i)
            k = i;
         else
            printf("该链表不存在！");
         getchar();getchar();
         break;
         getchar();getchar();
       case 16:
         TableTrabverse(T);
         getchar();getchar();
         break;
	   case 0:
         break;

	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
	}
}
}




status IntiaList(Linklist & L)
{
   L = (Linklist)malloc(sizeof(LNode));
   if(!L) exit (OVERFLOW);
   L->next = NULL;
   L->data.No = 0;
   return OK;
}

status DestroyList(Linklist & L)
{
    Linklist p;
    if(!L)
        return ERROR;
    while(L)
    {
        p = L->next;
        free(L);
        L = p;
    }
    return OK;
}

status ClearList(Linklist & L)
{
    Linklist p,q;
    if(!L)
        return ERROR;
    p = L->next;
    while(p != NULL){
        q = p->next;
        free(q);
        p = q;
    }
    L->next = NULL;
    return OK;

}

status ListEmpty(Linklist L)
{
    if(!L)
        return ERROR;
    if(L->next == NULL)
        return OK;
    else
        return FALSE;
}

status ListLength(Linklist L)
{
    int e = 0;
    Linklist p;
    if(!L)
        return ERROR;
    p = L->next;
    while(p != NULL){
        e++;
        p = p->next;
    }
    return e;
}

status GetElem1(Linklist L,int i,int & e)
{
    if(!L)
        return ERROR;
    Linklist p;
    p = L;
    if(i < 1||i > ListLength(L))
        return ERROR;
    while(i){
        p = p->next;
        i--;
    }
    e = p->data.No;
    return OK;
}

status GetElem2(Linklist L,int i,char *str )
{
    if(!L)
        return ERROR;
    Linklist p;
    p = L;
    if(i < 1||i > ListLength(L))
        return ERROR;
    while(i){
        p = p->next;
        i--;
    }
    strcpy(str,p->data.others);
    return OK;
}

status LocateElem1(Linklist L,int e)
{
    if(!L)
        return ERROR;
     Linklist p;
     p = L->next;
     int i = 1;
     while((p != NULL)&&(p->data.No != e)){
         p = p->next;
         i++;
     }
     if(p == NULL)
        return FALSE;
     else
        return i;

}

status LocateElem2(Linklist L,char* str)
{
    if(!L)
        return ERROR;
    Linklist p;
    p = L->next;
    int i = 1;
         while((p != NULL)&&strcmp(p->data.others,str)){
         p = p->next;
         i++;
     }
     if(p == NULL)
        return FALSE;
     else
        return i;

}
status PriorElem1(Linklist L,int cur,int & pre_e,char *pre_str)
{
    if(!L)
        return ERROR;
    Linklist p,q = NULL;
    p = L->next;
    if(p->data.No == cur)
        return ERROR;
    while(p&&(p->data.No != cur)){
        q = p;
        p = p->next;
    }
    if(p == NULL)
        return ERROR;
    strcpy(pre_str,q->data.others);
    pre_e = q->data.No;
    return OK;
}

status PriorElem2(Linklist L,char *cur_str,int & pre_e,char *pre_str)
{
    if(!L)
        return ERROR;
    Linklist p,q = NULL;
    p = L->next;
    if(!strcmp(p->data.others,cur_str))
        return ERROR;
    while(p&&strcmp(p->data.others,cur_str)){
        q = p;
        p = p->next;
    }
    if(p == NULL)
        return ERROR;
    pre_e = q->data.No;
    strcpy(pre_str,q->data.others);
    return OK;
}

status NextElem1(Linklist L,int cur,int & next_e,char *str)
{
    if(!L)
        return ERROR;
    Linklist p;
    p = L->next;
    while(p&&(p->data.No != cur))
        p = p->next;
    if(!p||!(p->next))
        return ERROR;
    next_e = p->next->data.No;
    strcpy(str,p->next->data.others);
    return OK;
}

status NextElem2(Linklist L,char *cur_str,int & next_e,char *next_str)
{
    if(!L)
        return ERROR;
    Linklist p;
    p = L->next;
    while(p&&strcmp(p->data.others,cur_str))
        p = p->next;
    if(!p||!(p->next))
        return ERROR;
    next_e = p->next->data.No;
    strcpy(next_str,p->next->data.others);
    return OK;
}

status ListInsert(Linklist & L,int i,int e,char *str)
{
    if(!L)
        return ERROR;
    if(i < 1)
        return FALSE;
    Linklist p = L,s;
    int j = 1;
    while(p&&j < i){
        p = p->next;
        ++j;
    }
    s = (Linklist)malloc(sizeof(LNode));
    s->data.No = e;
    strcpy(s->data.others,str);
    s->next = p->next;
    p->next = s;
    return OK;
}

status ListDelete(Linklist & L,int i,int & e,char *str)
{
    if(!L)
        return ERROR;
    if(i < 1||i > ListLength(L))
        return ERROR;
    Linklist p = L,q;
    int j = 0;
    while(p->next&&j < i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next)||j > i-1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data.No;
    strcpy(str,q->data.others);
    free(q);
    return OK;
}

status ListTrabverse(Linklist L)
{
    int i;
    printf("\n-----------all elements -----------------------\n");
    Linklist  p;
    p = L->next;
    for(i = 0;(i < ListLength(L))&&p;i++){
      printf("元素值：%d ",p->data.No);
      printf("字符串：%s\n",p->data.others);
      p = p->next;
    }
    printf("\n------------------ end ------------------------\n");
    return ListLength(L);
}

status TableTrabverse(table T)
{
    int i;
    printf("总表中存了%d个链表。\n",T.number);
    printf("\n-----------all elements -----------------------\n");
    for(i = 0;i < T.number;i++){
        if(T.elem[i].List){
        printf("链表名：%s  ",T.elem[i].name);
        printf("链表编号：%d  ",i+1);
        printf("链表长度：%d\n",ListLength(T.elem[i].List));
        }
    }
    printf("\n------------------ end ------------------------\n");
    return OK;
    }


status Save_File(table T)
{
    FILE *fp;
    int i,m;
    Linklist h;
    char filename[20];
    printf("请输入文件名：\n");
    scanf("%s",filename);
    getchar();
    if((fp = fopen(filename,"wb")) == NULL){
        printf("File open error\n");
        getchar();
        return ERROR;
    }
    //按照链表数、链表名、链表长度、链表中数据结构
    fwrite(&T.number,sizeof(int),1,fp);
    for(i = 0;i < T.number;i++){
       h = T.elem[i].List;
       fwrite(T.elem[i].name,20,1,fp);
       m = ListLength(h);
       fwrite(&m,sizeof(int),1,fp);
       h = h->next;
       while(h){
            fwrite(&h->data,sizeof(ElemType),1,fp);
            h = h->next;
            }
    }
    fclose(fp);
    printf("保存成功！\n");
    return OK;
}

status Load_File(table& T)
{
    FILE *fp;
    int i,j,m,n;
    Linklist h,P;
    ElemType E;
    char filename[20];
    printf("请输入文件名:\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"rb")) == NULL){
        printf("没有找到该文件！\n");
        return ERROR;
    }
    fread(&m,sizeof(int),1,fp);//链表数
    T.number = m;
    for(i = 0;i < m;i++){
        IntiaList(T.elem[i].List);//建立头结点
        fread(T.elem[i].name,20,1,fp);//表名
        fread(&n,sizeof(int),1,fp);//表长
        for(j = 0;j < n;j++){
            fread(&E,sizeof(ElemType),1,fp);//表中数据结构
            ListInsert(T.elem[i].List,j+1,E.No,E.others);//在后面接上结点

    }

    }
    fclose(fp);
    printf("加载成功！");
    return OK;
}

