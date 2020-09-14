//CNF解析模块儿
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "cnfparser.h"
#include "solver.c"

/*进行SAT，输入SOS判断是解普通文件还是数独，输入文件名*/
void SAT(int SOS,char *filename)
{
    FILE *fp;
    unsigned int var_num,con_num;
    int *lits;
    int i,j;

    fp=fopen(filename,"r");
    if(fp==NULL) {printf("no file\n");return;}
    Cinfo(fp,&var_num,&con_num);

    clause_info *Cla=(clause_info*)malloc(sizeof(clause_info)*con_num);

    for(i=0;i<con_num;i++)
    {
        Cla[i].original_length=CClause(fp,&lits);
        Cla[i].literals=lits;
    }

    Solver S,S0;
    S.var_num=var_num;
    S.con_num=con_num;
    S.base=&Cla[0];
    S.model=(int *)malloc(sizeof(int)*(var_num+1));
    S.model[0]=1;
    for(i=1;i<=var_num;i++)
        S.model[i]=-1;
    S.jixin=(int *)malloc(sizeof(int)*(var_num+1));
    for(i=0;i<=var_num;i++)
        S.jixin[i]=1;
    S0=S;
    int *a,*b;
    a=(int *)malloc(sizeof(int)*(var_num+1));
    b=(int *)malloc(sizeof(int)*(var_num+1));
    for(i=0;i<=var_num;i++)
        a[i]=b[i]=0;
    int y=1;
    for(i=0;i<con_num;i++)
        for(j=0;j<S.base[i].original_length;j++)
        a[abs(S.base[i].literals[j])]++;

    for(i=1;i<=var_num;i++)
    {
        for(j=1;j<=var_num;j++)
        {
            if(a[j]>a[y]) y=j;
        }
        b[i]=y;
        a[y]=0;
        y=1;
    }


printf("******************************\nb[i]=");
for(i=1;i<var_num+1;i++)
    printf("%d ",b[i]);
printf("\n******************************\n");


 //优化前
    int yh=1;
    double start1=clock();
    bool x=DPLL(yh,b,&S,SOS);
    double end1=clock();
    double time1=end1-start1;

    if(!x) printf("unsat!\n");
    if(x!=0)
    {
        for(i=0;i<S.var_num;i++)
            printf("%d ",(i+1)*(S.model[i+1]==0?-1:1));
        printf("\n");
    }
    printf("time: %lfms\n\n",time1);
//数独
    if(SOS==2)
    {
        printf("\nanswer basic on sat:\n");
        int cr=0;
        for(int sx=1;sx<=729;sx++)
        {
            if(S.model[sx]==1)
            {
                if(sx%9==0) printf("9 ");
                else printf("%d ",sx%9);
                cr++;
                if(cr%9==0) printf("\n");
            }
        }
    }

//优化后
    if(SOS==1)
    {
    yh++;
    double start2=clock();
    bool xx=DPLL(yh,b,&S0,SOS);
    double end2=clock();
    double time2=end2-start2;

    if(!xx) printf("unsat!\n");
    if(xx!=0)
    {
        S.model[S.var_num]=S.model[S.var_num]==0?1:0;
        for(i=0;i<S0.var_num;i++)
            printf("%d ",(i+1)*(S0.model[i+1]==0?-1:1));
        printf("\n");
    }
    printf("time: %lfms\n\n",time2);

//计算优化率
    double time3;
    if(time1==0 || time2==0) time3=1;
    else {time3=abs(time1-time2);time3/=time1;}
    time3*=100;
    if(time2>time1) time3*=-1;
    printf("Optimization rate： %lf%%\n\n",time3);

    }
    fclose(fp);

//保存文件
    if(SOS==1)
    {
        int len=strlen(filename);
        filename[len-3]='r';
        filename[len-2]='e';
        filename[len-1]='s';
        FILE *pf=fopen(filename,"w");
        fprintf(pf, "s %d\n",x);
        if(x==1)
        {fprintf(pf, "v ");
        for(i=1;i<=S.var_num;i++)
            fprintf(pf, "%d ",(S.model[i]==0?-1:1)*i);
        fprintf(pf,"\n");}

        fprintf(pf,"t %lf\n",time1);
        fclose(pf);
    }
}


/*读取子句，输入文件名，输出指向首元素地址*/
unsigned int CClause(FILE *fp, int **lits)
{
	unsigned int l=0;
	unsigned space=1;
	int var;
	*lits=(int *)malloc(sizeof(int)*space);

	while(fscanf(fp,"%d",&var))
    {
		if(var!=0)
		{
			if (l==space)
			{
				space++;
				*lits=(int *)realloc(*lits,sizeof(int)*space);
			}
			(*lits)[l++]=var;
		}
		else break;
	}
	*lits=(int *)realloc((*lits), sizeof(int)*l);

	int x;
	for(int i=0;i<l;i++)
        for(int j=0;j<l-i-1;j++)
        if(abs((*lits)[j])>abs((*lits)[j+1]))
        {
            x=(*lits)[j];
            (*lits)[j]=(*lits)[j+1];
            (*lits)[j+1]=x;
        }
	return l;
}

/*读掉c注释，输入文件名*/
void Cline(FILE *fp)
{
	char c;
	while(1)
    {
		fscanf(fp,"%c",&c,sizeof(char));
		if(c=='\n') return;
	}
}

/*读取变元数和子句数，输入文件名*/
void Cinfo(FILE *fp, unsigned int *var_num, unsigned int *con_num)
{
	char c;
	char s[5];
	while (1)
    {
		fscanf(fp,"%c",&c,sizeof(char));
		if (c=='c')
			Cline(fp);
		else if(c=='p')
		{
			fscanf(fp,"%s",s,sizeof(char)*4);
			fscanf(fp,"%ud",var_num);
			fscanf(fp,"%ud",con_num);
			return;
		}
	}
}
