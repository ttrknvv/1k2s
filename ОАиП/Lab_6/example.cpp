#include <iostream>
using namespace std;
struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
int main()
{
    Number* begin = NULL, * end, * t;
    t = new Number;
    int p, size;
    cout << "\nEnter size queue=";  cin >> size;
    cout << "Enter number= ";       cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cout << "Enter number= ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //вывод на экран
        cout << "No elements" << endl;
    else
        view(begin);
    return 0;
}
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
}

