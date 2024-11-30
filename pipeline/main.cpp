#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct pipe {
	string pipe_name;
	double length;
	int diameter;
	bool under_repair;
	void add_pipe() {
		bool correct_data = false;
		cout << "Enter the name of the pipe: ";
		cin >> pipe_name;
		while (!correct_data) {
			cout << "Enter the length of the pipe: ";
			cin >> length;
			if (cin.fail() or (length <= 0)) {
				cout << "Incorrect data. Enter a positive int." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
		correct_data = false;
		while (!correct_data) {
			cout << "Enter the pipe diameter: ";
			cin >> diameter;
			if (cin.fail() or (diameter <= 0)) {
				cout << "Incorrect data. Enter a positive double." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
		correct_data = false;
		while (!correct_data) {
			cout << "Is the pipe under repair? (1/0) ";
			cin >> under_repair;
			if (cin.fail()) {
				cout << "Incorrect data. Enter 1 or 0." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
	}
	void show_pipe() {
		if (length > 0 and diameter > 0) {
			cout << "Pipe name: " << pipe_name << endl;
			cout << "Pipe length: " << length << endl;
			cout << "Pipe diameter: " << diameter << endl;
			cout << "Under repair: " << under_repair << endl;
		}
		else {
			cout << "There are no pipes." << endl;
		}
	}
	void edit_pipe() {
		if (length > 0 and diameter > 0) {
			under_repair = not(under_repair);
			cout << "The 'under repair' sign has been edited." << endl;
			cout << "Under repair: " << under_repair << endl;
		}
		else {
			cout << "There are no pipes." << endl;
		}
	}
	void save_pipe() {
		if (length > 0 and diameter > 0) {
			ofstream out;
			out.open("SavedObjects.txt", ios::app);
			if (out.is_open()) {
				out << pipe_name << endl;
				out << length << endl;
				out << diameter << endl;
				out << under_repair << endl;
			}
			out.close();
			cout << "Pipe has been saved." << endl;
		}
		else {
			cout << "There are no pipes." << endl;
		}
	}
	void download_pipe() {
		fstream file("SavedObjects.txt");
		if (file.peek() == EOF) {
			cout << "There are no saved pipes." << endl;
		}
		else {
			string line;
			ifstream in("SavedObjects.txt");
			if (in.is_open()) {
				in >> pipe_name;
				in >> length;
				in >> diameter;
				in >> under_repair;
			}
			in.close();
		}
	}
};

struct cs {
	string cs_name;
	int workshop_number;
	int workshop_working;
	int efficiency;
	void add_cs() {
		cout << "Enter the name of the CS: ";
		cin >> cs_name;
		bool correct_data = false;
		while (!correct_data) {
			cout << "Enter the number of workshops: ";
			cin >> workshop_number;
			if (cin.fail() or (workshop_number <= 0)) {
				cout << "Incorrect data. Enter a positive int." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
		correct_data = false;
		while (!correct_data) {
			cout << "Enter the number of working workshops: ";
			cin >> workshop_working;
			if (cin.fail() or (workshop_working <= 0) or (workshop_working > workshop_number)) {
				cout << "Incorrect data. Enter a positive int, no more than workshop number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
		correct_data = false;
		while (!correct_data) {
			cout << "Enter efficiency: ";
			cin >> efficiency;
			if (cin.fail() or (efficiency <= 0)) {
				cout << "Incorrect data. Enter a positive int." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				correct_data = true;
			}
		}
	}
	void show_cs() {
		if (workshop_number > 0 and workshop_working > 0 and efficiency > 0) {
			cout << "CS name: " << cs_name << endl;
			cout << "The number of workshops: " << workshop_number << endl;
			cout << "The number of working workshops: " << workshop_working << endl;
			cout << "Efficiency: " << efficiency << endl;
		}
		else {
			cout << "There are no compressor stations." << endl;
		}
	}
	void edit_cs() {
		if (workshop_number > 0 and workshop_working > 0 and efficiency > 0) {
			int action;
			cout << "The number of working workshops: " << workshop_working << endl;
			cout << "Press 1 to start shop operation, press 2 to stop shop operation: ";
			cin >> action;
			if (action == 1) {
				if (workshop_working < workshop_number) {
					workshop_working = workshop_working + 1;
					cout << "The number of working workshops has been edited." << endl;
					cout << "The number of working workshops: " << workshop_working << endl;
				}
				else {
					cout << "All workshops are working." << endl;
				}
			}
			else if (action == 2) {
				if (workshop_working > 0) {
					workshop_working = workshop_working - 1;
					cout << "The number of working workshops has been edited." << endl;
					cout << "The number of working workshops: " << workshop_working << endl;
				}
				else {
					cout << "Not a single workshop is working." << endl;
				}
			}
			else {
				cout << "Incorrect data. Please enter 1 or 2." << endl;
			}
		}
		else {
			cout << "There are no compressor stations." << endl;
		}
	}
	void save_cs() {
		if (workshop_number > 0 and workshop_working > 0 and efficiency > 0) {
			ofstream out;
			out.open("SavedObjects2.txt", ios::app);
			if (out.is_open()) {
				out << cs_name << endl;
				out << workshop_number << endl;
				out << workshop_working << endl;
				out << efficiency << endl;
			}
			out.close();
			cout << "CS has been saved." << endl;
		}
		else {
			cout << "There are no compressor stations." << endl;
		}
	}
	void download_cs() {
		fstream file("SavedObjects2.txt");
		if (file.peek() == EOF) {
			cout << "There are no saved CS." << endl;
		}
		else {
			string line;
			ifstream in("SavedObjects2.txt");
			if (in.is_open()) {
				in >> cs_name;
				in >> workshop_number;
				in >> workshop_working;
				in >> efficiency;
			}
			in.close();
		}
	}
};

int menu() {
	int option;
	cout << "MENU" << endl;
	cout << "Press 1. Add a pipe" << endl;
	cout << "Press 2. Add a compressor station" << endl;
	cout << "Press 3. Viewing all objects" << endl;
	cout << "Press 4. Edit the pipe" << endl;
	cout << "Press 5. Edit the compressor station" << endl;
	cout << "Press 6. Save" << endl;
	cout << "Press 7. Download" << endl;
	cout << "Press 0. Exit" << endl;
	bool correct_data = false;
	while (!correct_data) {
		cout << "Enter option:  ";
		cin >> option;
		if (cin.fail() or option < 0 or option>7) {
			cout << "Incorrect data. Enter a number from 0 to 7." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			correct_data = true;
		}
	}
	return option;
}

void delete_saved_objects() {
	ofstream out;
	out.open("SavedObjects.txt");
	out.close();
	out.open("SavedObjects2.txt");
	out.close();
}

int main() {
	int option;
	bool b = true;
	pipe p;
	cs c;
	while (b) {
		option = menu();
		switch (option) {
		case 1:
			p.add_pipe();
			break;
		case 2:
			c.add_cs();
			break;
		case 3:
			p.show_pipe();
			c.show_cs();
			break;
		case 4:
			p.edit_pipe();
			break;
		case 5:
			c.edit_cs();
			break;
		case 6:
			p.save_pipe();
			c.save_cs();
			break;
		case 7:
			p.download_pipe();
			c.download_cs();
			break;
		case 0:
			delete_saved_objects();
			b = false;
			break;
		}
	}
	return 0;
}