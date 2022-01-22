//
// Created by martin on 18/01/2022.
//

#include "../std_lib_facilities.h"

int main ()
  {
	int birth_year {1975};

	cout << dec << "dec: " << birth_year << endl;
	cout << hex << "hex: " << birth_year << endl;
	cout << oct << "oct: " << birth_year << endl;

	cout << "---------------------------------" << endl;

	double num {1234567.89};

	cout << "defaultfloat:\t\t" << defaultfloat << num << endl;
	cout << "fixed:\t\t\t" << fixed << num << endl;
	cout << "scientific:\t\t" << scientific << num << endl;
	cout << "---------------------------------" << endl;
	cout << setprecision(2);
	cout << "defaultfloat:\t\t" << defaultfloat << num << endl;
	cout << "fixed:\t\t\t" << fixed << num << endl;
	cout << "scientific:\t\t" << scientific << num << endl;

	cout << "---------------------------------" << endl;

	struct Person
		{
			string last_name;
			string first_name;
			string telephone;
			string email;
		};

	vector<Person> persons = {
		{"Brown", "James", "123-312-423", "j@brown.com"},
		{"Blue", "Ms. Anna", "333-184-753", "cloudwomen@mail.com"},
		{"Pink", "Mr. John", "543-323-423", "pinky@email.com"},
		{"Super", "Dumper", "985-872-423", "SD@sendt-to-me.com"},
		{"Smith", "Alexandra", "639-341-423", "asmith87@hotmail.com"},
		{"Olsen", "Camilla", "739-344-242", "camilla@coolmail.com"},
		{"Float", "Sir. Issac", "333-333-433", "sif@flaming-mail.com"},
	};
	cout << "-----------------------------------------------------------------------------"
		 << endl;
	cout << setw(20) << left << "Name" << "\t\t";
	cout << setw(16) << left << "Telephone";
	cout << setw(20) << left << "Email";
	cout << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (auto &p : persons)
	  {
		cout << p.last_name << ", " << setw(20) << left << p.first_name << "\t";
		cout << setw(16) << left << p.telephone;
		cout << setw(20) << left << p.email;
		cout << endl;
	  }
  }
