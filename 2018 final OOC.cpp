#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 10;

class Date {
};

class Patient;
class Doctor;
class ConsultantDoctor;
class Ward;
class Team;

class Hospital {
private:
    string name;
    string address;
    string phone;
    Ward* ward[SIZE] = {nullptr};
    Team* team[SIZE] = {nullptr};

public:
    Hospital(const string& name, const string& address, const string& phone)
        : name(name), address(address), phone(phone) {}

    ~Hospital() {
        for (int i = 0; i < SIZE; ++i) {
            delete ward[i];
            delete team[i];
        }
    }
};

class Doctor {
protected:
    vector<string> speciality;
    vector<string> location;

private:
    Patient* ppatient = nullptr;

public:
    Doctor() = default;
    virtual ~Doctor() = default; 
};

class Patient {
private:
    string id;
    string gender;
    int age;
    Date accepted;
    vector<string> sickness;
    vector<string> prescription;
    vector<string> allergies;
    vector<string> specialReq;
    Doctor* doc = nullptr;
    Ward* ward = nullptr;
    Team* team = nullptr;
    ConsultantDoctor* conDoc = nullptr;

public:
    Patient(const string& id, const string& gender, int age)
        : id(id), gender(gender), age(age) {}

    ~Patient() {
    }
};

class ConsultantDoctor : public Doctor {
private:
    double fee;
    Patient* ppp = nullptr;
    Team* tee = nullptr;

public:
    ConsultantDoctor(double fee) : fee(fee) {}
    ~ConsultantDoctor() override = default;
};

class JuniorDoctor : public Doctor {
private:
    int hours;

public:
    JuniorDoctor(int hours) : hours(hours) {}
    ~JuniorDoctor() override = default;
};

class Ward {
private:
    string name;
    string gender;
    int capacity;
    Patient* pat = nullptr;

public:
    Ward(const string& name, const string& gender, int capacity)
        : name(name), gender(gender), capacity(capacity) {}

    ~Ward() {
    }
};

class Team {
public:
    string name;
    Doctor* doc[SIZE] = {nullptr};
    Patient* patient = nullptr;
    ConsultantDoctor* cDoctor = nullptr;

    Team(const string& name) : name(name) {}

    ~Team() {
        for (int i = 0; i < SIZE; ++i) {
            delete doc[i];
        }
    }
};
