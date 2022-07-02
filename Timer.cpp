#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите время для таймера (ЧАСЫ:МИНУТЫ:СЕКУНДЫ): ";
    char ch;
    int hours;
    int minutes;
    int seconds;
    cin >> hours >> ch >> minutes >> ch >> seconds;

    while (true)
    {
        system("cls");
        cout << hours << ":";
        if(minutes<10)
            cout << "0" << minutes << ":";
        else
            cout << minutes << ":";
        if (seconds < 10)
            cout << "0" << seconds << endl;
        else
            cout << seconds << endl;
        if (seconds > 0)
        {
            Sleep(1000);
            seconds--;
        }
        else if (minutes > 0)
        {
            Sleep(1000);
            minutes--;
            seconds = 59;
        }
        else if (hours > 0)
        {
            Sleep(1000);
            hours--;
            minutes = 59;
        }
        if (seconds == 0 && minutes == 0 && hours == 0)
        {
            Sleep(1000);
            system("cls");
            cout << hours << ":";
            cout << "0" << minutes << ":";
            cout << "0" << seconds << endl;
            int i = 100;
            while( i < 1000)
            {
                Beep(100+i, 1000);
                i += 100;
            }
            break;
        }
    }
    return 0;
}
