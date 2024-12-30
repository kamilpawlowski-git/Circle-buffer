#include <iostream>
#include <limits>
#include <string>
#include "CircBuffBase.hpp"
#include "OverwritingCircBuff.hpp"
#include "NonOverwritingCircBuff.hpp"

//przedstawienie dziala na int, na nienadpisujacym buforze
void start()
{
    kp::NonOverwritingCircBuff<int> object(8, "example");
    while(1)
    {   
        int startVariable;

        int choice;
        std::cout << "To insert data press \"1\", to extract data press \"2\": ";
        std::cin >> choice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input can be only integer number! 1 or 2!" << std::endl;
            continue;
        }

        if(choice == 1)
        {   
            int variable;
            std::cout << "Insert your number: ";
            std::cin >> variable;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input can be only integer number, once again" << std::endl;
                continue;
            }else
            {
                object.push(variable);
            }
        }else if(choice == 2)
        {
            object.pop(startVariable);
        }else
        {
            std::cout << "You provided incorrect operation, try again" << std::endl;
        }
    }
}

int main()
{
    start();

    //showtime
    /*
    kp::OverwritingCircBuff<int> overWritingBuffer(8, "overWritingBuffer");
    overWritingBuffer.push(1);
    overWritingBuffer.push(2);
    overWritingBuffer.push(3);
    overWritingBuffer.push(4);
    overWritingBuffer.push(5);
    overWritingBuffer.push(6);
    overWritingBuffer.push(7);
    overWritingBuffer.push(8);
    overWritingBuffer.push(9);
    overWritingBuffer.push(10);
    overWritingBuffer.push(11);
    overWritingBuffer.push(12);
    overWritingBuffer.push(13);

    int giveMeFirstValue;
    overWritingBuffer.pop(giveMeFirstValue);
    std::cout << "my first read value: " << giveMeFirstValue << std::endl;

    int giveMeSecondValue;
    overWritingBuffer.pop(giveMeSecondValue);
    std::cout << "my second read value: " << giveMeSecondValue << std::endl;
    */
}


