#pragma once
#include <iostream>
using namespace std;

struct Pass {
	int time = 0; 
	Pass* next;
};
class Taxi
{
	Pass* passHead;
	Pass* passTail;

	int countPass;
	int time_pass;
	int time_bus;

public:
	double avg = 0;
	int numberOfSeats = 0;
	Taxi(int tPass, int tBus) :
		countPass{ 0 }, time_pass{ tPass }, time_bus{ tBus } {
		passHead = nullptr;
		passTail = nullptr;
	}

	void AddPassenger() {
		Pass* p = new Pass;
		Pass* temp = passHead;
		p->next = nullptr;

		if (passHead == nullptr)
			passHead = passTail = p;
		else {
			passTail->next = p;
			passTail = p;
			while (temp->next != nullptr) {
				temp->time += time_pass;
				temp = temp->next;
			}
		}

		countPass++;
	}
	void DelPassenger() {
		if (countPass != 0) {
			Pass* p = passHead;
			passHead = passHead->next;
			delete p;
			countPass--;
		}
	}

	void ArrivalBus(bool final = false) {
		for (int i = 0; i < time_bus; i++) {
			if (i % time_pass == 0)
				AddPassenger();
		}
		if (!final)
			numberOfSeats = rand() % 10;
		else
			numberOfSeats = 16;
		//PrintPassenger();
		while (numberOfSeats != 0)
		{
			DelPassenger();
			numberOfSeats--;

		}
		//PrintPassenger();
		//cout << endl;
		avg += AveragePass();
	}
	double AveragePass() {
		Pass* p = passHead;
		int avgTime = 0;
		if (p == nullptr) return 0;
		while (p->next != nullptr)
		{
			avgTime += p->time;
			p = p->next;
		}
		return (double)avgTime / countPass;
	}
	bool IsInterval(double N, double M) {
		if (N < M) {
			time_bus--;
			return false;
		}
		return true;
	}
	void PrintPassenger() {
		cout << "Количество людей на остановке -> "
			<< countPass << endl;
		cout << "Среднее время нахождения на оставновке -> "
			<< AveragePass() << endl;
		cout << "Время приезда автобуса -> "
			<< time_bus << endl;
		cout << "Количество свободных мест -> " << numberOfSeats << endl;
	}

	void Reset() {
		avg = 0;
		DelAllPassenger();
	}
	void DelAllPassenger() {
		while (countPass != 0) {
			DelPassenger();
		}
	}
	int GetTimeBus() { return time_bus; }
};

