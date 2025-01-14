#include <iostream>
#include <windows.h>

using namespace std;

bool isAlarmTime(int alarmHour, int alarmMinute, int currentHour, int currentMinute) {
    return (alarmHour == currentHour && alarmMinute == currentMinute);
}

void adjustAlarmTime(int& alarmHour, int& alarmMinute, int snoozeTime) {
    alarmMinute += snoozeTime;
    if (alarmMinute >= 60) {
        alarmMinute -= 60;
        alarmHour++;
        if (alarmHour >= 24) {
            alarmHour = 0;
        }
    }
}

void displayTime(int hour, int minute) {
    cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
}

int main() {
    int alarmHour, alarmMinute;
    int currentHour, currentMinute;
    int snoozeCount = 0;
    const int MAX_SNOOZES = 5;
    char snoozeOption;

    cout << "Enter the alarm hour (0-23): ";
    cin >> alarmHour;
    cout << "Enter the alarm minute (0-59): ";
    cin >> alarmMinute;


    if (alarmHour < 0 || alarmHour > 23 || alarmMinute < 0 || alarmMinute > 59) {
        cout << "Invalid alarm time entered." << endl;
        return 1;
    }

    cout << "Alarm is set to ";
    displayTime(alarmHour, alarmMinute);
    cout << endl;


    cout << "Enter current hour (0-23): ";
    cin >> currentHour;
    cout << "Enter current minute (0-59): ";
    cin >> currentMinute;

  
    if (currentHour < 0 || currentHour > 23 || currentMinute < 0 || currentMinute > 59) {
        cout << "Invalid current time entered." << endl;
        return 1;
    }

    
    while (true) {
      
        if (isAlarmTime(alarmHour, alarmMinute, currentHour, currentMinute)) {
            cout << "Alarm! Time is up!" << endl;
            cout << "Press 'y' to snooze for 5 minutes, or any other key to stop: ";
            cin >> snoozeOption;
            if (snoozeOption == 'y' || snoozeOption == 'Y') {
                if (snoozeCount < MAX_SNOOZES) {
                    snoozeCount++;
                    adjustAlarmTime(alarmHour, alarmMinute, 5);
                    cout << "Snooze activated! Alarm will ring again at ";
                    displayTime(alarmHour, alarmMinute);
                    cout << endl;
                }
                else {
                    cout << "Maximum snooze count reached. Stopping alarm." << endl;
                    break;
                }
            }
            else {
                cout << "Stopping alarm." << endl;
                break;
            }
        }

        currentMinute++;
        if (currentMinute >= 60) {
            currentMinute = 0;
            currentHour++;
            if (currentHour >= 24) {
                currentHour = 0;
            }
        }

        Sleep(1000); 
    }

    return 0;
}