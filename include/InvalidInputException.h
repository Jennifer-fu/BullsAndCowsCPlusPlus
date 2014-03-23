#ifndef INVALIDINPUTEXCEPTION_H
#define INVALIDINPUTEXCEPTION_H

using namespace std;

class InvalidInputException
{
    public:
        InvalidInputException(string err_message);
        string get_message();
        virtual ~InvalidInputException();
    protected:
    private:
        string err_message;
};

#endif // INVALIDINPUTEXCEPTION_H
