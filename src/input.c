//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

void inputScore(void) {
    int s, p, sc, sex;
    puts("请输入：学院号 项目号 成绩 性别(0女1男)");
    if (scanf("%d%d%d%d", &s, &p, &sc, &sex) != 4) {
        puts("格式错误！"); return;
    }
    if (s < 0 || s >= 28 || p < 0 || p >= projectCnt) {
        puts("编号越界！"); return;
    }

    if (findEvent(s, p, sex) != -1) {
        puts("该成绩已存在，请先修改！"); return;
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
}

