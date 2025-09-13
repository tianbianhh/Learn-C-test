//
// Created by 天边 on 2025/9/13.
//

#ifndef C_TEST_SPORT_H
#define C_TEST_SPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAXS 32
#define MAXP 16
#define MAXE 10000

typedef enum { FEMALE = 0, MALE = 1 } Sex;
typedef struct { int key, id; } Node;

typedef struct {
    int sno;
    int pid;
    int score;
    Sex sex;
} Event;

/* 全局变量声明 */
extern Event events[MAXE];
extern int   eventCnt;
extern int   totalScore[MAXS];
extern int   maleScore[MAXS];
extern int   femaleScore[MAXS];
extern const char *department[MAXS];
extern const char *project[MAXP];
extern int projectCnt;

/* 功能函数声明 */
void inputScore(void);
void modifyScore(void);
void queryByDep(void);
void queryByProj(void);
void rankTotal(void);
void rankMale(void);
void rankFemale(void);
void loadData(void);
void saveData(void);
void exportRank(void);
void displayTables(void);

/* 供外部使用的 rank 符号 */
extern Node buf[MAXS];
void rankCore(int score[]);

/* 工具函数 */
int  findEvent(int s, int p, Sex sex);
void delEvent(int idx);

#endif //C_TEST_SPORT_H
