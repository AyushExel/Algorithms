/*
Efficient implementation of standard data structure, stack
- This implementation uses vectors instead of C-style array because its always advised to use vectors over arrays
- This implementation also takes care of stack overflow and underflow by employing some workarounds
*/

#include <iostream>
#include <vector>

template<typename T=int>
class stack
{   public:
    
    stack():data(std::vector<T>(1)),top(-1){};

    stack(std::initializer_list<T>init):data(init),top(data.size()-1){}

    auto push(T item)
    {
        if(top == data.size()-1){
            data.resize(2*data.size());
        }
        data[++top] = item;

    }

    auto pop()
    {
        
    }
    private:
    std::vector<T>data;
    int top;
};



int main(int argc, char const *argv[])
{   

    return 0;
}
