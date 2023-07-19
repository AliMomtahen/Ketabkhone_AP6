#ifndef _PERSON_HH
#define _PERSON_HH

#include <bits/stdc++.h>
#include "Exception.hpp"
#include"Document.hpp"


const std::string NAME_ERROR = "Empty field";
const std::string NAME_UNIQ_ERROR = "Name already exists";
const std::string DAYS_ERROR = "Invalid day";
const std::string LIMIT_EXTEND_ERROR = "Maximum number of allowed borrows exceeded";



const int PROF_NUMBER_BORROW = 5;
const int STUDENT_NUMBER_BORROW = 2;





class Person{

protected:
    
    std::string name;
    std::vector<BorrowedDocument> borrowed_docs;
    int max_docs_can_borrow;
    int new_penalty;
    int certain_penalty;

public:
    Person();
    Person(std::string _name);

    bool is_same_whit_person(std::string _name);
    void borrow(Document *new_doc , int today_date);
    void extend(Document *doc , int today_date);
    void return_document(Document *doc , int today_date);
    int total_penalty(){ return new_penalty + certain_penalty;}
    void update_info(int today_date);
    


};


class Profesor : public Person{

private:
    



public:
    Profesor();
    Profesor(std::string);


};


class Student : public Person{

private:
    std::string student_id;


public:
    Student();
    Student(std::string _name , std::string id);

};




#endif