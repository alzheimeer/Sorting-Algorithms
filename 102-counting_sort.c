#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - counting sort algorithm
 * @array: array to be sorted
 * @size: array's size
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t j;
	int i, h = 0;
	int *array2 = NULL, *newarray = NULL;

	if (!array || !size)
		return;

	for (j = 0; j < size; j++)
	{
		if (h < array[j])
			h = array[j];
	}
	h = h + 1;

	newarray = calloc((size + 1), sizeof(int));
	if (!newarray)
		return;

	array2 = calloc((h + 1), sizeof(int));
	if (!array2)
		return;

	for (j = 0; j < size; j++)
		array2[array[j]] = array2[array[j]] + 1;
	for (i = 0; i < h; i++)
		array2[i + 1] = array2[i] + array2[i + 1];

	print_array(array2, h);

	for (j = 0; j < size; j++)
	{
		newarray[array2[array[j]] - 1] = array[j];
		array2[array[j]]  -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = newarray[j];
	free(array2);
	free(newarray);
}
