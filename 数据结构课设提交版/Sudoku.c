#include "cnfparser.h"

/*开始新数独，输出数独结构*/
Sudoku *S_begin(int max)
{
	Sudoku *sud=(Sudoku *)malloc(sizeof(Sudoku));
	bool dig[9][9];
	int limr[10],limc[10],lim;
	int x,y,cdig=81,done=0;
	void(*dig_next)(Sudoku *,int *,int *)=NULL;

	do{
            for(x=0;x<9;x++)
            for(y=0;y<9;y++)
            sud->game[x][y]=0;
	} while (!S_creat(sud));
	for(x=0;x<9;x++)
        for(y=0;y<9;y++)
        sud->ans[x][y]=sud->game[x][y];

	for (x=1;x<=9;x++)
		{
		    limr[x]=9;
		    limc[x]=9;
        }
	for (x=0;x<9;x++)
		for (y=0;y<9;y++)
			dig[x][y]=1;
    int level;
    if(20<=max && max<32) level=1;
    if(32<=max && max<46) level=2;
    if(46<=max && max<50) level=3;
    if(50<=max && max<54) level=4;
    if(54<=max && max<60) level=5;

	switch(level)
	{
        case 1:
            dig_next=S_1_2;
            lim=5;
            break;
        case 2:
            dig_next=S_1_2;
            lim=4;
            break;
        case 3:
            dig_next=S_3;
            lim=3;
            break;
        case 4:
            dig_next=S_4;
            lim=2;
            break;
        case 5:
            dig_next=S_5;
            lim=0;
            break;
	}
    sud->level=level;
	x=rand()%9;
	y=rand()%9;
	while(cdig)
    {
		dig_next(sud,&x,&y);
		if (!dig[x][y])
			continue;
		if(limr[y]==lim || limc[x]==lim || done>=max)
		{
			dig[x][y]=0;
			cdig--;
			if (done>=max)
				break;
		}
		else if (S_only(sud,x,y))
        {
			sud->game[x][y]=0;
			limr[y]--;
			limc[x]--;
			done++;
			dig[x][y]=0;
			cdig--;
		}
		else
		{
			dig[x][y]=0;
			cdig--;
		}
	}
	return sud;
}

/*创造数独*/
bool S_creat(Sudoku *sud)
{
	int x,y,n,i=0;
	while(i<11)
    {
		x=rand()%9;
		y=rand()%9;
		if(sud->game[x][y])
			continue;
		else
		{
			sud->game[x][y]=S_select(sud,x,y);
			i++;
		}
	}
	for(x=0;x<9;x++)
		for(y=0;y<9;y++)
			if(!sud->game[x][y])
            {
				n=S_select(sud,x, y);
				if (!n)
					return false;
				sud->game[x][y]=n;
			}
	return true;
}

/*选择下一个格子*/
int S_select(Sudoku *sud,int x,int y)
{
	int mark[10];
	mark[0]=9;
	for(int i=1;i<10;i++)
        mark[i]=0;
	int m,var,xb,xe,yb,ye,x_0,y_0;

	for (m=0;m<9;m++)
    {
		var=sud->game[m][y];
		if(var)
		{
			if(!mark[var])
            {
				mark[var]++;
				mark[0]--;
			}
		}

		var=sud->game[x][m];
		if(var)
		{
			if (!mark[var])
            {
				mark[var]++;
				mark[0]--;
			}
		}
	}

	if(x<3)	xb=0;
	else if(6<=x) xb=6;
	else xb=3;

	if(y<3)	yb=0;
	else if(6<=y) yb=6;
	else yb=3;

	xe=xb+3;
	ye=yb+3;

	for(x_0=xb;x_0<xe;x_0++)
		for(y_0=yb;y_0<ye;y_0++)
		{
			var=sud->game[x_0][y_0];
			if(var)
			{
				if (!mark[var])
                {
					mark[var]++;
					mark[0]--;
				}
			}
		}

	if (!mark[0]) return 0;

	for(int start=(rand()%9)+1;;start++)
    {
        if(mark[start%10]==0)
            return start%10;
    }
}

