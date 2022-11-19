#include "Queue.h"
using namespace std;
int Student::round = 0;
void Queue::Show()
{
	cout << "\n----------------------------------------------------------------------\n";
	cout << setw(6) << "Имя" << setw(6) << "|" << setw(13) << "Фамилия" << setw(10) << "|" << setw(20) << "Баллы";
	cout << "\n----------------------------------------------------------------------\n";
	for (int i = 0; i < QueueLength; i++)
	{
		cout << Wait[i] << endl;
		cout << "----------------------------------------------------------------------\n";
	}
	cout << endl;
	

}
Queue::~Queue()
{
	delete[]Wait;
}
Queue::Queue(int m)
{
	MaxQueueLength = m;
	Wait = new Student[MaxQueueLength];
	QueueLength = 0;
}
void Queue::Clear()
{
	QueueLength = 0;
}
bool Queue::IsEmpty()
{
	return QueueLength == 0;
}
bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::GetCount()
{
	return QueueLength;
}
void Queue::Add(Student _st)
{

	if (!IsFull())
		Wait[QueueLength++] = _st;
}
Student Queue::Extract()
{

	if (!IsEmpty())
	{
		Student temp = Wait[0];
		//temp.SetGrade(rand() % 12, round);
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		QueueLength--;
		return temp;
	}
	else
		exit(1);

}

Student::Student()
{
}

Student::Student(string _N, string _S)
{
	Name = _N;
	Surname = _S;
}

Student::~Student()
{

}

void Student::SetGrade(int n, int i)
{
	grade[i] = n;
}

int Student::GetGrade(int n)
{
	return grade[n];
}

ostream& operator<<(ostream& os, Student st)
{

	os << setw(7) << st.Name << setw(5) << "|" << setw(12) << st.Surname << setw(11) << "|" << setw(4);
	for (int i = 0; i < 3; i++)
	{
		os << st.grade[i];
		if (i != Student::round) // в том столбике, который = round печатаем сдал/не сдал, в остальных - пробел
		{
			os << setw(10)<< " ";
		}
		else if (st.grade[i] < 7)
			os << " Не сдал" << setw(7);
		else
		{
			os << " Сдал" << setw(10);
		}

	}
	return os;
}
