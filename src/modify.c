//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

void modifyScore(void) {
    int s, p, sex, newScore;
    puts("请输入：学院号 项目号 性别(0女1男) 新成绩");
    if (scanf("%d%d%d%d", &s, &p, &sex, &newScore) != 4) {
        puts("格式错误！"); return;
    }
    int idx = findEvent(s, p, sex);
    if (idx == -1) {
        puts("未找到该成绩！"); return;
    }

    int old = events[idx].score;
    totalScore[s] -= old;
    if (sex == MALE) maleScore[s]   -= old;
    else             femaleScore[s] -= old;

    events[idx].score = newScore;
    totalScore[s] += newScore;
    if (sex == MALE) maleScore[s]   += newScore;
    else             femaleScore[s] += newScore;

    printf("修改成功！新成绩 %d 分\n", newScore);
}
