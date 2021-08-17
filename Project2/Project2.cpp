#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

struct Queue
{
    int count;
    Queue* next;
};

void View(Queue* first)
{
    if (first == NULL)
    {
        cout << "Queue is empty, goodbye" << endl;
        return;
    }
    cout << "Your queue : ";
    while (first != NULL)
    {
        cout << first->count << " ";
        first = first->next;
    }
    cout << endl;
}

void PushFront (Queue** first, int a)
{
    if ((*first) == NULL)
    {
        Queue* ptr = new Queue; 
        ptr->next = NULL;
        *first = ptr;
        ptr->count = a;
    }
    else 
    {
        Queue* ptr = new Queue;
        ptr->next = *first;
        *first = ptr;
        ptr->count = a;
    }
}

void CleaningMemory (Queue* first)
{
    while (first != NULL)
    {
        Queue * ptr = first;
        first = first->next;
        delete ptr;
    }
}

void PossiblyFutureTask(Queue** first)
{

}

void maintask1(Queue** first)
{
    if ((*first) == NULL)
    {
        cout << "There is only no elements" << endl;
        return;
    }
    Queue* ptr = *first;
    for (int i = 0; ptr != NULL; i++)
    {
        if (i == 0)
        {
            *first = (*first)->next;
            delete ptr;
            ptr = *first;
        }
        else if (ptr->next)
        {
            Queue* del = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            delete del;
        }
        else ptr = NULL;
    }
}

int main()
{
    Queue* first = NULL;
    bool endsign = false;
    int wish, amount;
    while (endsign == false)
    {
        cout << "Press 1 to enter/create new queue" << endl <<
            "Press 2 to view the queue" << endl <<
            "Press 3 to do main task1" << endl <<
            "Press 4 to do main task2" << endl <<
            "Press 5 to finish the perfomance" << endl;
        cin >> wish;
        switch (wish)
        {
        case 1: 
            cout << "Enter the amount of elements : ";
            cin >> amount;
            cout << "Enter exact elements : " << endl;
            for (int i = 0; i < amount; i++)
            {
                int el;
                cin >> el;
                PushFront(&first, el);
            }
            break;

        case 2:
            View(first);
            break;

        case 3: 
            maintask1(&first);
            break;

        case 4:
            maintask2(&first);
            break;
        case 5:
            cout << "Hope that was interesting to work with me, goodbye!" << endl;
            CleaningMemory(first);
            endsign = true;
            break;

        default: cout << "Enter something possible to work with !!" << endl; 
            break;
        }
    }
    return 0;
}
