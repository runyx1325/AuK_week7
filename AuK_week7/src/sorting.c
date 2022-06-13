/*
 ============================================================================
 Aufgabe     : Sortieren
 Autor       : koetter
 Matrikel    : DIESE DATEI NICHT AENDERN
 Version     : DIESE DATEI NICHT AENDERN
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include "dhbwtest.h"

#include "dhbwstudent.h"
#include "dhbwstudentlist.h"
#include "dhbwstudenttree.h"
#include "dhbwstudentmap.h"

#include "dhbwsortmisc.h"
#include "dhbwsortsimple.h"
#include "dhbwsortmerge.h"
#include "dhbwsortheap.h"

//some string constants

static const char S_QSORT[] = "qsort (builtin)";
static const char S_TREESORT_LIST[] = "Treesort (List)";
static const char S_TREESORT_ARRAY[] = "Treesort (Array)";
static const char S_INSERTSORT_LIST[] = "Insertsort (List)";
static const char S_INSERTSORT_ARRAYLIST[] = "Inserts.(Arr->Lst)";
static const char S_BUBBLESORT[] = "Bubblesort";
static const char S_SELECTIONSORT[] = "Selectionsort";
static const char S_MERGESORT_ARRAY[] = "Mergesort (Array)";
static const char S_MERGESORT_LIST[] = "Mergesort (List)";
static const char S_HEAPSORT[] = "Heapsort";

static const char OP_SORT_TEST_DATA[] = "Sort Test Data";

bool arraySortTest(const char *sortName, StudentLP *inputList, void (*SortArray)(Student_p *array, int size)) {
	bool result = true;


		int count;
		//printf("1\n");
		Student_p *inputArray = StudentLToArray(inputList, &count, false);
		//printf("2\n");
		SortArray(inputArray, count);
		//printf("3\n");
		result = testMatrSortArray(inputArray, count);
		//printf("4\n");
		outputTestResult(sortName, OP_SORT_TEST_DATA, result, NULL);

		if(!result) {
			printf("Array not sorted:\n");
			outputStudentArray(inputArray, count);
		}





	return result;
}


bool listSortTest(const char *sortName, StudentLP *inputList, void (*SortList)(StudentLP *anchor_adr)) {
	bool result = true;

	if(result) {
		int count;

		SortList(inputList);

		result = testMatrSort(inputList);

		outputTestResult(sortName, OP_SORT_TEST_DATA, result, NULL);

		if(!result) {
			printf("List not sorted:\n");
			outputStudentList(inputList);
		}
	}

	return result;
}

void arraySortBenchmark(const char *sortName, StudentLP *inputList, void (*SortArray)(Student_p *array, int size)) {

	clock_t begin, end;

	{
		int count;

		Student_p *inputArray = StudentLToArray(inputList, &count, false);

		begin = clock();
		SortArray(inputArray, count);
		end = clock();

		free(inputArray);

		outputBenchmarkScore(sortName, OP_SORT_TEST_DATA, begin, end);

	}
}

void listSortBenchmark(const char *sortName, StudentLP *inputList, void (*SortList)(StudentLP *anchor_adr)) {

	clock_t begin, end;

	{
		begin = clock();
		SortList(inputList);
		end = clock();

		outputBenchmarkScore(sortName, OP_SORT_TEST_DATA, begin, end);
	}
}



int main(int argc, char *argv[]) {

	clock_t begin, end;

	begin = clock();

	if (argc != 2) {
		fprintf(stderr, "Usage: %s [<file>|<number of random students>]\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Argument=%s\n", argv[1]);
	int amount = atoi(argv[1]);
	printf("Amount=%d\n", amount);



	StudentLP *inputList;
	if (amount > 0) {
		inputList = generateTestData(amount, true);
	} else {
		inputList = StudentsFromFile(argv[1]);
	}

	bool result = true;

	{
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_QSORT, listForTest, QSortArray);
		StudentLFree(listForTest);
	}

	if(result && StudentLImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_INSERTSORT_ARRAYLIST, listForTest, ListSortArray);
		StudentLFree(listForTest);
	}

	if(result && StudentLImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = listSortTest(S_INSERTSORT_LIST, listForTest, ListSortList);
		StudentLFree(listForTest);
	}


	if(result && StudentTImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_TREESORT_ARRAY, listForTest, TreeSortArray);
		//TODO: this is a bit of a problem with the existing interface from week 4-6 - fix next year
		//StudentLFree(listForTest);
	}

	if(result && StudentTImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = listSortTest(S_TREESORT_LIST, listForTest, TreeSortList);
		StudentLFree(listForTest);
	}

	if(result && BubbleSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_BUBBLESORT, listForTest, BubbleSortArray);
		StudentLFree(listForTest);
	}

	if(result && SelectionSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_SELECTIONSORT, listForTest, SelectionSortArray);
		StudentLFree(listForTest);
	}

	if(result && MergeSortArrayImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_MERGESORT_ARRAY, listForTest, MergeSortArray);
		StudentLFree(listForTest);
	}

	if(result && MergeSortListImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = listSortTest(S_MERGESORT_LIST, listForTest, MergeSortList);
		StudentLFree(listForTest);
	}

	if(result && HeapSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		result = arraySortTest(S_HEAPSORT, listForTest, MergeSortArray);
		StudentLFree(listForTest);
	}





	if (result) {
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_QSORT, listForTest, QSortArray);
		StudentLFree(listForTest);
	}

	if(result && StudentLImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_INSERTSORT_ARRAYLIST, listForTest, ListSortArray);
		StudentLFree(listForTest);
	}

	if(result && StudentLImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		listSortBenchmark(S_INSERTSORT_LIST, listForTest, ListSortList);
		StudentLFree(listForTest);
	}


	if(result && StudentTImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_TREESORT_ARRAY, listForTest, TreeSortArray);
		//TODO: this is a bit of a problem with the existing interface from week 4-6 - fix next year
		//StudentLFree(listForTest);
	}

	if(result && StudentTImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		listSortBenchmark(S_TREESORT_LIST, listForTest, TreeSortList);
		StudentLFree(listForTest);
	}

	if(result && BubbleSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_BUBBLESORT, listForTest, BubbleSortArray);
		StudentLFree(listForTest);
	}

	if(result && SelectionSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_SELECTIONSORT, listForTest, SelectionSortArray);
		StudentLFree(listForTest);
	}

	if(result && MergeSortArrayImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_MERGESORT_ARRAY, listForTest, MergeSortArray);
		StudentLFree(listForTest);
	}

	if(result && MergeSortListImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		listSortBenchmark(S_MERGESORT_LIST, listForTest, MergeSortList);
		StudentLFree(listForTest);
	}

	if(result && HeapSortImplemented()){
		StudentLP *listForTest = deepLCopy(inputList);
		arraySortBenchmark(S_HEAPSORT, listForTest, MergeSortArray);
		StudentLFree(listForTest);
	}



	end = clock();

	exit(EXIT_SUCCESS);
}
