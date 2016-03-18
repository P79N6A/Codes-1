#include <fstream>
#include <strstream>
#include <sstream>

#include "Person.h"
#include "Student.h"

int main()
{
    ifstream fin("C:\\Users\\gonghailong\\Desktop\\Student1\\Student\\student.txt");
    
    vector<Person*> listPerson;
    
    string strObjType;
    Person* pPerson = 0;
    
    while (fin >> strObjType)
    {
        fin.get();
        
        if (strObjType == "#Person#")
        {
            pPerson = new Person;
            if (pPerson)
                pPerson->Load(fin);
            
            getline(fin,strObjType);     //Skip the  end line;
            
        }
        else if (strObjType == "#Pupil#")
        {
            pPerson = new Pupil;
            if (pPerson)
                pPerson->Load(fin);
            
            getline(fin, strObjType);     //Skip the  end line;
            
            //		fin >> strObjType;     //Skip the  end line;
            
        }
        else if (strObjType == "#Student#")
        {
            pPerson = new Student;
            if (pPerson)
                pPerson->Load(fin);         //Ö»ÄÜ¶ÔÐéº¯Êýµ÷ÓÃ
        }
        listPerson.push_back(pPerson);
    }
    
    for each(auto p in listPerson)
    {
        p->Display();
        cout << endl;
        
    }
    
    cout << "************" << listPerson.size() << endl;
    
    
    
    return 0;
}