#include <iostream>

int founder(int* arr, int size, int ref_point)
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    int middle = 0, left = 0, right = size;
    int point = 0, count = 0;
    do
    {
        middle = (left + right) / 2;

        if (arr[middle] > ref_point)
        {
            right = middle - 1;
            point = middle;
        }
        else if (arr[middle] < ref_point)
        {
            left = middle + 1;
        }
        if (arr[middle] == ref_point)
        {
            left = middle + 1;
            point = left;
        }
    } while (left <= right);

    for (int i = point; i < size; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    setlocale(0, "");

    int ref_point, size;
    int arr[]{ 14,16,19,32,32,32,56,69,72 };
    size = sizeof(arr) / sizeof(*arr);

    std::cout << "Введите точку отсчёта: ";
    std::cin >> ref_point;
    std::cout << "\nКоличество элементов в массиве больших, чем " << ref_point << ": " << founder(arr, size, ref_point) << std::endl;
}