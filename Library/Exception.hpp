#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include<iostream>
#include<string>



class Exception {
public:
    Exception(){}
    Exception(std::string _message);
    std::string message;
    void print_message(){ std::cout << message ;}
};


class DocumentException{

public:
    DocumentException();
    DocumentException(std::string _message);
    std::string message;

};










#endif