/*1/2级挖洞*/
void S_1_2(Sudoku *sud,int *x,int *y)
{
	*x=rand()%9;
	*y=rand()%9;
}

/*3级挖洞*/
void S_3(Sudoku *sud,int *x,int *y)
{
    for(int i=0;i<2;i++)
    {
        static int m = 1;
        if((*y)+m<9 && (*y)+m>= 0) (*y)+=m;
	    else if ((*x)<8)
        {
            (*x)++;
            m*=-1;
        }
        else
        {
            (*x)=0;
            m*=-1;
        }
    }
}

/*4级挖洞*/
void S_4(Sudoku *sud,int *x,int *y)
{
	static int m=1;
	if((*y)+m<9 && (*y)+m>=0) (*y)+=m;
	else if((*x)<8)
	{
		(*x)++;
		m*=-1;
	}
	else
	{
		(*x)=0;
		m*=-1;
	}
}

/*5级挖洞*/
void S_5(Sudoku *sud,int *x,int *y)
{
	if((*y)<8) (*y)++;
	else if((*x)<8)
    {
		(*x)++;
		(*y)=0;
	}
	else
	{
		(*y)=0;
		(*x)=0;
	}
}

/*判断解的唯一性*/
bool S_only(Sudoku *sud,int x,int y)
{
	int n=sud->game[x][y],i;
	for(i=1;i<10;i++)
    {
		sud->game[x][y]=0;
		if (i==n) continue;
		if (S_chongtu(sud, x, y, i)) continue;
		else sud->game[x][y]=i;

		if (S_exit(sud))
        {
			sud->game[x][y]=n;
			return false;
		}
	}
	sud->game[x][y]=n;
	return true;
}

/*判断是否有冲突*/
bool S_chongtu(Sudoku *sud,int x,int y,int a)
{
	int m,var,xb,xe,yb,ye,x_0,y_0;

	for(m=0;m<9;m++)
    {
		var=sud->game[m][y];
		if(var==a) return true;
		var=sud->game[x][m];
		if(var==a) return true;
	}
	if(x<3) xb=0;
	else if(6<=x) xb=6;
	else xb=3;

	if(y<3) yb=0;
	else if(6<=y) yb = 6;
	else yb=6;

	xe=xb+3;
	ye=yb+3;

	for(x_0=xb;x_0<xe;x_0++)
		for(y_0=yb;y_0<ye;y_0++)
        {
			var=sud->game[x_0][y_0];
			if(var==a) return true;
		}
	return false;
}

/*判断是否存在解*/
bool S_exit(Sudoku *sud)
{
	Sudoku temp=*sud;
	int nof=81;
	S_cans(sud,&temp,&nof,0,0);
	if(nof==0) return true;
	return false;
}

