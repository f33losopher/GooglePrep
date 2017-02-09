/*
 * Prob23-Student.h
 *
 *  Created on: Feb 8, 2017
 *      Author: Felix
 */

#ifndef PROB23_STUDENT_H_
#define PROB23_STUDENT_H_

#include <string>
#include <vector>
#include <fstream>

class Student {
public:
	Student();
	~Student();

	void setName(std::string name);
	void setMidterm(int midterm);
	void setFinal(int final);
	void addHw(int hw);

	const std::string getName() const;
	const int getMidterm() const;
	const int getFinal() const;
	const std::vector<int> getHw() const;

	void calcGrade();
	const float getGrade() const;

private:
	friend std::ostream & operator<<(std::ostream& os, const std::vector<int> list);
	friend std::ostream & operator<<(std::ostream& os, const Student& stud);

private:
	std::string myName;
	int myMidterm; // 25%
	int myFinal;   // 55%
	std::vector<int> myHw;

	float myGrade;

};
#endif /* PROB23_STUDENT_H_ */
