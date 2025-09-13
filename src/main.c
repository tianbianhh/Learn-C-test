#include "sport.h"

Event events[MAXE] = {0};      // 成绩池数组
int   eventCnt       = 0;      // 当前已存条数
int   totalScore[MAXS] = {0};  // 各学院总分
int   maleScore[MAXS]  = {0};  // 各学院男团分
int   femaleScore[MAXS]= {0};  // 各学院女团分
const char *department[MAXS] = {
    "人文学院", "国际商学院", "法学院", "马克思主义学院",
    "体育学院", "外国语学院国际传播与艺术学院", "数学与统计学院",
    "物理与光电工程学院", "化学化工学院", "海洋科学与工程学院",
    "生命健康学院", "生态学院", "机电工程学院", "材料科学与工程学院",
    "生物医学工程学院", "电子科学与技术学院", "海洋生物与水产学院",
    "信息与通信工程学院", "计算机科学与技术学院", "食品科学与工程学院",
    "土木建筑工程学院", "网络空间安全学院", "环境科学与工程学院",
    "热带农林学院", "药学院", "国际旅游与公共管理学院",
    "纪检监察学院", "预留A", "预留B", "预留C"
};
const char *project[MAXP] = {
    "50米", "100米", "200米", "400米", "1500米",
    "跳高", "跳远", "标枪", "铅球", "铁饼"
};
int projectCnt = 10; // 实际项目数

int main(void) {
    puts("==================================================");
    puts("||  海南大学运动会成绩数据库 —— C11 版      ||");
    puts("==================================================");

    loadData(); // 启动时读文件

    int choice;
    do {
        puts("\n========== 主菜单 ==========");
        puts("1.录入成绩 2.修改成绩 3.院系汇总 4.项目明细");
        puts("5.总分排名 6.男团排名 7.女团排名 8.导出排名");
        puts("9.显示学院和项目对应表 0.退出");
        printf("请选择：");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
        case 1: inputScore(); break;
        case 2: modifyScore(); break;
        case 3: queryByDep();  break;
        case 4: queryByProj(); break;
        case 5: rankTotal();   break;
        case 6: rankMale();    break;
        case 7: rankFemale();  break;
        case 8: exportRank();  break;
        case 9: displayTables(); break; // 显示对应表
        case 0: puts("感谢使用！"); break;
        default: puts("输入无效！");
        }
    } while (choice != 0);

    saveData(); // 退出时保存
    return 0;
}


void displayTables() {
    // 显示学院编号和名称
    printf("\n学院编号对应表：\n");
    for (int i = 0; i < 28; i++) {
        printf("%d. %s\n", i, department[i]);
    }

    // 显示项目编号和名称
    printf("\n项目编号对应表：\n");
    for (int i = 0; i < projectCnt; i++) {
        printf("%d. %s\n", i, project[i]);
    }

    printf("\n按任意键继续...");
    getchar(); // 等待用户按键
    getchar(); // 清除输入缓冲区
}

