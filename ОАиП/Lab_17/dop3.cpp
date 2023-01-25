//Дан массив из 15 целых чисел на отрезке[-5; 5].Упорядочить массив, удалив повторяющиеся элементы.

#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int* a, int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            if (a[j - 1] > a[j])
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
}

int del(int* arr, int n)
{
    int buf;
    for (int i = 0; i < n; i++)
    {
        buf = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == buf)
            {
                n = n - 1;
                for (int a = j; a < n; a++)
                    arr[a] = arr[a + 1];

            }

        }

    }


    return n;
}


void randomize(int* arr, int n)
{
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = -5 + rand() % ((5 + 1) - -5);
        cout << arr[i] << " ";

    }
}

void print(int* arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";

    }
}
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива А :";
    cin >> n;
    int* arrA = new int[n];

    randomize(arrA, n);
    n = del(arrA, n);   
    n = del(arrA, n);
    print(arrA, n);
    bubbleSort(arrA, n);
    print(arrA, n);



}