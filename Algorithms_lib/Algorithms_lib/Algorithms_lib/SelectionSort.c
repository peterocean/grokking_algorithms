#include "SelectionSort.h"

void SelectionSort(int array[], int32_t size)
{
	int32_t minValue = 0;
	int32_t minIndex = 0;
	int32_t i = 0;
	int32_t j = 0;

	for (i = 0; i < size; i++)
	{
		minIndex = i;
		minValue = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < minValue)
			{
				minIndex = j;
				minValue = array[j];
			}
		}
		array[minIndex] = array[i];
		array[i] = minValue;
	}
}