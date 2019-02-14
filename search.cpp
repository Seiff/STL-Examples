#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
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

int compare(const void *s1, const void *s2) {
	const int *a = (int *) s1;
	const Student *b = (Student *) s2;
	if(*a < b->id)
		return -1;
	else if(*a > b->id)
		return 1;
	else
		return 0; 
}

bool sortComparator(Student s1, Student s2) {
	return(s1.id < s2.id);
}

int main() {
	Student students[9] = {Student("Alice", 145, 3.1),
							Student("Bob", 187, 2.9),
							Student("Ali", 209, 3.9),
							Student("Erlene", 145, 3.2),
							Student("Myriam", 444, 1.7),
							Student("Britni", 123, 3.2),
							Student("Edwin", 532, 1.8),
							Student("Glinda", 164, 3.7),
							Student("Golda", 219, 2.2)};
							
	int numberOfStudent = sizeof(students)/sizeof(students[0]);
	Student *result;

	cout<<"All students:"<<endl;
	cout<<"Name\tid\tGPA"<<endl;
	for(int i=0; i<numberOfStudent; i++) students[i].printStudentInfo();

	//sort array
	sort(students, students+numberOfStudent, sortComparator);

	//printing
	cout<<endl<<"Students after sort:"<<endl;
	cout<<"Name\tid\tGPA"<<endl;
	for(int i=0; i<numberOfStudent; i++) students[i].printStudentInfo();

	//Search students by existing id
	int id = 219;
	result = (Student*) bsearch(&id, students, numberOfStudent, sizeof(students[0]), compare);
	
	if(result) {
		cout<<endl<<"Student with id "<<id<<" found!"<<endl;
		result->printStudentInfo();
	} else cout<<endl<<"Student with id "<<id<<" not found!"<<endl;
	
	//search student by non existing id
	id = 201;
	result = (Student*) bsearch(&id, students, numberOfStudent, sizeof(students[0]), compare);
	
	if(result) {
		cout<<endl<<"Student with id "<<id<<" found!"<<endl;
		result->printStudentInfo();
	} else cout<<endl<<"Student with id "<<id<<" not found!"<<endl;

	return 0;
}