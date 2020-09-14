#ifndef CNFPARSER_H_INCLUDED
#define CNFPARSER_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct clause_info{
    int * literals;
    int original_length;
}clause_info;

typedef struct Solver{
    int var_num;
    int con_num;
    clause_info  *base;
    int *model;
    int *jixin;
}Solver;

typedef struct Queen{
    int length;
    int maxlen;
    int head;
    int tail;
    int *base;
}Queen;

typedef struct trails{
    int *trail_0;
    int length;
    int *trail_depth;
    int depth;
}trails;

typedef struct Sudoku {
	int level;
	int game[9][9];
	int ans[9][9];
}Sudoku;

extern unsigned int CClause(FILE *fp, int **lits);//读取子句，输入文件名，输出指向首元素地址
extern void Cline(FILE  *fp);//读掉c注释，输入文件名
extern void Cinfo(FILE  *fp, unsigned int *var_num, unsigned int *con_num);//读取变元数和子句数，输入文件名
extern void SAT(int SOS,char *filename);//进行SAT，输入SOS判断是解普通文件还是数独，输入文件名

extern int cluase_prop(Queen *Q,Solver *S,int i,int Lit,trails *tra);//判断是子句否冲突，输入队列等
extern int prop(Queen *Q,Solver *S,trails *tra);//判断是否冲突，输入公式结构等，冲突返回1
extern void back(trails *tra,Solver *S);//回溯
extern bool DPLL(int yh,int *b,Solver *S,int SOS);//DPLL核心
extern int select_var(int yh,int *b,Solver *S,trails *tra);//挑选元素

extern void in_Q(Queen *Q,int lit);//入队列
extern int out_Q(Queen *Q);//出队列，输出第一个元素
extern void cl_Q(Queen *Q);//清空队列

extern Sudoku *S_begin(int max);//开始新数独，输出数独结构
extern int S_select(Sudoku *sud, int x, int y);//选择下一个格子
extern bool S_creat(Sudoku *sud);//创造数独
extern void S_5(Sudoku *sud, int *x, int *y);//5级挖洞
extern void S_4(Sudoku *sud, int *x, int *y);//4级挖洞
extern void S_3(Sudoku *sud, int *x, int *y);//3级挖洞
extern void S_1_2(Sudoku *sud, int *x, int *y);//1/2级挖洞
extern bool S_only(Sudoku *sud, int x, int  y);//判断解的唯一性
extern bool S_chongtu(Sudoku *sud, int x, int y, int assign);//判断是否冲突
extern bool S_exit(Sudoku *sud);//判断是否存在解
extern void S_cans(Sudoku *sud, Sudoku *temp, int *nof, int x, int y);//判断是否有答案
extern void S_save(Sudoku *sud,FILE * fp,int max);//转cnf文件


#endif // CNFPARSER_H_INCLUDED

