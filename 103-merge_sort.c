#include "sort.h"

/**
 * merging - merges the sub arrays into main array.
 * @a1: sub array 1
 * @a2: sub array 2
 * @size1: size of sub array 1.
 * @size2: size of sub array 2.
 * @a3: main array to which a1 and a2 to be merged
 * Return: void
 */
void merging(int *a1, int *a2, int size1, int size2, int *a3)
{
	int i = 0, j = 0, k = 0, size;

	size = size1 + size2;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(a1, size1);
	printf("[right]: ");
	print_array(a2, size2);
	for (i = 0; k < size; k++)
	{
		if (i >= size1)
		{
			a3[k] = a2[j];
			j++;
		}
		else if (j >= size2)
		{
			a3[k] = a1[i++];
		}
		else if (a1[i] < a2[j])
		{
			a3[k] = a1[i++];
		}
		else
		{
			a3[k] = a2[j++];
		}
	}

	for (i = 0; i < size; i++)
		a1[i] = a3[i];
	printf("[Done]: ");
	print_array(a1, size);
}

/**
 * div_merge - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @temp: temp array to malloc
 * Return: Nothing.
 */
void div_merge(int *array, size_t size, int *temp)
{
	int m;

	if (!array || size < 2)
		return;
	m = size / 2;
	div_merge(array, m, temp);
	div_merge(array + m,  size - m, temp);
	merging(array, array + m, m, size - m, temp);
}

/**
 * merge_sort - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	div_merge(array, size, temp);
	free(temp);
}
