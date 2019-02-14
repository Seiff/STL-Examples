#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//class of a student with name, id and GPA
class Student {
public:
	string name;
	int id;
	float GPA;

	Student(string name, int id, float GPA) {
		this->name = name;
		this->id = id;
		this->GPA = GPA;
	}
	void printStudentInfo() {
		cout<<name<<"\t"<<id<<"\t"<<GPA<<endl;
	}
};

//function to be used in sort() that will sort students by GPA
bool sortComparator(Student s1, Student s2) {
	return(s1.GPA > s2.GPA);
}

int main() {
	Student students[3] = {Student("Alice", 145, 3.1),
							Student("Bob", 187, 2.9),
							Student("Ali", 209, 3.9)};
	int numberOfStudent = sizeof(students)/sizeof(students[0]);

	cout<<"Students before sort:"<<endl;
	cout<<"Name\tid\tGPA"<<endl;
	for(int i=0; i<3; i++) students[i].printStudentInfo();

	sort(students, students+numberOfStudent, sortComparator);

	cout<<endl<<"Students after sort:"<<endl;
	cout<<"Name\tid\tGPA"<<endl;
	for(int i=0; i<3; i++) students[i].printStudentInfo();

	return 0;
}