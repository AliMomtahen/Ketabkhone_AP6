#include"Document.hpp"




Document::Document(std::string _name , int _copies){
    title = _name;
    copies = _copies;
    if(title.size() == 0)
        throw Exception(TITLE_ERROR);
}


bool Document::has_same_title(std::string _title){
    if(title == _title)
        return 1;
    return 0;    
}


int Document::find_the_penalty(int delay){
    return 0;
}


bool Document::reduce_copies(){
    copies -= 1;
    if(copies <= 0 )
        return 1;
    return 0;    
}

bool Document::increas_copies(){
    copies++;
    if(copies <= 1)
        return 1;
    return 0;    
}


Reference::Reference() : Document(){
    penalty_delay = REFERENCE_TOTAL_PENALTY;
    max_extend_of_doc = MAX_EXTEND_OF_DOCS;
    delivery_deadline = RETURN_DEADLINE_REFERENCE;

}

Reference::Reference(std::string _name , int _copies) : Document(_name , _copies){
    delivery_deadline = RETURN_DEADLINE_REFERENCE;
    penalty_delay = REFERENCE_TOTAL_PENALTY;
    max_extend_of_doc = MAX_EXTEND_OF_DOCS;

}


int Reference::find_the_penalty(int delay){
    int total_penalty = 0;

    if(delay <= FIRST_DELAY_RETURN_DURATION_OF_REFERENCE)
        return delay * FIRST_DELAY_DURATION_PENALTY_OF_REFERENCE;
    else {
        total_penalty  += FIRST_DELAY_DURATION_PENALTY_OF_REFERENCE * FIRST_DELAY_RETURN_DURATION_OF_REFERENCE;
        delay = delay - FIRST_DELAY_RETURN_DURATION_OF_REFERENCE;

        total_penalty += delay * penalty_delay;

        return total_penalty;
    }   
}


Magazine::Magazine() : Document() {
    max_extend_of_doc = 0;
    delivery_deadline = RETURN_DEADLINE_MAGAZINE;
    
}


Magazine::Magazine(std::string _name , int _copies , int _year , int _number) : Document(_name , _copies){
    number = _number;
    year_created = _year;
    max_extend_of_doc = 0;
    delivery_deadline = RETURN_DEADLINE_MAGAZINE;
    if(number <= 0)
        throw Exception(NUMBER_ERROR);
    if(year_created <= 0)
    throw Exception(YEAR_ERROR);
    if(year_created < 1390)
        penalty_delay = OLD_MAGAZINE_TOTAL_PENALTY;
    else
        penalty_delay = NEW_MAGAZINE_TOTAL_PENALTY;

}

int Magazine::find_the_penalty(int delay){
    return delay * penalty_delay;
}

Book::Book() : Document(){
    penalty_delay = BOOK_TOTAL_PENALTY;
    max_extend_of_doc = MAX_EXTEND_OF_DOCS;
    delivery_deadline = RETURN_DEADLINE_BOOK;


}

Book::Book(std::string _name , int _copies) : Document(_name , _copies){
    penalty_delay = BOOK_TOTAL_PENALTY;
    delivery_deadline = RETURN_DEADLINE_BOOK;
    max_extend_of_doc = MAX_EXTEND_OF_DOCS;
}

int Book::find_the_penalty(int delay){
    int total_penalty = 0;
    if(delay <= FIRST_DELAY_RETURN_DURATION_OF_BOOK)
        return delay * FIRST_DELAY_DURATION_PENALTY_OF_BOOK;
    else {
        total_penalty  += FIRST_DELAY_DURATION_PENALTY_OF_BOOK * FIRST_DELAY_RETURN_DURATION_OF_BOOK;
        delay = delay - FIRST_DELAY_RETURN_DURATION_OF_BOOK;
        if(delay <= SECONDE_DELAY_RETURN_DURATION_OF_BOOK){
            total_penalty += delay * SECONDE_DELAY_DURATION_PENALTY_OF_BOOK;
            return total_penalty;
        }
        else{
            total_penalty += SECONDE_DELAY_DURATION_PENALTY_OF_BOOK * SECONDE_DELAY_RETURN_DURATION_OF_BOOK;
            delay = delay - SECONDE_DELAY_RETURN_DURATION_OF_BOOK;
            total_penalty += delay * penalty_delay;
            return total_penalty;
    

        }

    }    
}






BorrowedDocument::BorrowedDocument(Document *_doc , int now_date){
    doc = _doc;
    borrow_date = now_date;
    deadline = now_date + doc->get_delivery_deadline();
    extend_number = 0;
    max_extend = doc->get_max_extend_of_doc();
}


void BorrowedDocument::extend(int now_day){
    if(now_day == borrow_date)
        throw Exception(EXTENT_IN_BORROW_DAY_ERROR);
    if(now_day > deadline)
        throw Exception(EXTEND_AFTER_DEADLINE_ERROR);
    if(max_extend == 0 )
        throw Exception(EXTEND_MAGAZINE_ERROE);    
    if(extend_number >= max_extend)
        throw Exception(EXTEND_TWO_TIMES_ERROR);
    else{
        deadline = deadline + doc->get_delivery_deadline();
        extend_number++;
    }            
}



int BorrowedDocument::return_penalty_to_now(int now_day){

    if(now_day > deadline){
        int penalty =doc->find_the_penalty(now_day  - deadline); 
        return penalty;
    }
    else 
        return 0;
}


