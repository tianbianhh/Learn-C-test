//
// Created by 天边 on 2025/9/13.
//
#include "sport.h"

/* 查找重复成绩，返回下标或 -1 */
int findEvent(int s, int p, Sex sex) {
    for (int i = 0; i < eventCnt; i++)
        if (events[i].sno == s && events[i].pid == p && events[i].sex == sex)
            return i;
    return -1;
}

/* 删除指定下标成绩（用于修改） */
void delEvent(int idx) {
    if (idx < 0 || idx >= eventCnt) return;
    events[idx] = events[eventCnt - 1];
    eventCnt--;
}