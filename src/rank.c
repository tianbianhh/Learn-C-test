#include "sport.h"

Node buf[MAXS];  // 不是 static，全局可见

static void qsortNode(Node a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    Node pivot = a[l];
    while (i < j) {
        while (i < j && a[j].key <= pivot.key) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i].key >= pivot.key) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot;
    qsortNode(a, l, i - 1);
    qsortNode(a, i + 1, r);
}

void rankCore(int score[]) {
    for (int i = 0; i < 28; i++) {
        buf[i].key = score[i];
        buf[i].id  = i;
    }
    qsortNode(buf, 0, 27);
}

void rankTotal(void) {
    rankCore(totalScore);
    puts("========== 院系总分排名 ==========");
    for (int i = 0; i < 28 && buf[i].key; i++)
        printf("%2d. %-30s %d 分\n", i + 1, department[buf[i].id], buf[i].key);
}

void rankMale(void) {
    rankCore(maleScore);
    puts("========== 男团总分排名 ==========");
    for (int i = 0; i < 28 && buf[i].key; i++)
        printf("%2d. %-30s %d 分\n", i + 1, department[buf[i].id], buf[i].key);
}

void rankFemale(void) {
    rankCore(femaleScore);
    puts("========== 女团总分排名 ==========");
    for (int i = 0; i < 28 && buf[i].key; i++)
        printf("%2d. %-30s %d 分\n", i + 1, department[buf[i].id], buf[i].key);
}