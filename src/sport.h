//
// Created by 天边 on 2025/9/13.
//

#ifndef C_TEST_SPORT_H
#define C_TEST_SPORT_H

#include <stdio.h>   // 标准输入输出
#include <stdlib.h>  // 标准工具函数
#include <string.h>  // 字符串处理
#include <locale.h>  // 本地化（终端中文）

#define MAXS 32     // 最多学院（29+预留）
#define MAXP 16     // 最多项目（10+预留）
#define MAXE 10000  // 成绩池上限

/* 性别枚举 */
typedef enum { FEMALE = 0, MALE = 1 } Sex;

/* 一条成绩记录 */
typedef struct {
    int sno;   // 学院编号 0..28
    int pid;   // 项目编号 0..9
    int score; // 得分
    Sex sex;   // 性别分组
} Event;

/* 排名用的临时结构 */
typedef struct { int key, id; } Node;

/* 全局变量声明 */
extern Event events[MAXE];        // 成绩池数组
extern int   eventCnt;            // 当前已存条数
extern int   totalScore[MAXS];    // 各学院总分
extern int   maleScore[MAXS];     // 各学院男团分
extern int   femaleScore[MAXS];   // 各学院女团分
extern const char *department[MAXS]; // 学院名称表
extern const char *project[MAXP];    // 项目名称表
extern int projectCnt;               // 实际项目数

/* 功能函数声明 */
void inputScore(void);   // 录入成绩
void modifyScore(void);  // 修改成绩
void queryByDep(void);   // 按学院查汇总
void queryByProj(void);  // 按项目查明细
void rankTotal(void);    // 总分排名
void rankMale(void);     // 男团排名
void rankFemale(void);   // 女团排名
void loadData(void);     // 启动读文件
void saveData(void);     // 退出写文件
void exportRank(void);   // 导出 txt 排名

/* 供 fileio.c 使用的 rank.c 内部符号 */
void rankCore(int score[]); // 排名核心函数
extern Node buf[MAXS];      // 排名临时数组

/* 工具函数 */
int  findEvent(int s, int p, Sex sex); // 查重
void delEvent(int idx);              // 删除成绩

#endif //C_TEST_SPORT_H