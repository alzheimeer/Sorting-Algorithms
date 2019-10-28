#include "sort.h"

/**
 * inter_int - Swap two integers in an array.
 * @a: The first integer.
 * @b: the second integer.
 */
void inter_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t f, fi;

	if (array == NULL || size < 2)
		return;

	for (f = 0; f < size - 1; f++)
	{
		min = array + f;
		for (fi = f + 1; fi < size; fi++)
			min = (array[fi] < *min) ? (array + fi) : min;

		if ((array + f) != min)
		{
			inter_int(array + f, min);
			print_array(array, size);
		}
	}
}
