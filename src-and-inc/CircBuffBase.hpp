#include <iostream>

namespace kp
{   
    template <class Type>
    class CircBuffBase
    {
        protected:
            int size;
            Type* dyn_array;
            Type* head;
            Type* tail;
            int count_head{};
            int count_tail{};
            std::string name;

            bool isFullyEmpty() //calkowicie pusty
            {   
                if(head == tail && count_tail == count_head)
                {
                    return true;
                }
                return false;
            }

            bool isEmpty() //calkowicie lub czesciowo pusty
            {
                return !isFull();
            }

            bool isFull() //calkowicie pelny
            {
                if(head == tail && count_tail != count_head)
                {
                    return true;
                }
                return false;
            }   

            void printBuff()
            {
                std::cout << "{ ";
                if(count_head - count_tail == 0) //if empty
                {
                    std::cout << "}" << std::endl;
                    std::cout << "The buffer is empty!" << std::endl;
                }
                const Type* temp = tail;
                for(int i = 0; i < count_head - count_tail; i++)
                {
                    if(i == (count_head - count_tail - 1)) //if last iteration
                    {
                        std::cout << *temp << " }" << std::endl;
                    }else
                    {
                        std::cout << *temp << ", ";
                    }
                    (temp == (dyn_array + size - 1)) ? (temp = dyn_array) : temp++; 
                }
            }

        public:
            CircBuffBase(int size, std::string name) : size(size), name(name) 
            {
                dyn_array = new Type[size];
                head = dyn_array;
                tail = dyn_array;
            }
            ~CircBuffBase() { delete[] dyn_array; }

            virtual bool push(Type value) = 0; //ask if: virtual bool push(int value) = 0; is better

            bool pop(Type& value) //Type& number   number = *tail
            {
                if(!isFullyEmpty())
                {
                    value = *tail;
                    std::cout << *tail << " was extracted from buffer" << std::endl;
                    (tail == dyn_array + size - 1) ? tail = dyn_array : tail++;
                    count_tail++;
                    std::cout << "Buffer looks like this: ";
                    printBuff();
                    return true;
                }
                std::cout << "could not extract any value, the buffer is empty" << std::endl;
                printBuff();
                return false;
            }
    };
}
