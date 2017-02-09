/*
 * Prob23-Student.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Felix
 */

#include "Prob23-Student.h"

#include <iostream>
using namespace std;

Student::Student() :
	myName(""), myMidterm(0), myFinal(0), myGrade(0.0) {

	myHw.clear();
}

Student::~Student() {
	myHw.clear();
}

void Student::setName(string name) {
	myName = name;
}

void Student::setMidterm(int midterm) {
	myMidterm = midterm;
}

void Student::setFinal(int final) {
	myFinal = final;
}

void Student::addHw(int hw) {
	myHw.push_back(hw);
}

const string Student::getName() const {
	return myName;
}

const int Student::getMidterm() const {
	return myMidterm;
}

const int Student::getFinal() const {
	return myFinal;
}

const vector<int> Student::getHw() const {
	return myHw;
}

void Student::calcGrade() {
	float hwAvg = 0.0;
	int hwTot = 0;
	for (unsigned int i=0; i < myHw.size(); ++i) {
		hwTot += myHw[i];
	}
	hwAvg = (hwTot / myHw.size());

	static float midtermWeight = 0.25;
	static float finalWeight = 0.55;

	myGrade = (myMidterm * midtermWeight) + (myFinal * finalWeight) + hwAvg;
}

const float Student::getGrade() const {
	return myGrade;
}

ostream & operator<<(ostream& os, const vector<int> list) {
	for(unsigned int i=0; i < list.size(); ++i) {
		os << list[i] << " ";
	}
	return os;
}

ostream & operator<<(ostream& os, const Student& stud) {
	os << "Name:    " << stud.getName() << endl;
	os << "MidterM: " << stud.getMidterm() << endl;
	os << "Final:   " << stud.getFinal() << endl;
	os << "HW:      ";
	os << stud.getHw() << endl;
	os << "Grade:   " << stud.getGrade() << endl;
	return os;
}

