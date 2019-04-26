

#include <iostream>
#include <iomanip>
#include "algorithms_lib.h"
using namespace std;

#define BINARY_SEARCH_ARRAY_SIZE (100u)
#define SELECTION_SORT_ARRAY_SIZE (20u)

void create_binary_search_int_array(int32_t array[], int32_t size)
{
	int32_t index = 0;

	for (index = 0; index < size; index++)
	{
		if (index == 0)
		{
			array[index] = rand() % 10;
		}
		else
		{
			array[index] = array[index - 1] + rand() % 10;
		}
	}
}

void create_selection_sort_test_array(int32_t array[], int32_t size)
{
	int32_t index = 0;

	for (index = 0; index < size; index++)
	{
		array[index] = rand() % 1000;
	}
}


void print_binary_search_int_array(int32_t array[], int32_t size)
{
	int32_t index = 0;
	int32_t temp = 0;

	for (index = 0; index < size; index++)
	{
		temp = array[index];
		std::cout<<left << setw(5) << temp << ",";
		if ((index + 1) % 10 == 0 && index != 0)
			std::cout << endl;
	}
}

void binary_search_int_test(void)
{
	int32_t pos = 0;
	int32_t key = 0;
	int32_t *array = (int32_t*)malloc(BINARY_SEARCH_ARRAY_SIZE*sizeof(int32_t));

	create_binary_search_int_array(array, BINARY_SEARCH_ARRAY_SIZE);
	std::cout << "Init array: \n" << endl;

	print_binary_search_int_array(array, BINARY_SEARCH_ARRAY_SIZE);

	for (int i = 0; i < 10; i++) {
		std::cout << "binary_search_int() test:" << i + 1  << endl;
		pos = rand() % 100;
		key = array[pos];
		std::cout << "key position:" << pos << "   " << "key value:" << key << endl;
		if (pos != binary_search_int(array, BINARY_SEARCH_ARRAY_SIZE, key))
			std::cout << "binary_search_int(): test fail!" << endl;
		else
			std::cout << "binary_search_int() work well!" << endl;
	}
	std::cout << "binary_search_int(): test pass!" << endl;
	free(array);
}

static int32_t int_compare(const void *elem1, const void *elem2, int32_t elem_size)
{
	int32_t temp1 = *(int32_t*)elem1;
	int32_t temp2 = *(int32_t*)elem2;

	if (temp1 < temp2)
		return -1;
	else if (temp1 > temp2)
		return 1;
	else
		return 0;
}

static void binary_search_temple_test(void)
{
	int32_t pos = 0;
	int32_t key = 0;
	int32_t *array = (int32_t*)malloc(BINARY_SEARCH_ARRAY_SIZE * sizeof(int32_t));

	create_binary_search_int_array(array, BINARY_SEARCH_ARRAY_SIZE);
	std::cout << "Init array: \n" << endl;

	print_binary_search_int_array(array, BINARY_SEARCH_ARRAY_SIZE);

	for (int i = 0; i < 10; i++) {
		std::cout << "binary_search_int() test:" << i + 1 << endl;
		pos = rand() % 100;
		key = array[pos];
		std::cout << "key position:" << pos << "   " << "key value:" << key << endl;
		if (pos != binary_search_temple(array, BINARY_SEARCH_ARRAY_SIZE,sizeof(int32_t), &key, int_compare))
			std::cout << "binary_search_int(): test fail!" << endl;
		else
			std::cout << "binary_search_int() work well!" << endl;
	}
	std::cout << "binary_search_int(): test pass!" << endl;
	free(array);
}

void selectionSortUnitTest(void)
{
	int32_t pos = 0;
	int32_t key = 0;
	int32_t *array = (int32_t*)malloc(SELECTION_SORT_ARRAY_SIZE * sizeof(int32_t));

	create_selection_sort_test_array(array, SELECTION_SORT_ARRAY_SIZE);
	std::cout << "Before selection sort,Init array:" << endl;

	print_binary_search_int_array(array, SELECTION_SORT_ARRAY_SIZE);
	SelectionSort(array, SELECTION_SORT_ARRAY_SIZE);

	std::cout << "After selection sort, array: " << endl;
	print_binary_search_int_array(array, SELECTION_SORT_ARRAY_SIZE);
	free(array);
}
int main()
{
	//binary_search_int_test();
	//binary_search_temple_test();
	selectionSortUnitTest();
}