//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

void queryByDep(void) {
    int s;
    printf("请输入学院编号（0-27）：");
    scanf("%d", &s);
    if (s < 0 || s >= 28) { puts("越界！"); return; }

    int tot = 0, male = 0, female = 0;
    for (int i = 0; i < eventCnt; i++)
        if (events[i].sno == s) {
            tot += events[i].score;
            if (events[i].sex == MALE) male += events[i].score;
            else female += events[i].score;
        }
    printf("【%s】 总分:%d  男团:%d  女团:%d\n",
           department[s], tot, male, female);
}

void queryByProj(void) {
    int p;
    printf("请输入项目编号（0-9）：");
    scanf("%d", &p);
    if (p < 0 || p >= projectCnt) { puts("越界！"); return; }

    printf("【%s】全部成绩：\n", project[p]);
    for (int i = 0; i < eventCnt; i++)
        if (events[i].pid == p) {
            printf("  %s %s %d 分\n",
                   department[events[i].sno],
                   events[i].sex == MALE ? "男" : "女",
                   events[i].score);
        }
}

