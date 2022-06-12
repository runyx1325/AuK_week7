/*
 ============================================================================
 Aufgabe     : Datenstrukturen
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdbool.h>
#include <time.h>
#include "dhbwstudent.h"
#include "dhbwstudentlist.h"

#ifndef DHBWTEST_H_
#define DHBWTEST_H_

static const char TRUETEXT[] = "Passed";
static const char FALSETEXT[] = "FAILED";

void shuffle(int *array, size_t n);

bool testNoNulls(StudentLP* anchor_adr);
bool testMatrSort(StudentLP* anchor_adr);
bool testMatrSortArray(Student_p *array, int count);

Student_p generateTestStudent(int matr_nr);
StudentLP* generateTestData(int amount, bool shuffleData);

void outputBenchmarkScore(const char *datastructure, const char *operation,
		clock_t begin, clock_t end);

void outputTestResult(const char *datastructure, const char *operation,
bool result, Student_p element);

void outputStudentList(StudentLP* anchor_adr);

void outputStudentArray(Student_p *array, int count);

#endif /* DHBWTEST_H_ */
