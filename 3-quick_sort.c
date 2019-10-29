#include "sort.h"

/**
 * inter_ints - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void inter_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * parti_lomuto - Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int parti_lomuto(int *array, size_t size, int left, int right)
{
	int *pivote, encima, debajo;

	pivote = array + right;
	for (encima = debajo = left; debajo < right; debajo++)
	{
		if (array[debajo] < *pivote)
		{
			if (encima < debajo)
			{
				inter_ints(array + debajo, array + encima);
				print_array(array, size);
			}
			encima++;
		}
	}

	if (array[encima] > *pivote)
	{
		inter_ints(array + encima, pivote);
		print_array(array, size);
	}

	return (encima);
}

/**
 * sort_lomuto - Implement the quicksort algorithm
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void sort_lomuto(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = parti_lomuto(array, size, left, right);
		sort_lomuto(array, size, left, partition - 1);
		sort_lomuto(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending.
 * @array:  array of integers.
 * @size: the size of the array.
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_lomuto(array, size, 0, size - 1);
}
