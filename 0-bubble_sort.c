#include "sort.h"
/**
 * bubble_sort - sorting bubble sort method
 * @array: array
 * @size: array size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int temp,  flag;

	if (array == NULL || size < 2)
		return;
	for (; flag; )
	{
		flag = 0;
		for (j = 0; j < (size - 1); j++)
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
	}
}
