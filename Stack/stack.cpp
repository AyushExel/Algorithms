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

    auto push(const T item)
    {
        if(top == data.size()-1){
            data.resize(2*data.size());
        }
        data[++top] = item;

    }

    auto pop()
    {
        if(top == -1)
            std::cout << "Undeflow Error -> No elements in the stack\n";

        data[top--] = -1;

        if(top == data.size()/4 - 1)
            data.resize(data.size()/2);

    }

    auto print(){
         for(auto i = 0;i<=top;i++)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
    
    auto topElem()
    {   
        if(top != -1)
            std::cout << "The top element is " << data[top] << " \n";
        else
           std::cout << "The stack is empty \n" ; 
    }

    private:
    std::vector<T>data;
    int top;
};

template< typename T>
auto runStack(stack<T>& container)
{
    auto choice = -2;
    std::cout << "The following operations can be performed:\n Enter:\n 1 to push\n 2 to pop \n 3 to print the stack\n and -1 to exitn\n";
    while(std::cin >> choice)
    {   
        if(choice == -1)
           break;
        switch(choice)
            {
                case 1:
                std::cout << "Enter the value to push into stack \n";
                T elem;
                std::cin>>elem;
                container.push(elem);
                break;
        
                case 2:
                container.topElem();
                container.pop();
                break;

                case 3:
                container.print();
                break;

                default:
                std::cout << "ERROR! \n Input did not match any available operations. \n";
                std::cout << "The following operations can be performed:\n Enter:\n 1 to push\n 2 to pop \n 3 to print the stack\n and -1 to exitn\n";
                

            }
            std::cout << "Enter your next choice \n" ;

    }

    std::cout << std::endl;
    
}


int main(int argc, char const *argv[])
{   
    stack<> x;
    runStack(x);
    return 0;
}
