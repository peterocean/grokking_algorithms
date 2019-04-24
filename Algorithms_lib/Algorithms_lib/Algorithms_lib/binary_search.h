
#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */



#include "algorithms_lib_typedef.h"

typedef int32_t binary_search_comp(const void * elem1, const void *elem2, int32_t elem_size);

int32_t binary_search_temple(void *array, int32_t array_size, int32_t array_elem_size, void *key, binary_search_comp comp);

int32_t binary_search_int(int array[], int32_t size, int key);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif // !_BINARY_SEARCH_H_
