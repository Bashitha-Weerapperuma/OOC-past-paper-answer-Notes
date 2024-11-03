#include <iostream>
#include <cstring>

using namespace std;

//Uni-directional Association
(department -> manager)
class Manager
{
private:
	string name;

public:
	Manager(string dname){
		name = dname;
	}
	void printManager(){
		cout << "Manager's name is : " << name << endl;
	}
};

class Department
{ 
private:
	string deptName;
	// has a Manager
	Manager *mgr;

public:
	Department(string dname, Manager *m){
		deptName = dname;
		mgr = m;
	}

	void printDepartment(){
		cout << "Department name is : " << deptName << endl;
		mgr->printManager();
	}

};

int main() {
  
	Manager *m = new Manager("Bashitha");

	Department *d = new Department("SE", m);

	d->printDepartment();

	return 0;
}

