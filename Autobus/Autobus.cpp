#include <iostream>
#include"Taxi.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Taxi h{ 5, 100 };

    do {
        h.Reset();
        for (int i = 0; i < 5; i++) {
            h.ArrivalBus(1);
        }
        //system("pause");
        //system("cls");
    } while (!h.IsInterval(10, h.avg / 5));
    cout << "Выбрано оптимальное время прихода автобуса = "
        << h.GetTimeBus() << " секунд";
}

