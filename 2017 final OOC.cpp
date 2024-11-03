#include <string>
using namespace std;

#define SIZE 10

class Faculty;
class Institute;
class Employee;
class ResearchAssociate;
class Lecturer;
class Course;
class Project;
class Participation;

class Faculty {
private:
    string name;
    Institute* inst[SIZE]; 
    Employee* emp;

public:

    Faculty(string n) : name(n), emp(nullptr) {
        for (int i = 0; i < SIZE; i++) {
            inst[i] = nullptr;
        }
    }

    ~Faculty() {
        delete emp;
    }
};

class Institute {
private:
    string name;
    string address;
    ResearchAssociate* reas;

public:
    Institute(string n, string addr) : name(n), address(addr), reas(nullptr) {}


    ~Institute() {
        delete reas;
    }
};

class Employee {
protected:
    int ssNo;
    string name;
    string email;
    int counter;
    Faculty* fal;

public:
    Employee(string n, string e, int ss) : name(n), email(e), ssNo(ss), counter(0), fal(nullptr) {}

    virtual void EmployeeAbstract() = 0;

    virtual ~Employee() = default;
};

class AdministrativeEmployee : public Employee {
public:
    AdministrativeEmployee(string n, string e, int ss) : Employee(n, e, ss) {}

    void EmployeeAbstract() override {
    }
};

class ResearchAssociate : public Employee {
private:
    int fieldOfStudy;
    Project* pro;

public:
    ResearchAssociate(string n, string e, int ss, int field) 
        : Employee(n, e, ss), fieldOfStudy(field), pro(nullptr) {}

    void EmployeeAbstract() override {
    }

    ~ResearchAssociate() {
        delete pro;
    }
};

class Lecturer : public ResearchAssociate {
private:
    Course* course;

public:
    Lecturer(string n, string e, int ss, int field) 
        : ResearchAssociate(n, e, ss, field), course(nullptr) {}

    void EmployeeAbstract() override {
    }

    ~Lecturer() {
        delete course;
    }
};

class Course {
private:
    string name;
    int id;
    float hours;
    Lecturer* lecturer;

public:
    Course(string n, int i, float h) : name(n), id(i), hours(h), lecturer(nullptr) {}

    ~Course() {
    }
};

class Project {
private:
    string name;
    string start;
    string end;
    ResearchAssociate* ra;

public:
    Project(string n, string s, string e) : name(n), start(s), end(e), ra(nullptr) {}

    ~Project() {
    }
};

class Participation {
private:
    int hours;

public:
    Participation(int h) : hours(h) {}
    ~Participation() = default;
};
