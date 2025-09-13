//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

void loadData(void) {
    FILE *fp = fopen("sports.dat", "rb");
    if (!fp) return;
    fread(&eventCnt, sizeof(int), 1, fp);
    fread(events, sizeof(Event), eventCnt, fp);
    fclose(fp);
    /* 重建统计 */
    for (int i = 0; i < eventCnt; i++) {
        int s = events[i].sno;
        int sc= events[i].score;
        totalScore[s] += sc;
        if (events[i].sex == MALE) maleScore[s]   += sc;
        else                       femaleScore[s] += sc;
    }
}

void saveData(void) {
    FILE *fp = fopen("sports.dat", "wb");
    if (!fp) { perror("save"); return; }
    fwrite(&eventCnt, sizeof(int), 1, fp);
    fwrite(events, sizeof(Event), eventCnt, fp);
    fclose(fp);
    puts("数据已保存到 sports.dat");
}

void exportRank(void) {
    FILE *fp = fopen("rank.txt", "w");
    if (!fp) return;
    fprintf(fp, "海南大学运动会成绩排名\n");
    fprintf(fp, "=======================\n");
    rankCore(totalScore);
    for (int i = 0; i < 28 && buf[i].key; i++)
        fprintf(fp, "%2d. %-30s %d 分\n", i + 1, department[buf[i].id], buf[i].key);
    fclose(fp);
    puts("排名已导出到 rank.txt");
}

