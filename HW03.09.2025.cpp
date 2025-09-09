#include "Time_.h"
#include "Schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "===== Завдання 1: Перевірка класу Time_ =====\n\n";
    Time_ now;                 
    Time_ t1(12, 59, 58, true);  
    now.showTime();
    t1.showTime();
    cout << "--------------------------------------------\n";
    now.tickTime(); 
    t1.untickTime();
    now.showTime();
    t1.showTime();
    cout << "--------------------------------------------\n";
    t1.setHour(15);
    t1.setMinutes(70); 
    t1.setSeconds(30);
    t1.showTime();
    cout << "--------------------------------------------\n";
    t1.showTime();
    now.showTime();
    cout << " == " << boolalpha << (t1 == now) << endl;
    cout << " != " << boolalpha << (t1 != now) << endl;
    cout << " > " << boolalpha << (t1 > now) << endl;
    cout << " < " << boolalpha << (t1 < now) << endl;
    cout << " >= " << boolalpha << (t1 >= now) << endl;
    cout << " <= " << boolalpha << (t1 <= now) << endl;
    cout << "--------------------------------------------\n";
    t1.showTime();
    t1 += 5.f;  
    t1.showTime();
    t1 += 2;    
    t1.showTime();
    t1 += 1l;  
    t1.showTime();
    cout << "--------------------------------------------\n";
    Time_ tmp2 = t1 + 20.f; 
    t1.showTime();
    tmp2.showTime();
    cout << "\n\n===== Завдання 2: Розклад дзвінків =====\n\n";
    Time_ start(8, 30, 0, true);
    Schedule s(start, 45, 5, 15, 2, 5);
    s.generateSchedule();
    return 0;
}