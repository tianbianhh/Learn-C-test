#include "sport.h"

void modifyScore(void) {
    int s, p, sex, newScore;
    int exitFlag = 0; // 用于标识是否退出修改

    do {
        printf("\n请输入：学院号 项目号 性别(0女1男) 新成绩，或输入-1退出修改：");
        if (scanf("%d", &s) != 1) {
            puts("格式错误！请重新输入。");
            exitFlag = 1;
            break;
        }
        if (s == -1) {
            break; // 用户选择退出
        }
        if (scanf("%d%d%d", &p, &sex, &newScore) != 3) {
            puts("格式错误！请重新输入。");
            exitFlag = 1;
            break;
        }
        if (s < 0 || s >= 28 || p < 0 || p >= projectCnt) {
            puts("编号越界！请重新输入。");
            exitFlag = 1;
            break;
        }

        int idx = findEvent(s, p, sex);
        if (idx == -1) {
            puts("未找到该成绩！请重新输入。");
            exitFlag = 1;
            break;
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
        exitFlag = 0; // 重置退出标志
    } while (exitFlag == 0);

    if (!exitFlag) {
        puts("已退出成绩修改。");
    }
}