/*判断是否有答案*/
void S_cans(Sudoku *sud,Sudoku *temp,int *nof,int x,int y)
{
	if((*nof)==0) return;
	if(sud->game[x][y])
	{
		(*nof)--;
		int x_0, y_0;
		if (y<8)
		{
			x_0=x;
			y_0=y+1;
		}
		else
		{
			x_0=x+1;
			y_0=0;
		}
		S_cans(sud,temp,nof,x_0,y_0);
		if((*nof)==0) return;
		(*nof)++;
	}
	else
	{
		int mark[10];
		mark[0]=9;
		for(int i=1;i<10;i++)
            mark[i]=0;
		int m,var,xb,xe,yb,ye,x_0,y_0;

		for (m=0;m<9;m++)
        {
			var=temp->game[m][y];
			if(var)
			{
				if(!mark[var])
				{
					mark[var]++;
					mark[0]--;
				}
			}

			var=temp->game[x][m];
			if(var)
			{
				if (!mark[var])
                {
					mark[var]++;
					mark[0]--;
				}
			}
		}

		{
			if(x<3)	xb=0;
			else if(6<=x) xb=6;
			else xb=3;

			if(y<3)	yb=0;
			else if(6<=y) yb=6;
			else yb=3;

			xe=xb+3;
			ye=yb+3;

			for(x_0=xb;x_0<xe;x_0++)
				for(y_0=yb;y_0<ye;y_0++)
                {
					var=temp->game[x_0][y_0];
					if(var)
					{
						if (!mark[var])
						{
							mark[var]++;
							mark[0]--;
						}
					}
				}
		}

		if(!mark[0]) return ;
		else
        {
			int i;
			for(i=1;i<=9;i++)
			{
				if(mark[i]==0)
				{
					(*nof)--;
					temp->game[x][y]=i;
					int x_0, y_0;
					if(y<8)
					{
						x_0=x;
						y_0=y+1;
					}
					else
					{
						x_0=x+1;
						y_0=0;
					}
					S_cans(sud,temp,nof,x_0,y_0);
					if((*nof)==0) return;
					temp->game[x][y]=0;
					(*nof)++;
				}
			}
		}
	}
}

/*转cnf文件*/
void S_save(Sudoku *sud,FILE *fp,int max)
{

	int un=0;
	int x,y,i,j,t=0;
    fprintf(fp,"c sudoku,holes£º%d\n",max);
	fprintf(fp,"c game:\n");
	for (x=0;x<9;x++)
    {
		fprintf(fp,"c ");
		for (y=0;y<9;y++)
		{
			if(sud->game[x][y]==0) fprintf(fp, ". ");
			else fprintf(fp,"%d ",sud->game[x][y]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"c ans:\n");
	for(x=0;x<9;x++)
	{
		fprintf(fp,"c ");
		for(y=0;y<9;y++)
		{
			if(sud->ans[x][y]==0) fprintf(fp,". ");
			else fprintf(fp, "%d ", sud->ans[x][y]);
		}
		fprintf(fp, "\n");
	}
	for(x=0;x<9;x++)
		for(y=0;y<9;y++)
			if(sud->game[x][y]) un++;

	fprintf(fp,"p cnf 729 %d\n",un*9+(81-un)*37+3*81);

	for(x=0;x<9;x++)
    {
		for(y=0;y<9;y++)
		{
			if(sud->game[x][y])
			{
				for(i=1;i<=9;i++)
				{
					if (i!=sud->game[x][y])
					{
						fprintf(fp,"-%d 0\n",(x*81+y*9)+i);
						t++;
                    }
					else
					{
						fprintf(fp,"%d 0\n",(x*81+y*9)+i);
						t++;
					}
				}
			}
			else
			{
				for(i=1;i<=9;i++)
				{
					for(j=i+1;j<=9;j++)
					{
						fprintf(fp,"-%d -%d 0\n",(x*81+y*9)+i,(x*81+y*9)+j);
						t++;
					}
				}
				for(i=1;i<=9;i++) fprintf(fp, "%d ", (x * 81 + y * 9) + i);
				fprintf(fp, "0 \n");
				t++;
			}
		}
	}

	for(i=1;i<=9;i++)
    {
		for(x=0;x<9;x++)
		{
			for(y=0;y<9;y++) fprintf(fp,"%d ",(x*81+y*9)+i);
			t++;
			fprintf(fp,"0 \n");
			for(y=0;y<9;y++) fprintf(fp,"%d ",(y*81+x*9)+i);
			t++;
			fprintf(fp,"0 \n");
		}
	}

	for(i=1;i<=9;i++)
		for(x=0;x<3;x++)
			for(y=0;y<3;y++)
            {
				int xx,yy;
				for(xx=0;xx<3;xx++)
				{
					for(yy=0;yy<3;yy++)
						fprintf(fp,"%d ",(x*3+xx)*81+(y*3+yy)*9+i);
				}
				t++;
				fprintf(fp,"0 \n");
			}
}
