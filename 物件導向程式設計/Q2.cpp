#include <bits/stdc++.h>

using namespace std;

struct student
{
    string name;
    int score;
};

void input_students(student *arr, int n);
void sort_Students(student *arr, int n);
double Average_Students(student *arr, int n);
void print_students(student *arr, int size, double average);

int main()
{
    int Student_num;
    cout << "輸入學生數量：";
    cin >> Student_num;

    student *students = new student[Student_num];
    if (!students)
    {
        cerr << "記憶體分配失敗！" << endl;
        exit(1);
    }

    input_students(students, Student_num);

    sort_Students(students, Student_num);

    double average = Average_Students(students, Student_num);

    print_students(students, Student_num, average);

    delete[] students;

    return 0;
}

void input_students(student *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "輸入學生 " << i + 1 << " 的姓名：";
        cin >> (arr + i)->name;
        cout << "輸入學生 " << i + 1 << " 的分數：";
        while (cin >> (arr + i)->score && ((arr + i)->score < 0 || (arr + i)->score > 100))
            cout << "分數必須在0到100之間，請重新輸入。" << endl;
    }
}

void sort_Students(student *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((arr + j)->score > (arr + j + 1)->score)
                swap(*(arr + j), *(arr + j + 1));
}

double Average_Students(student *arr, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr + i)->score;
    return sum / n;
}

void print_students(student *arr, int size, double average)
{
    cout << "        學生分數" << endl;
    cout << "--------------------------" << endl;
    cout << "學生姓名" << "       " << "分數" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < size; ++i)
        cout << left << setw(15) << (arr + i)->name << (arr + i)->score << endl;
    cout << fixed << setprecision(2);
    cout << "--------------------------" << endl;
    cout << "平均分數：" << average << endl;
}

/*
測試用
5
1
10
11
15
111
55
1111
1
11111
50
*/