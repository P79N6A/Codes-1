#ifndef Student_person_h
#define Student_person_h

#include <iostream>
#include <string>
using namespace std;

enum PERSON_SEX
{
    FEMALE = 'F',
    MALE = 'M'
};

class Date
{
    friend ostream& operator << (ostream &output, const Date &r);
    friend istream& operator >> (istream &input, Date &r);
    
public:
    Date(short year = 0, short month = 0, short day = 0) : m_nYear(year), m_nMonth(month), m_nDay(day){}
    short getYear()const;
    short getMonth()const;
    short getDay()const;
    string getDate()const;
    
    void operator++();
    
    void Display()const;
    
private:
    short m_nYear;
    short m_nMonth;
    short m_nDay;
};

class Person{
    friend ostream& operator << (ostream &put, const Person &r);
    friend istream& operator >> (istream &input , Person &r);

public:
    Person();
    Person(const string name, const char sex, const Date birthday,
           const string id, const string birthPlace);
    
    string GetName()const;
    char   GetSex()const;
    Date   GetBirthday()const;
    string GetID()const;
    string GetbirthPlace()const;
    
    void   SetName(const string &name);
    void   SetSex(char sex);
    void   SetID(const string &id);
    
    void   Display()const;
    
protected:
    string m_strName;
    char   m_chSex;  // FEMALE or MALE
    Date   m_Birthday;
    
private:
    string m_strID;
    string m_strBirthPlace;
};

#endif //Student_person_h
