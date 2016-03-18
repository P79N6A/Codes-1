//
//  Student.cpp
//  Student
//
//  Created by Link on 15/5/12.
//  Copyright (c) 2015年 郭子尧. All rights reserved.
//

#include "Student.h"
#include "Person.h"

void Student::AddCourse(const COURSE &course)
{
    m_vecCourse.push_back(course);
}

//COURSE Student::GetCourse(const string &strCourseName){}

ostream& operator << (ostream& sout, const Pupil& r)
{
    sout << (const Person&)r;
    sout << "School Name: " << r.m_strSchoolName << '\n'
         << "     Number: " << r.m_nNumber       << '\n'
         << "        GPA: " << r.m_fGPA          << '\n';
    return sout;
}

istream& operator >> (istream& sin, Pupil& r)
{
    sin >> r.m_strSchoolName >> r.m_nNumber >> r.m_fGPA;
    return sin;
}

ostream& operator << (ostream& sout, const Student& r)
{
    sout << (const Pupil&)r;
    sout << "      Major: " << r.m_strMajor << '\n';
    return sout;
}
