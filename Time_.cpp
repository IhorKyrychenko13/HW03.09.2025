#include "Time_.h"
Time_::Time_() {
    time_t now = time(nullptr);
    tm local{};
    localtime_s(&local, &now);
    hour = local.tm_hour;
    minutes = local.tm_min;
    seconds = local.tm_sec;
    format = true;
}
Time_::Time_(int h, int m, int s, bool f) {
    hour = h; minutes = m; seconds = s; format = f;
    if (!valid()) {
        hour = minutes = seconds = 0;
        format = true;
    }
}
Time_::Time_(const Time_& obj) {
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}
Time_& Time_::operator=(const Time_& obj) {
    if (this != &obj) {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}
Time_::~Time_() {} 
void Time_::setHour(int h) { if (h >= 0 && h < 24) hour = h; }
int Time_::getHour()const { return hour; }

void Time_::setMinutes(int m) { if (m >= 0 && m < 60) minutes = m; }
int Time_::getMinutes()const { return minutes; }

void Time_::setSeconds(int s) { if (s >= 0 && s < 60) seconds = s; }
int Time_::getSeconds()const { return seconds; }

void Time_::setFormat(bool f) { format = f; }
bool Time_::getFormat()const { return format; }
bool Time_::valid()const {
    return (hour >= 0 && hour < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
}

void Time_::tickTime() {
    seconds++;
    if (seconds >= 60) { seconds = 0; minutes++; }
    if (minutes >= 60) { minutes = 0; hour++; }
    if (hour >= 24) hour = 0;
}

void Time_::untickTime() {
    seconds--;
    if (seconds < 0) { seconds = 59; minutes--; }
    if (minutes < 0) { minutes = 59; hour--; }
    if (hour < 0) hour = 23;
}

void Time_::showTime()const {
    int h = hour;
    string ampm = "";
    if (!format) { 
        ampm = (h >= 12) ? " PM" : " AM";
        h = (h % 12 == 0) ? 12 : h % 12;
    }
    cout << (h / 10) << (h % 10) << ":"
        << (minutes / 10) << (minutes % 10) << ":"
        << (seconds / 10) << (seconds % 10)
        << ampm << endl;
}
bool Time_::operator==(const Time_& obj)const& { return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds; }
bool Time_::operator!=(const Time_& obj)const& { return !(*this == obj); }
bool Time_::operator>(const Time_& obj)const& {
    if (hour != obj.hour) return hour > obj.hour;
    if (minutes != obj.minutes) return minutes > obj.minutes;
    return seconds > obj.seconds;
}
bool Time_::operator<(const Time_& obj)const& { return obj > *this; }
bool Time_::operator>=(const Time_& obj)const& { return !(*this < obj); }
bool Time_::operator<=(const Time_& obj)const& { return !(*this > obj); }
Time_& Time_::operator+=(float s) {
    int sec = (int)s;
    for (int i = 0; i < sec; i++) tickTime();
    return *this;
}
Time_& Time_::operator-=(float s) {
    int sec = (int)s;
    for (int i = 0; i < sec; i++) untickTime();
    return *this;
}
Time_& Time_::operator+=(int m) {
    for (int i = 0; i < m * 60; i++) tickTime();
    return *this;
}
Time_& Time_::operator-=(int m) {
    for (int i = 0; i < m * 60; i++) untickTime();
    return *this;
}
Time_& Time_::operator+=(long h) {
    for (int i = 0; i < h * 3600; i++) tickTime();
    return *this;
}
Time_& Time_::operator-=(long h) {
    for (int i = 0; i < h * 3600; i++) untickTime();
    return *this;
}
Time_ Time_::operator+(float s)const& { Time_ tmp = *this; tmp += s; return tmp; }
Time_ Time_::operator-(float s)const& { Time_ tmp = *this; tmp -= s; return tmp; }
Time_ Time_::operator+(int m)const& { Time_ tmp = *this; tmp += m; return tmp; }
Time_ Time_::operator-(int m)const& { Time_ tmp = *this; tmp -= m; return tmp; }
Time_ Time_::operator+(long h)const& { Time_ tmp = *this; tmp += h; return tmp; }
Time_ Time_::operator-(long h)const& { Time_ tmp = *this; tmp -= h; return tmp; }