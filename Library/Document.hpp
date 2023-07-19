#ifndef _DOCUMENT_HH
#define _DOCUMENT_HH


#include <bits/stdc++.h>
#include "Exception.hpp"


const std::string YEAR_ERROR = "Invalid year";
const std::string NUMBER_ERROR = "Invalid number";
const std::string TITLE_ERROR = "Empty field";
const std::string TITLE_UNIQ_ERROR = "A document with the specified name already exists";
const std::string EXTENT_IN_BORROW_DAY_ERROR = "You can't extend and borrow a document on the same day";
const std::string EXTEND_AFTER_DEADLINE_ERROR = "You can't renew a document after receiving a penalty";
const std::string EXTEND_TWO_TIMES_ERROR = "You can't renew a document more than two times";
const std::string EXTEND_MAGAZINE_ERROE = "You can't renew magazines";


const int MAX_EXTEND_OF_DOCS = 2;
const int RETURN_DEADLINE_BOOK = 10;
const int RETURN_DEADLINE_REFERENCE = 5;
const int RETURN_DEADLINE_MAGAZINE = 2;
const int FIRST_DELAY_RETURN_DURATION_OF_BOOK = 7;
const int FIRST_DELAY_RETURN_DURATION_OF_REFERENCE = 3;
const int FIRST_DELAY_RETURN_DURATION_OF_MAGAZINE = 0;
const int SECONDE_DELAY_RETURN_DURATION_OF_BOOK = 14;
const int SECONDE_DELAY_RETURN_DURATION_OF_REFERENCE = 0;
const int SECONDE_DELAY_RETURN_DURATION_OF_MAGAZINE = 0;
const int FIRST_DELAY_DURATION_PENALTY_OF_BOOK = 2000;
const int FIRST_DELAY_DURATION_PENALTY_OF_REFERENCE = 5000;
const int SECONDE_DELAY_DURATION_PENALTY_OF_BOOK = 3000;

const int BOOK_TOTAL_PENALTY = 5000;
const int OLD_MAGAZINE_TOTAL_PENALTY = 2000;
const int NEW_MAGAZINE_TOTAL_PENALTY =  3000;
const int REFERENCE_TOTAL_PENALTY = 7000;





class Document{
protected:
    std::string title;
    int copies;
    int penalty_delay;
    int delivery_deadline;
    int max_extend_of_doc;

    

    
public:
    Document(){ copies = 1;}
    Document(std::string title , int copies);
    bool has_same_title(std::string _title);
    std::string get_title(){ return title;}
    int get_delivery_deadline(){ return delivery_deadline;}
    int get_max_extend_of_doc(){ return max_extend_of_doc;}
    bool reduce_copies();
    bool increas_copies();
    virtual int find_the_penalty(int delay);


};    



class Book : public Document{
private:




public:
    Book();
    Book(std::string _name , int copies);
    virtual int find_the_penalty(int delay);
};



class Reference : public Document{
private:


public:
    Reference();
    Reference(std::string _name , int copies);
    virtual int find_the_penalty(int delay);
};

class Magazine : public Document{
public:    
    Magazine();
    Magazine(std::string _name , int _copies , int _year , int _number);
    virtual int find_the_penalty(int delay);

private:
    int year_created;
    int number;

};



class BorrowedDocument{
private:
    int max_extend;
    int extend_number;

public:
    Document *doc;
    int borrow_date;
    int deadline;
    int max_borrowed;
    
    BorrowedDocument(){ }
    BorrowedDocument(Document *_doc , int now_date );
    void extend(int now_day);
    int return_penalty_to_now(int now_date);
    void update(int now_day);
    
};



#endif