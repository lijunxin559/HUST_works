#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cnfparser.c"
#include "Sudoku.c"

int main()
{
    while(1)
    {
        FILE *fp;
        int x,m,n;
        char file_name[100];
        printf("Please choose SAT(1) or Sudoku(2) or Quit(0):");
        scanf("%d",&x);
        if(x==0) break;
        else if(x==1)
        {
            printf("Please input the name of file:");
            scanf("%s",file_name);
            printf("\n");
            SAT(x,file_name);
        }
        else if(x==2)
        {
            printf("Please choose holes(20-59):");
            scanf("%d",&m);

            if(m<21||m>59)
            {
                printf("bad num!\n");
                continue;
            }
            Sudoku *sud=S_begin(m);
            printf("Please input the name of file:");
            scanf("%s",file_name);
            fp=fopen(file_name,"w");
            S_save(sud,fp,m);
            fclose(fp);
            printf("\ngame:\n");

            for (int xx=0;xx<9;xx++)
            {
                for (int yy=0;yy<9;yy++)
                {
                    if (sud->game[xx][yy]==0)
                    printf(". ");
                    else
                    printf("%d ", sud->game[xx][yy]);
                }
            printf("\n");
            }//end for
            printf("\n");

            SAT(x,file_name);

            printf("\nanswer:\n");
            for (int xx=0;xx<9;xx++)
            {
                for (int yy=0;yy<9;yy++)
                {
                    if (sud->ans[xx][yy]==0)
                    printf(". ");
                    else
                    printf("%d ", sud->ans[xx][yy]);
                }
            printf("\n");
            }//end for
            printf("\n");

        }
        else printf("bad num try again!\n");
    }
    return 0;
}

