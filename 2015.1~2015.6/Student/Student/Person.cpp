//
//  Person.cpp
//  Student
//
//  Created by Link on 15/5/5.
//  Copyright (c) 2015年 郭子尧. All rights reserved.
//

#include "person.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator << (ostream &output, const Date &r){
    output << r.m_nYear << '-' << r.m_nMonth << '-' << r.m_nDay << '\n';
    return output;
}

istream& operator >> (istream &input, Date &r){
    input >> r.m_nYear >> r.m_nMonth >> r.m_nDay;
    return input;
}

ostream& operator << (ostream &put, const Person &r){
    put << "      Name : " << r.m_strName        << '\n';
    put << "       Sex : " << r.m_chSex          << '\n';
    put << "  Birthday : " << r.m_Birthday              ;
    put << "        ID : " << r.m_strID          << '\n';
    put << "Birthplace : " << r.m_strBirthPlace  << '\n';
    return put;
}

istream& operator >> (istream& input , Person& r){
    input >> r.m_strName      ;
    input >> r.m_chSex        ;
    input >> r.m_Birthday     ;
    input >> r.m_strID        ;
    input >> r.m_strBirthPlace;
    return input;
}

short Date::getYear()const{
    return m_nYear;
}

short Date::getMonth()const{
    return m_nMonth;
}

short Date::getDay()const{
    return m_nDay;
}

string Date::getDate()const{
    char buf[11];
    sprintf(buf,"%d-%02d-%02d",m_nYear, m_nMonth, m_nDay);
    return buf;
}

const int MONTH_DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void Date::operator++(){
    ++m_nDay;
    if ((m_nMonth == 2 && IsLeapYear(m_nYear) && m_nDay > 29) || m_nDay > MONTH_DAYS[m_nMonth])
    {
        ++m_nMonth;
        m_nDay = 1;
    }
    
    if (m_nMonth > 12){
        ++m_nYear;
        m_nMonth = 1;
    }
}

void Date::Display()const{
    cout<< m_nYear << ':' << m_nMonth << ':' << m_nDay;
    return;
}

Person::Person() : m_chSex(FEMALE){}

Person::Person(const string name, const char sex, const Date birthday,
               const string id, const string birthPlace){
    m_strName       = name;
    m_chSex         = sex;
    m_Birthday      = birthday;
    m_strID         = id;
    m_strBirthPlace = birthPlace;
}

string Person::GetName()const{
    return m_strName;
}

char   Person::GetSex()const{
    return m_chSex;
}

Date Person::GetBirthday()const{
    return m_Birthday;
}
string Person::GetID()const{
    return m_strID;
}

string Person::GetbirthPlace()const{
    return m_strBirthPlace;
}


void Person::SetName(const string &name){
    m_strName=name;
    return;
}

void Person::SetSex(const char sex){
    m_chSex=sex;
    return;
}

void Person::SetID(const string &id){
    m_strID=id;
    return;
}


void Person::Display()const{
    cout << *this;
}
