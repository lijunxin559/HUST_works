//核心DPLL模块儿
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "cnfparser.h"

/*判断是子句否冲突，输入队列等*/
int cluase_prop(Queen *Q,Solver *S,int i,int Lit,trails *tra)
{
    int x_f = 0,x_u = 0,u=0;
    clause_info cla=S->base[i];
    int n=abs(cla.literals[0]);
    if((S->model[n]==1 && cla.literals[0]>0)||(S->model[n]==0 &&cla.literals[0]<0))
        return 0;
    for(int j=0;j<cla.original_length;j++)
    {
        n=abs(cla.literals[j]);
        if((S->model[n])==-1) {x_u++;u=cla.literals[j];}
        else
        {
            if((S->model[n]==1 && cla.literals[j]>0)||(S->model[n]==0 &&cla.literals[j]<0))
            {
                int x=cla.literals[j];
                cla.literals[j]=cla.literals[0];
                cla.literals[0]=x;
                return 0;
            }
            else x_f++;
        }
    }
    if(x_f==cla.original_length) return 1;
    if(x_f==cla.original_length-1 && x_u==1)
    {
        in_Q(Q,u);
        (tra->trail_0)[tra->length]=u;
        S->model[abs(u)]=u>0?1:0;
        (tra->length)++;
        (tra->trail_depth)[tra->depth]++;
    }
    return 0;
}


/*判断是否冲突，输入公式结构等，有冲突返回1*/
int prop(Queen *Q,Solver *S,trails *tra)
{
    if(Q->length==0) return 0;
    else{
        while(Q->length!=0)
        {
            int Lit=out_Q(Q);
            for(int i=0;i<S->con_num;i++)
                if(cluase_prop(Q,S,i,Lit,tra))
                {
                    cl_Q(Q);
                    return 1;
                }
        }
    }return 0;
}

/*回溯*/
void back(trails *tra,Solver *S)
{
	if (tra->depth == 0) return;
   int m=0;
   for(int i=0;i<(tra->trail_depth)[tra->depth];i++)
   {
       int n=(tra->trail_0)[(tra->length)-1];
       if(i+1==(tra->trail_depth)[tra->depth]&&S->jixin[abs(n)]==1)
			m=abs(n);

	   S->model[abs(n)]=-1;
       (tra->trail_0)[(tra->length)-1]=0;
       (tra->length)--;
   }
   (tra->trail_depth)[tra->depth]=0;
   (tra->depth)--;
   if(m!=0)
    back(tra,S);
}

/*DPLL核心算法*/
bool DPLL(int yh,int *b,Solver *S,int SOS)
{
    trails tra;
    tra.trail_0 = (int *)malloc(sizeof(int )* S->var_num);
    for(int i=0;i<S->var_num;i++)
        tra.trail_0[i]=0;
    tra.length=0;
    tra.trail_depth = (int *)malloc(sizeof(int )*(S->var_num+1));
    for(int i=0;i<=S->var_num;i++)
        tra.trail_depth[i]=0;
    tra.depth = 0;

    Queen Q;
    Q.maxlen=S->var_num+1;
    Q.length=0;
    Q.head=0;
    Q.tail=0;
    Q.base=(int *)malloc(sizeof(int)*Q.maxlen);

    if(SOS==2)
    {
        for(int i=0;i<S->con_num;i++)
            if(S->base[i].original_length==1)
            {
                S->model[abs(S->base[i].literals[0])]=S->base[i].literals[0]>0?1:0;
                tra.trail_0[tra.length]=S->base[i].literals[0];
                tra.length++;
            }
    }
    int fir = 1;
    for(int i =1; i <= S->var_num;i++){
        if(S->model[i]==-1)
        {
            fir = i;
            break;

        }
    }

    while(1)
    {
        if(prop(&Q,S,&tra))
        {
            back(&tra,S);
			if (tra.depth == 0 && S->jixin[fir] == 1) return false;
        }
        else
        {
            if(tra.length==S->var_num)
            {
                return true;
            }
            else
            {
                int var = select_var(yh,b,S,&tra);
                int lit=(S->jixin[var])*var;
                S->model[var]=S->jixin[var]==1?1:0;
                S->jixin[var]*=-1;
                in_Q(&Q,var);
                tra.trail_0[tra.length]=lit;
                tra.length++;
                tra.trail_depth[tra.depth]++;
            }
        }
    }
}

/*挑选元素*/
int select_var(int yh,int *b,Solver *S,trails *tra)
{
    for(int i=1;i<=S->var_num;i++)
    {
        int mm=(yh==1)?i:b[i];
		if (S->model[mm] == -1) {
			(tra->depth)++;
			return mm;
		}//end_if
    }//end_for
}
/*入队*/
void in_Q(Queen *Q,int lit)
{
    Q->base[Q->tail]=lit;
    Q->tail=(Q->tail+1)%Q->maxlen;
    Q->length++;
}
/*出队，返回首元素*/
int out_Q(Queen *Q)
{
    int lit=0;
    if(Q->length){
        lit=Q->base[Q->head];
    Q->head=(Q->head+1)%Q->maxlen;
    Q->length--;}
    return lit;
}
/*清空队列*/
void cl_Q(Queen *Q)
{
    Q->head=0;
    Q->tail=0;
    Q->length=0;
}
