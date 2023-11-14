#include <iostream>

using namespace std;

int main() {

	int size;
	bool input = false;

	while (input == false) {
		cout << "\nHow many students do you want to enter into the student database? ";
		cin >> size;
		if (size > 1) input = true;
		else cout << "\nYou have to input atlest two students.";
	}

	struct student {
		int ID;
		string name;
		int age;
		float grade;
	};

	student* record = new student[size];

	//student input
	for (int i = 0; i < size; i++) {

		cout << "\n *** Student " << i + 1 << " ***";
		cout << "\n Input the student' id: # ";
		cin >> record[i].ID;
		cout << "\n Input the student' name: ";
		cin >> record[i].name;
		cout << "\n Input the student's age: ";
		cin >> record[i].age;
		cout << "\n Input the student's grade: ";
		cin >> record[i].grade;
		cout << "\n *************** ";
		cout << "\n\n";
	}

	char option;

	cout << "\n What option do you want now?";
	cout << "\n * Display all student record (a)";
	cout << "\n * Find and display the record of a specific student by ID (b)";
	cout << "\n * Calculate and display the average grade of all students (c)";
	cout << "\n * Quit (d)";
	cout << "\n\n Your choice: "; cin >> option;

	if (option != 'a' && option != 'b' && option != 'c' && option != 'd') {
		cout << "Invalid option. Exiting the program." << endl;
		delete[] record;
		return 0;
	}

	if (option == 'a') {
		for (int i = 0; i < size; i++) {
			cout << "\n *** Student " << i + 1 << " ***";
			cout << "\n Student ID: #" << record[i].ID;
			cout << "\n Student Name: " << record[i].name;
			cout << "\n Student Age: " << record[i].age;
			cout << "\n Student Grade: " << record[i].grade;
			cout << "\n *************** ";
			cout << "\n\n";
		}
	}

	if (option == 'b') {
		int find;
		cout << "Please input the student ID you want to find: #"; cin >> find;
		for (int k = 0; k < size; k++) {
			if (record[k].ID == find) {
				cout << "\n *** Student " << k + 1 << " ***";
				cout << "\n Student ID: #" << record[k].ID;
				cout << "\n Student Name: " << record[k].name;
				cout << "\n Student Age: " << record[k].age;
				cout << "\n Student Grade: " << record[k].grade;
				cout << "\n *************** ";
				cout << "\n\n";
			}
		}
	}

	if (option == 'c') {
		int ma;
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += record[i].grade;
		}
		ma = static_cast<double>(sum) / size;
		cout << "The average grade is: " << ma;
	}

	if (option == 'd') {
		return 0;
	}

	delete[] record;
}