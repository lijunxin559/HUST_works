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

extern unsigned int CClause(FILE *fp, int **lits);//��ȡ�Ӿ䣬�����ļ��������ָ����Ԫ�ص�ַ
extern void Cline(FILE  *fp);//����cע�ͣ������ļ���
extern void Cinfo(FILE  *fp, unsigned int *var_num, unsigned int *con_num);//��ȡ��Ԫ�����Ӿ����������ļ���
extern void SAT(int SOS,char *filename);//����SAT������SOS�ж��ǽ���ͨ�ļ����������������ļ���

extern int cluase_prop(Queen *Q,Solver *S,int i,int Lit,trails *tra);//�ж����Ӿ���ͻ��������е�
extern int prop(Queen *Q,Solver *S,trails *tra);//�ж��Ƿ��ͻ�����빫ʽ�ṹ�ȣ���ͻ����1
extern void back(trails *tra,Solver *S);//����
extern bool DPLL(int yh,int *b,Solver *S,int SOS);//DPLL����
extern int select_var(int yh,int *b,Solver *S,trails *tra);//��ѡԪ��

extern void in_Q(Queen *Q,int lit);//�����
extern int out_Q(Queen *Q);//�����У������һ��Ԫ��
extern void cl_Q(Queen *Q);//��ն���

extern Sudoku *S_begin(int max);//��ʼ����������������ṹ
extern int S_select(Sudoku *sud, int x, int y);//ѡ����һ������
extern bool S_creat(Sudoku *sud);//��������
extern void S_5(Sudoku *sud, int *x, int *y);//5���ڶ�
extern void S_4(Sudoku *sud, int *x, int *y);//4���ڶ�
extern void S_3(Sudoku *sud, int *x, int *y);//3���ڶ�
extern void S_1_2(Sudoku *sud, int *x, int *y);//1/2���ڶ�
extern bool S_only(Sudoku *sud, int x, int  y);//�жϽ��Ψһ��
extern bool S_chongtu(Sudoku *sud, int x, int y, int assign);//�ж��Ƿ��ͻ
extern bool S_exit(Sudoku *sud);//�ж��Ƿ���ڽ�
extern void S_cans(Sudoku *sud, Sudoku *temp, int *nof, int x, int y);//�ж��Ƿ��д�
extern void S_save(Sudoku *sud,FILE * fp,int max);//תcnf�ļ�


#endif // CNFPARSER_H_INCLUDED

