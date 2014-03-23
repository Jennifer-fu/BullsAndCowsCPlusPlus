#include <string>
#include "InvalidInputException.h"

using namespace std;

InvalidInputException::InvalidInputException(string err_message)
{
    this->err_message = err_message;
}

string InvalidInputException::get_message()
{
    return err_message;
}

InvalidInputException::~InvalidInputException()
{
    //dtor
}
