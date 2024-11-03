#include <iostream>

using namespace std;

#define num = 10;

class Payment
{

private:
    Member *m;
    double amount;
    string datepaid;

public:
    Payment();
    Payment(Member *me, double a, string d);
    void printReceipt();
};

class Person
{
private:
    char Name[50];
    char address[300];
    char TelNo[10];

public:
    Person();
    Person(const char Name, const char a, const char tel);
};

class Member : public Person
{

private:
    Payment *p[num];
    Loan *l[num];
    Reservation *r[num];
    int memberCode();

public:
    Member(Payment *p[], Loan *l[], int mCode);
    void findMember();
    void findMemberByCode();
};

class Loan
{

private:
    Member *m;
    Video *v;
    string startDate;
    int numberDays;
    float LateFine;

public:
    Loan();
    Loan(Member *m, Video *v, string sdate, int nday, float lfine);
    float findLoan();
    float calDaysOverdue();
    void setLateFine();
};

class Video
{
private:
    Loan *l[num];
    Reservation *r[num];
    int videoCode;
    char title[200];
    float dailyLoanRate();

public:
    Video();
    Video(Loan *l[], Reservation *r[], int vcode, char title[], float rate);
    char *getVideoByTitle();
    void findVideo();
    float calcCharges();
};

class Reservation
{
private:
    Video *v;
    Member *r;
    int memberCode;
    string reservationDate;

public:
    Reservation();
    Reservation(Video *v, Member *m, int mcode, string r);
    void findMember();
    void checkReservation();
    void printPostCard();
};