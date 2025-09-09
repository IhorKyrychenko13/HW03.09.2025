#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(Time_ start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons)
    : startTime(start),
    lessonDuration(lessonDur),
    shortBreak(shortBr),
    longBreak(longBr),
    longBreakAfter(longAfter),
    totalLessons(lessons) {
}
void Schedule::generateSchedule() const {
    Time_ cur = startTime;
    for (int i = 1; i <= totalLessons; i++) {
        Time_ lessonStart = cur;
        Time_ lessonEnd = cur + lessonDuration;
        cout << "Lesson " << i << ": ";
        lessonStart.showTime();
        cout << "   - ";
        lessonEnd.showTime();
        cur = lessonEnd;
        if (i < totalLessons) {
            if (i == longBreakAfter)
                cur += longBreak;
            else
                cur += shortBreak;
        }
    }
}