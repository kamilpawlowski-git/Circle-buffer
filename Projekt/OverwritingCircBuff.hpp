#include <iostream>

namespace kp
{
    template<class Type>
    class OverwritingCircBuff : public CircBuffBase<Type>
    {
        public:
            OverwritingCircBuff(int size, std::string name) : CircBuffBase<Type>(size, name) {}  

            bool push(Type value) override 
            {
                *(this->head) = value;
                (this->head < this->dyn_array + this->size - 1) ? (this->head++) : (this->head = this->dyn_array);
                this->count_head++;
                std::cout << value << " was correcly inserted into the buffer" << std::endl; 
                std::cout << "Buffer looks like this: ";
                if(this->tail == ((this->head - 1) && abs(this->count_tail - this->count_head) == this->size + 1))
                {
                    this->tail++;
                    this->count_tail++;
                }
                this->printBuff();
                return true;
            }
    };
}