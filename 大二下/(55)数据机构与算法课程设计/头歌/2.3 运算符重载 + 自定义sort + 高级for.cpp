//
//  main.cpp
//  step3
//
//  Created by ljpc on 2018/7/6.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

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
    bool operator < (const Student &S)const
    {
        // 请在这里补充代码，完成本关任务
        /********** Begin *********/
        if(score != S.score){
            return score<S.score;
        }else{
            return numberID < S.numberID;
        }

        /********** End **********/
    }
};

bool max_cmp(Student S1, Student S2)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(S1.score != S2.score){
        return S1.score > S2.score;
    }else{
        return S1.numberID < S2.numberID;
    }

    /********** End **********/
}

int main(int argc, const char * argv[])
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    vector<Student>students;
    Student temp;
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        temp.in();
        students.push_back(temp);
    }

    sort(students.begin(), students.end(), max_cmp);

    for (Student student : students) {
        student.out();
    }
    /********** End **********/

    return 0;
}
