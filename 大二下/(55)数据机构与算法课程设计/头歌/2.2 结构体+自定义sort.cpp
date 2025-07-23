#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
/*
 首先比较学生的成绩：若成绩不同，则返回成绩低的；
 若成绩相同，返回学号靠前的（即数值小的）。
 */
using namespace std;

struct Student{
    int numberID;
    char name[20];
    int score;
    Student(){}
    Student(int id_, char *name_, int score_){
        numberID = id_;
        strcpy(name, name_);
        score = score_;
    }
    void in()
    {
        scanf("%d %s %d", &numberID, name, &score);
    }
    void out()
    {
        printf("%d %s %d\n", numberID, name, score);
    }
};

bool min_cmp(Student S1, Student S2){
    /********** Begin *********/
    if (S1.score != S2.score) {
        return S1.score < S2.score;
    } else {
        return S1.numberID < S2.numberID;
    }
    /********** End **********/
}

int main(int argc, const char * argv[])
{务
    /********** Begin *********/
    vector<Student>students;
    Student temp; //为了存储创建的临时容器
    while (scanf("%d %s %d", &temp.numberID, temp.name, &temp.score) == 3) {
        students.push_back(temp);
    }
    sort(students.begin(), students.end(), min_cmp);
    if (!students.empty()) {
        students[0].out();
    }
    /********** End **********/

    return 0;
}
/*
测试输入：
20180122 Niki 71
20180110 Barbara 71
预期输出：
20180110 Barbara 71
 */