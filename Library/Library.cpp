#include"Library.hpp"



Library::Library(){
    date = 1;
}




Person *  Library::find_member(std::string member_name){
    for(int i=0; i < members.size() ; i++){
        if(members[i]->is_same_whit_person(member_name))
            return members[i];
    }
    return NULL;
}

Document *  Library::find_docs(std::string docs_title){
    for(int i=0; i < docs.size() ; i++){
        if(docs[i]->has_same_title(docs_title))
            return docs[i];
    }
    return NULL;
}


void Library::add_student_member(std::string student_id, std::string student_name){
    try{
        Person * exist_member = find_member(student_name);
        if(exist_member != NULL){
            std::cout << NAME_UNIQ_ERROR << '\n';
            exit(EXIT_SUCCESS);
        }
        members.push_back(new Student(student_name , student_id));
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
}


void Library::add_prof_member(std::string prof_name){
    try{
        Person * exist_member = find_member(prof_name);
        if(exist_member != NULL){
            std::cout << NAME_UNIQ_ERROR << '\n';
            exit(EXIT_SUCCESS);

        }
        members.push_back(new Profesor(prof_name));
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
}


void Library::add_book(std::string book_title, int copies){
    try{
        Document *exist_doc = find_docs(book_title);
        if(exist_doc != NULL){
                std::cout << TITLE_UNIQ_ERROR << '\n';
                exit(EXIT_SUCCESS);
            }

        docs.push_back(new Book(book_title , copies));
        available_titles_list.push_back(book_title);
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
    

}




void Library::add_magazine(std::string magazine_title, int year, int number, int copies){
    try{
        Document *exist_doc = find_docs(magazine_title);
        if(exist_doc != NULL){
            std::cout << TITLE_UNIQ_ERROR << '\n';
            exit(EXIT_SUCCESS);

        }
    
    
    docs.push_back(new Magazine(magazine_title , copies , year , number));
    available_titles_list.push_back(magazine_title);
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
}

void Library::delete_this_doc_from_titles(std::string title){
    for(int i=0 ; i < available_titles_list.size() ; i++){
        if(available_titles_list[i] == title){
            available_titles_list.erase(available_titles_list.begin() + i);
            return;
        }
    }
}



void Library::add_reference(std::string reference_title, int copies){
    try{
        Document *exist_doc = find_docs(reference_title);
        if(exist_doc != NULL){
                std::cout << TITLE_UNIQ_ERROR << '\n';
                exit(EXIT_SUCCESS);

        }

        docs.push_back(new Reference(reference_title , copies));
        available_titles_list.push_back(reference_title);
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
}

void Library::borrow(std::string member_name, std::string document_title){
    Person *person = find_member(member_name);
    Document *borrowed_doc = find_docs(document_title);
    try{
        person->borrow(borrowed_doc , date);
        bool is_runing_out_copies = borrowed_doc->reduce_copies();
        if(is_runing_out_copies)
            delete_this_doc_from_titles(borrowed_doc->get_title());
    }
    catch(Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
    
}

void Library::extend(std::string member_name, std::string document_title){
    Person *person = find_member(member_name);
    Document *borrowed_doc = find_docs(document_title);
    try{
        person->extend(borrowed_doc , date);
    }
    catch( Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
    
}


void Library::return_document(std::string member_name, std::string document_title){
    Person *person = find_member(member_name);
    Document *borrowed_doc = find_docs(document_title);
    try{
        person->return_document(borrowed_doc , date);
        bool not_have_copies_this_doc = borrowed_doc->increas_copies();
        if(not_have_copies_this_doc)
            available_titles_list.push_back(borrowed_doc->get_title());

    }
    catch( Exception &error_hapens){
        error_hapens.print_message();
        exit(EXIT_SUCCESS);
    }
}



int Library::get_total_penalty(std::string member_name){
    Person *person = find_member(member_name);
    return person->total_penalty();
}

void Library::time_pass(int days){
    if(days < 0){
        std::cout << DAYS_ERROR << '\n';
        exit(EXIT_SUCCESS);
    }
    
    date = date + days;
    update();

}


void Library::update(){
    for(int i=0 ; i < members.size() ; i++){
        members[i]->update_info(date);
    }
}
