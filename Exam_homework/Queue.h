#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class Student
{
	string Name;
	string Surname;
	int grade[3] = {};
	static int round;
public:
	Student();
	Student(string _N, string _S);
	~Student();
	friend ostream& operator << (ostream& os, Student st);
	void SetGrade(int n, int i);
	int GetGrade(int n);
	static void IncrementRound() { round++; }
};

	class Queue
	{
		Student* Wait;
		int MaxQueueLength;
		int QueueLength;
	public:
		Queue(int m);
		~Queue();
		void Add(Student _st);
		Student Extract();
		void Clear();
		bool IsEmpty();
		bool IsFull();
		int GetCount();
		void Show();
	};

