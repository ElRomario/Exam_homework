#include "Queue.h"
#include <vector>
int main()
{
    int queueSize = 10;
    srand(time(NULL));
    setlocale(LC_ALL,("rus"));
    vector<Student> students;
    Student st1("Фёдор", "Григорьев");
    students.push_back(st1);
    Student st2("Кирилл", "Емифодий");
    students.push_back(st2);
    Student st3("Роман", "Циклоп");
    students.push_back(st3);
    Student st4("JD", "Ride");
    students.push_back(st4);
    Student st5("Кирилл", "Неровный");
    students.push_back(st5);
    Student st6("Стас", "Смазанный");
    students.push_back(st6);
    Student st7("Георгий", "Клепстер");
    students.push_back(st7);
    Student st8("Стас", "Кукушка");
    students.push_back(st8);
    Student st9("Сонечка", "Зайчик");
    students.push_back(st9);
    Student st10("Эдуар", "Блок");
    students.push_back(st10);

    Queue qu(queueSize);
    int n = 0;
    for (int i = 0; i < queueSize; i++)
    {
        qu.Add(students[i]);
        students[i];
    }

    

    
    for (int round = 0; round < 3; round++, Student::IncrementRound())
    {
        cout <<setw(30) <<"----------" << round + 1 << "й раунд----------";

        for (int i = 0; i < queueSize; i++)
        {
            Student st = qu.Extract();
            st.SetGrade(rand()% 12 + 1, round);
            qu.Add(st);
            //students[i].SetGrade(rand() % 12, round);
            //qu.Add(students[i]);
        }
        qu.Show();
        cout << setw(30) << "----------" << "Прошли" << "----------";
        for (int i = 0; i < queueSize; i++)
        {

            Student st = qu.Extract();
            if (st.GetGrade(round) >= 7)
            {
                qu.Add(st);

            }
        }
        qu.Show();
    }

        


       

    

    //выдача оценок
    //проверка с выводом
    //удаление не прошедших



    



}


