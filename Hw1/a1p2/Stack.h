#include <iostream>

using namespace std;

template <class T>
class Stack 
{
    T *ptr;
    int size;
    int where;
public:
    Stack()
    {
        ptr = new T[10];
        size = 10;
        where = 0;
    };

    Stack(const Stack& src)
    {
        this->ptr = new T[src.size];
        if(ptr == NULL)
            exit(1);
        size = src.size;
        for(int i = 0; i < src.size; i++)
        {
            ptr[i] = src.ptr[i]; 
        }
        where = src.where;
    };

    Stack(int size)
    {
        this->ptr = new T[size];
        if(ptr == NULL)
            exit(1);
        this->size = size;
        where = 0;
    };
    
    bool push(T element);

    bool pop(T& out)
    {
        if(where <= 0)
            return false;
        
        out = ptr[where-1];
        where--;
        return true;
    };

    T back(void)
    {
        return ptr[where-1];
    };

    int getNumEntries()
    {
        return where;
    };

    ~Stack()
    {
        delete []ptr;
    };

    void print()        
    {
        for (int i = 0; i < where; i++)
            {
                cout<<ptr[i]<<"  ";
            }
        cout<<endl;
    }
};

template<class T>
bool Stack<T>::push(T element)
{
    if(where == size)
        return false;
    else
    {
        where++;
        ptr[where-1] = element;
        return true;
    }
}