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
}

int main()
{
    std::cout << "Hello World!" << endl;
    cout << "Well, file commited" << endl;
    return 0;
}
