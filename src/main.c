//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

/* 定义全局变量 */
Event events[MAXE] = {0};      // 成绩池，初始清零
int   eventCnt       = 0;      // 当前已录入条数
int   totalScore[MAXS] = {0};  // 各学院总分
int   maleScore[MAXS]  = {0};  // 各学院男团分
int   femaleScore[MAXS]= {0};  // 各学院女团分

/* 29 个学院名称（按你给出顺序） */
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

/* 10 个田径项目 */
const char *project[MAXP] = {
    "50米", "100米", "200米", "400米", "1500米",
    "跳高", "跳远", "标枪", "铅球", "铁饼"
};
int projectCnt = 10; // 实际项目数

int main(void) {
    setlocale(LC_ALL, ""); // 让终端正确显示中文
    puts("==================================================");
    puts("||  海南大学运动会成绩数据库 —— C11 版      ||");
    puts("==================================================");

    loadData(); // 启动时读文件

    int choice;
    do {
        puts("\n========== 主菜单 ==========");
        puts("1.录入成绩 2.修改成绩 3.院系汇总 4.项目明细");
        puts("5.总分排名 6.男团排名 7.女团排名 8.导出排名");
        puts("0.退出");
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
            case 0: puts("感谢使用！"); break;
            default: puts("输入无效！");
        }
    } while (choice != 0);

    saveData(); // 退出时保存
    return 0;
}