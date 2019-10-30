#include "sort.h"

/**
 * radix_sort - sorts array Radix sort algorithm
 * @array: array to sort
 * @size: array's size
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	size_t i, j;
	int *newarray = NULL, k, d, count = 1, num = 0, c = 0;

	if (!array || !size)
		return;
	for (j = 0; j < size; j++)
	{
		if (num < array[j])
			num = array[j];	}
	while (num / 10 > 0)
	{ num = num / 10;
		count++; }
	newarray = calloc(size, sizeof(int));
	for (d = 0; d < count; d++)
	{ c = 0, k = 0;
		for (i = 0; i < size ; i++)
		{ k = i;
			for (j = 0; j < size ; j++)
			{
				if (d == 0)
				{
					if (array[j] % 10 == k)
					{
						newarray[c] = array[j];
						c++; } }
				if (d == 1)
				{
					if (array[j] / 10 == k)
					{
						newarray[c] = array[j];
						c++; } }
				if (d == 2)
				{
					if (array[j] / 100 == k)
					{ newarray[c] = array[j];
						c++; } } } }
		for (i = 0; i < size ; i++)
			array[i] = newarray[i];
		print_array(newarray, size); }
	free(newarray); }
