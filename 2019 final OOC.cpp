#include <iostream>
#include <cstring>
#define SIZE 10
using namespace std;

class Customer;

class Loan{
  private:
    int loan_no;
    double amount;
    char Type[20];
    Customer *cus;

  public:
    Loan (int lno, double amo, char tp[]){
       loan_no = lno;
       amount = amo;
       strcpy(Type,tp);
      
    }
    void addCustomer(Customer *pcus);
    void prepayment();
    void getEM1();   
};

class Account {
    protected:
      int Acc_no;
      double Balance;

    public:
      Account(int no, double bal){
      Acc_no = no;
      Balance = bal;
      }
      void debitAmount();
      void creditAmount();
      double getBalance();
};


class Branch {
private:
  int b_code;
  string City;
  Loan *lo[SIZE];
  Account *acc[SIZE];

public:
  Branch() {
    b_code = 0;
    City = "";
  }

  Branch(int code, string cit) {
    b_code = code;
    City = cit;
  }

  void addAccount(Account *a1[]){
    for(int i=0;i<SIZE;i++)
      acc[i] = a1[i];
  }

  void addLoan(Loan *L[]){
    for(int i=0;i<SIZE;i++)
      lo[i] = L[i];
  }

  ~Branch(){
    cout << "Branch is Closing" << endl;
  }

};

class Bank {
  private:
    string name;
    int code;
    Branch *br[SIZE];



public:
  Bank() {
  name = "";
  code = 0;
  for (int i=0; i < SIZE; i++) {
    br[i] = new Branch(0,"");
  }
}



Bank(string nm, int cd, int co[], string ci[]) {
  name = nm;
  code = cd;
  
  for (int i=0; i < SIZE; i++) {
    br[i] = new Branch(co[i], ci[i]);
  }

}


~Bank() {
  
  cout << "Bank is CLosing.." << endl;
  
  for (int i=0; i < SIZE; i++) {
    delete br[i];
    }
  }
};

class Savings_Account : public Account{
    private:
      double Min_Balance;
      string Date_of_Opening;
      Customer *cus;
    public:
      void addCustomer(Customer *pcus);
      void removeCustomer();
};

class Current_Account : public Account{
    private:
      double Interest_Rate; 
      string Date_of_Opening;
      Customer *cus;
    public:
      void addCustomer(Customer *pcus);
      void removeCustomer();
};

class Customer{
    private:
      string Cust_ID;
      string Name;
      string Address;
      string Phone;
      Savings_Account *S_Acc[SIZE];
      Current_Account *C_Acc[SIZE];
      Loan *lo[SIZE];   

    public:
      Customer(string ID, string NM, string AD, string pNo, Loan *lo[], Savings_Account *SA[], Current_Account *CA[]);
};
