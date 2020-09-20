#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Employee{
	protected:
		string name;
		float hoursWorked;
		int lateCount;
	public:
		Employee(string n){name = n; lateCount = 0;}
		string GetName(){return name;}
		void SetHoursWorked(float h){hoursWorked = h;}
		float GetHoursWorked(){return hoursWorked;}
		void SetLateCount(int c){lateCount = c;}
		float GetLateCount(){ return lateCount;}

		float operator+(const Employee& e) {
			float totalHours = this->hoursWorked + e.hoursWorked;
			return totalHours;
		}

		virtual void DisplayMyPay() = 0;
};
/*****************************************/
/* Write your Hourly Employee class here */

class HourlyEmployee : public Employee {
	private:
		float wage;
	public:
		HourlyEmployee(string n, float wage_): Employee(n), wage(wage_) {};
		float getWage() {return wage;}
		void setWage(float wage_) {wage = wage_;}
		
		virtual void DisplayMyPay() override {
			cout << "You earn $" << wage << "/hour" << endl;
		}
};

/*****************************************/	
/* Write your Salary Employee class here */

class SalariedEmployee : public Employee {
	private:
		float salary;
	public:
		SalariedEmployee(string n, float salary_): Employee(n), salary(salary_) {};
		float getSalary() {return salary;}
		void setSalary(float salary_) {salary = salary_;}

		virtual void DisplayMyPay() override {
			cout << "You earn $" << salary << "/year" << endl;
		}
};


/*****************************************/	
/* Write your Volunteer class here       */

class Volunteer : public Employee {
	private:
		float award;
	public:
		Volunteer(string n, float award_): Employee(n), award(award_) {};
		float getAward() {return award;}
		void setAward(float award_) {award = award_;}

		virtual void DisplayMyPay() override {
			cout << "You don't get paid, but you may get an award for your efforts this year!" << endl;
		}
};

/*****************************************/	
/* Write your late function here         */

void getLateEmployees(vector<Employee*> weeklyVect) {
	vector<Employee*>::iterator it;
	int count = 1;

	for(it = weeklyVect.begin(); it != weeklyVect.end(); it++) {
		cout << "employee" << count << " - " << (*it)->GetLateCount() << endl;
		count++;
	}
}

/***************************************************/	
/* Write your DisplayEmployeeDetails function here */

void DisplayEmployeeDetails(Employee* e) {
	e->DisplayMyPay();
}

/*****************************************/
/* Do Not Edit the function SumOf Hours
   You must adjust your progam to make   
   use of this function                  */
/*****************************************/
template <typename T>
float SumOfHours (T x, T y){
return (x+y);
}


int main(){
/* This is where the main driver
 * for the program exisits. You don't have to 
 * fill in this portion on this exam.
 *
 * Feel free to use the main code to test snippets 
 * of your own code to make sure it works.
 * Leave your tests here and comment them to 
 * recieve partial credit.
*/ 	
vector<Employee*> weeklyVect;

	Employee *e;

	HourlyEmployee e1("Bob", 13.05);
	SalariedEmployee e2("Joe", 60000);
	Volunteer e3("idk", 999999);

	e1.SetHoursWorked(5);
	e2.SetHoursWorked(8);

	//DisplayMyPay test (works)
	e1.DisplayMyPay();
	e2.DisplayMyPay();
	e3.DisplayMyPay();

	//DisplayEmployeeDetails test (works)
	e = &e1;
	DisplayEmployeeDetails(e);

	//GetLateCount test (works)
	e1.SetLateCount(2);
	e2.SetLateCount(4);
	e3.SetLateCount(6);
	e = &e1;
	weeklyVect.push_back(e);
	e = &e2;
	weeklyVect.push_back(e);
	e = &e3;
	weeklyVect.push_back(e);
	getLateEmployees(weeklyVect);

	//SumOfHours test (works only if I remove the virtual functions, if not, it says Employee is abstract)
	cout << SumOfHours<Employee>(e1,e2) << endl; //comment this out to test the other codes, they should work. this is the only problem i had.

}
