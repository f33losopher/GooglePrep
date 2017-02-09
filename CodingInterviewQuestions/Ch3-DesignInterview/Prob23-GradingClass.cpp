/*
 * Prob23-GradingClass.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Felix
 */

#include "Prob23-GradingClass.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

bool sortByNames(Student* left, Student* right) {
	return left->getName() < right->getName();
}

bool sortByMarks(Student* left, Student* right) {
	return left->getGrade() < right->getGrade();
}

GradingClass::GradingClass() {

}

GradingClass::~GradingClass() {

}

void GradingClass::readFile(string file) {
	ifstream ifs(file.c_str());
	if (!ifs) {
		cerr << "Failed to open file: " << file << endl;
		return;
	}

	string line;
	while (getline(ifs, line)) {
		// DEBUG
//		cout << line << endl;

		Student* newStud = new Student();
		char buf[500];
		line.copy(buf, 500, 0);
		char* ptr = strtok(buf, " ");

		newStud->setName(ptr);

		ptr = strtok(NULL, " ");
		newStud->setMidterm(atoi(ptr));

		ptr = strtok(NULL, " ");
		newStud->setFinal(atoi(ptr));

		ptr = strtok(NULL, " ");
		while (ptr != NULL) {
			newStud->addHw(atoi(ptr));
			ptr = strtok(NULL, " ");
		}
		newStud->calcGrade();

		// DEBUG
//		cout << *newStud << endl;

		myStudents.push_back(newStud);
	}
}

void GradingClass::writeFile(string file) {
	fstream out;
	out.open(file.c_str(), ios::out);

	vector<Student*> studsByNames = myStudents;
	vector<Student*> studsByMarks = myStudents;

	sort(studsByNames.begin(), studsByNames.end(), sortByNames);
	sort(studsByMarks.begin(), studsByMarks.end(), sortByMarks);

	printSorted("name", out, studsByNames);
	printSorted("marks", out, studsByMarks);

	out.close();
}

const vector<Student*>& GradingClass::getStudents() const {
	return myStudents;
}

void GradingClass::printSorted(string sortType, fstream& fs, vector<Student*>& list) {
	fs << "Sorted by student " << sortType << ":" << endl;
	for (unsigned int i=0; i < list.size(); ++i) {
		Student* student = list[i];

		fs << student->getName() << " ";
		fs << student->getGrade() << " ";
		fs << student->getMidterm() << " ";
		fs << student->getFinal() << " ";
		vector<int> hw = student->getHw();
		for (unsigned int j=0; j < hw.size(); ++j) {
			fs << hw[j] << " ";
		}
		fs << endl;
	}
	fs << endl;
}


