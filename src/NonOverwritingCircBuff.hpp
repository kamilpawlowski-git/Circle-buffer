#include <iostream>

namespace kp
{
    template<class Type>
    class NonOverwritingCircBuff : public CircBuffBase<Type>
    {
        public:
            NonOverwritingCircBuff(int size, std::string name) : CircBuffBase<Type>(size, name) {}

            bool push(Type value) override
            {
                if(this->isEmpty())
                {
                    *(this->head) = value;
                    (this->head < this->dyn_array + this->size - 1) ? (this->head++) : (this->head = this->dyn_array);
                    this->count_head++;
                    std::cout << value << " was correcly inserted into the buffer" << std::endl; 
                    std::cout << "Buffer looks like this: ";
                    this->printBuff();
                    return true;
                }
                std::cout << value << " could not be inserted, buffer is full" << std::endl;
                this->printBuff();
                return false;
            }
    };
}