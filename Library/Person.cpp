#include"Person.hpp"





Person::Person(){

}

Person::Person(std::string _name){
    name = _name;
    if(name.size() == 0)
        throw Exception(NAME_ERROR);
}

void Person::extend(Document *doc , int today_date){
    for(int i=0 ; i < borrowed_docs.size() ; i++){
        if(doc->get_title() == borrowed_docs[i].doc->get_title()){
            borrowed_docs[i].extend(today_date);
        }
    }

}


void Person::update_info(int today_date){
    new_penalty = 0;
    for(int i=0 ;i < borrowed_docs.size() ; i++){
        new_penalty = new_penalty +  borrowed_docs[i].return_penalty_to_now(today_date);
    }

}


bool Person::is_same_whit_person(std::string _name){
    if(_name == name)
        return 1;
    return 0;
}



void Person::return_document(Document *doc , int today_date){
    for(int i=0 ; i < borrowed_docs.size() ; i++){
        if(doc->get_title() == borrowed_docs[i].doc->get_title()){
            int penalt_of_this_doc = borrowed_docs[i].return_penalty_to_now(today_date);
            certain_penalty += penalt_of_this_doc;
            new_penalty -= penalt_of_this_doc;
            borrowed_docs.erase(borrowed_docs.begin() +  i);
            return;
        }
    }
}



void Person::borrow(Document *doc , int today_date){
    if(borrowed_docs.size() >= max_docs_can_borrow)
        throw Exception(LIMIT_EXTEND_ERROR);
    borrowed_docs.push_back( BorrowedDocument(doc , today_date));    
}







Student::Student() : Person(){
    student_id = 1;
}

Student::Student(std::string _name , std::string id) : Person(_name) {
    student_id = id;
    max_docs_can_borrow = STUDENT_NUMBER_BORROW;
    if(student_id.size() == 0)
        throw Exception(NAME_ERROR);
}


Profesor::Profesor() : Person(){

}

Profesor::Profesor(std::string _name) : Person(_name){
    max_docs_can_borrow = PROF_NUMBER_BORROW;
}





