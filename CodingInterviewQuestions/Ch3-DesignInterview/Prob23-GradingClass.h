/*
 * Prob23-GradingClass.h
 *
 *  Created on: Feb 8, 2017
 *      Author: Felix
 */

#ifndef PROB23_GRADINGCLASS_H_
#define PROB23_GRADINGCLASS_H_

#include "Prob23-Student.h"

#include <string>
#include <vector>

class GradingClass {
public:
	GradingClass();
	~GradingClass();

	void readFile(std::string file);
	void writeFile(std::string file);

	const std::vector<Student*>& getStudents() const;

private:
	std::vector<Student*> myStudents;

	void printSorted(std::string sortType, std::fstream& fs, std::vector<Student*>& list);

	friend bool sortByNames(Student* left, Student* right);
	friend bool sortByMarks(Student* left, Student* right);
};

#endif /* PROB23_GRADINGCLASS_H_ */
