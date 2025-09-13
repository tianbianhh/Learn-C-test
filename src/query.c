#include "sport.h"

void queryByDep(void) {
    int s;
    int exitFlag = 0; // 用于标识是否退出查询

    // 显示学院编号和名称
    printf("\n学院编号对应表：\n");
    for (int i = 0; i < 28; i++) {
        printf("%d. %s\n", i, department[i]);
    }

    do {
        printf("\n请输入学院编号（0-27）或输入-1退出查询：");
        if (scanf("%d", &s) != 1) {
            puts("格式错误！请重新输入。");
            exitFlag = 1;
            break;
        }
        if (s == -1) {
            break; // 用户选择退出
        }
        if (s < 0 || s >= 28) {
            puts("编号越界！请重新输入。");
            exitFlag = 1;
            break;
        }

        int tot = 0, male = 0, female = 0;
        for (int i = 0; i < eventCnt; i++)
            if (events[i].sno == s) {
                tot += events[i].score;
                if (events[i].sex == MALE) male += events[i].score;
                else female += events[i].score;
            }
        printf("【%s】 总分:%d  男团:%d  女团:%d\n",
               department[s], tot, male, female);
        exitFlag = 0; // 重置退出标志
    } while (exitFlag == 0);

    if (!exitFlag) {
        puts("已退出院系查询。");
    }
}

void queryByProj(void) {
    int p;
    int exitFlag = 0; // 用于标识是否退出查询

    // 显示项目编号和名称
    printf("\n项目编号对应表：\n");
    for (int i = 0; i < projectCnt; i++) {
        printf("%d. %s\n", i, project[i]);
    }

    do {
        printf("\n请输入项目编号（0-9）或输入-1退出查询：");
        if (scanf("%d", &p) != 1) {
            puts("格式错误！请重新输入。");
            exitFlag = 1;
            break;
        }
        if (p == -1) {
            break; // 用户选择退出
        }
        if (p < 0 || p >= projectCnt) {
            puts("编号越界！请重新输入。");
            exitFlag = 1;
            break;
        }

        printf("【%s】全部成绩：\n", project[p]);
        for (int i = 0; i < eventCnt; i++)
            if (events[i].pid == p) {
                printf("  %s %s %d 分\n",
                       department[events[i].sno],
                       events[i].sex == MALE ? "男" : "女",
                       events[i].score);
            }
        exitFlag = 0; // 重置退出标志
    } while (exitFlag == 0);

    if (!exitFlag) {
        puts("已退出项目查询。");
    }
}