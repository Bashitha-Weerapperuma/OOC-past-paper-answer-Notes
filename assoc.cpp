#include <iostream>
#include <cstring>

using namespace std;

//Association Class 

class Employee
{
private:
	string empID;
	string name;
public:
	Employee(string pempID, string pname)
	{
		empID = pempID;
		name = pname;
	}
	
	void displayEmployee()
	{
		cout << "Emp ID = " << empID << endl;
		cout << "Name = " << name << endl;
	}
};

class Project
{
private:
	string projectID;
	string name;
public:
	Project(string pprojectID, string pname)
	{
		projectID = pprojectID;
		name = pname;
	}

	void displayProject()
	{
		cout << "Project ID = " << projectID << endl;
		cout << "Name  = " << name << endl;
	}
};

class worksON
{
private:
	Employee *emp;
	Project *prj;
	int hours;
public:
	worksON(Employee *pemp, Project *pprj, int phours)
	{
		emp = pemp;
		prj = pprj;
		hours = phours;
	}
	void displayWorksON()
	{
		emp->displayEmployee();
		prj->displayProject();
		cout << "Hours = " << hours << endl;
	}
};

int main()
{
	Employee *e[2];
	e[0] = new Employee("E001", "Bashitha");
	e[1] = new Employee("E002", "Weerapperuma");
	
	Project *p[2];
	p[0] = new Project("P001", "Python");
	p[1] = new Project("P002", "Java");
	
	worksON work1(e[0], p[0], 2);
	worksON work2(e[1], p[1], 4);
	
	work1.displayWorksON();
	cout << endl;
  	work2.displayWorksON();
	
	delete e[0];
  
	return 0;
}
