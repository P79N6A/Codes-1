//
//  Student.h
//  Student
//
//  Created by Link on 15/5/12.
//  Copyright (c) 2015年 郭子尧. All rights reserved.
//

#ifndef Student_Student_h
#define Student_Student_h

#include "Person.h"
#include <vector>

class Pupil : public Person
{
    friend ostream& operator << (ostream& sout, const Pupil& r);
    friend istream& operator >> (istream& sin, Pupil& r);
    
public:
    Pupil(): m_nNumber(0), m_fGPA(0.0f){}
    
    Pupil(const string& name, char sex, const Date& birthday,
          const string& birthPlace, const string& id,
          int number, float gpa, const string schoolname) :
    Person(name,sex,birthday,id,birthPlace), m_nNumber(number), m_fGPA(gpa), m_strSchoolName(schoolname){}
    
    void SetSchoolName(const string& schoolName){ m_strSchoolName = schoolName;}
    void SetNumber(int number){ m_nNumber = number;}
    
    string GetSchoolName()const{ return m_strSchoolName;}
    int  GetNumber()const{ return m_nNumber; }
    
    void Display()const
    {
        Person::Display();
        cout << *this;
    }
    
private:
    int m_nNumber;
    string m_strSchoolName;
    float m_fGPA;
};

struct COURSE
{
    COURSE() : score(0), credit(0.0f){}
    COURSE(const string& na,const int sco,const int cred): name(na), score(sco), credit(cred){}
    string name;
    int    score;
    int    credit;
};

class Student : protected Pupil
{
    friend ostream& operator << (ostream& sout, const Student& r);
public:
    Student();
    Student(const string& name, char sex, const Date& birthday,
            const string& birthPlace, const string& id,
            int number, float gpa, const string schoolname, const string major) :
    Pupil(name,sex,birthday,birthPlace,id,number,gpa,schoolname), m_strMajor(major){}
    void AddCourse(const COURSE& course);
    COURSE GetCourse(const string& strCourseName);

private:
    string         m_strMajor;
    vector<COURSE> m_vecCourse;
};

#endif
