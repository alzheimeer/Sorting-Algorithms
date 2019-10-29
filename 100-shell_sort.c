#include "sort.h"
/**
 * shell_sort - shell_sort
 * @array: the integer array to sort
 * @size: the size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t zz, i, j, pepe, n = 1;
	int temp;

	if (!array || !size)
		return;
	while (n < size)
		n = n * 3 + 1;
	pepe = ((n - 1) / 3);

	for (zz = pepe; zz; zz = (zz - 1) / 3)
	{
		for (i = zz; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > zz - 1 && array[j - zz] > temp; j -= zz)
			{
				array[j] = array[j - zz];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
