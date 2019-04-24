#include "binary_search.h"



/*
*@brief     通用二分法查找函数模版
*@author	 阳永锋
*@date		 20190424
*@param[out]
*@param[in]	$MethodArg$
*@return	$SymbolType$
*/
int32_t binary_search_temple(void *array, int32_t array_size, int32_t array_elem_size, void *key,binary_search_comp comp)
{
	int32_t low = 0;
	int32_t high = array_size - 1;
	int32_t mid = 0;
	int32_t comp_res = 0;
	
	if (array == NULL || key == NULL)
		return -1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		comp_res = comp((uint8_t*)array + mid * array_elem_size, key, array_elem_size);
		if (comp_res < 0)
			low = mid + 1;
		else if (comp_res > 0)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

/*
*@brief      整数数组二分法查找
*@author	 阳永锋
*@date		 20190424
*@param[out]
*@param[in]	$MethodArg$
*@return	$SymbolType$
*/
int32_t binary_search_int(int array[], int32_t size,int key)
{
	int32_t low = 0;
	int32_t high = size - 1;
	int32_t mid = 0;

	if (array == NULL || key == NULL)
		return -1;

	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (array[mid] == key )
		{
			return mid;
		}
		else if (array[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}