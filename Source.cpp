#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string& n, int a) : name(n), age(a) {}

    string getName() 
    {
        return name;
    }
    void setName( string& n) 
    {
        name = n;
    }

    int getAge() 
    {
        return age;
    }
    void setAge(int a)
    {
        age = a;
    }
    
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    friend ostream& operator<<(ostream& text, Person& person)
    {
        text << "Name: " << person.name << endl;
        text << "Age: " << person.age << endl;
        
        return text;
    }
  
    virtual ~Person() {}
};


class Student : public Person
{
private:
    string studentId;

public:
    
    Student(string n, int a,string id) : Person(n, a), studentId(id) {}
  
    string getStudentId()
    { 
        return studentId;
    }
    void setStudentId(string& id)
    { 
        studentId = id;
    }
   
    void displayInfo() override
    {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentId << endl << endl;
    }
};


class Teacher {
private:
    Person person;
    string subject;

public:
    
    Teacher(string n, int a,string subj) : person(n, a), subject(subj) {}

    string getSubject() 
    {
        return subject; 
    }
    void setSubject(string& subj)
    {
        subject = subj;
    }
  
    void displayInfo()
    {
        cout << "Teachers ";
        person.displayInfo();
        cout << "Subject: " << subject << endl << endl;
    }
};

int main() {
    
    Student student("Owen", 20, "A00123456");
    Teacher teacher("Seth", 30, "Computer Programing");
   
    student.displayInfo();  
    teacher.displayInfo();  

    Person* personPtr = new Student("Cayne", 21, "A00654321");
    personPtr->displayInfo();  

    cout << *personPtr << endl;

    delete personPtr;

    return 0;
}