#include "sport.h"

void inputScore(void) {
    int s, p, sc, sex;
    int exitFlag = 0; // 用于标识是否退出录入

    do {
        printf("\n请输入：学院号 项目号 成绩 性别(0女1男)，或输入-1退出录入：");
        if (scanf("%d", &s) != 1) {
            puts("格式错误！请重新输入。");
            clearInputBuffer(); // 清空输入缓冲区
            continue;
        }
        if (s == -1) {
            break; // 用户选择退出
        }
        if (scanf("%d%d%d", &p, &sc, &sex) != 3) {
            puts("格式错误！请重新输入。");
            clearInputBuffer(); // 清空输入缓冲区
            continue;
        }
        if (s < 0 || s >= 28 || p < 0 || p >= projectCnt) {
            puts("编号越界！请重新输入。");
            continue;
        }

        if (findEvent(s, p, sex) != -1) {
            puts("该成绩已存在，请先修改！");
            continue;
        }

        events[eventCnt].sno  = s;
        events[eventCnt].pid  = p;
        events[eventCnt].score= sc;
        events[eventCnt].sex  = sex;
        eventCnt++;

        totalScore[s] += sc;
        if (sex == MALE) maleScore[s]   += sc;
        else             femaleScore[s] += sc;

        printf("录入成功！%s %s %s 得分 %d\n",
               department[s], project[p], sex?"男":"女", sc);
    } while (1);

    puts("已退出成绩录入。");
}

// 新增函数：清空输入缓冲区
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } // 清空缓冲区直到换行符或文件结束符
}
