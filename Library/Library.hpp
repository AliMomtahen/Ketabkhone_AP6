#ifndef __LIBRARY_HH__
#define __LIBRARY_HH__

#include <vector>
#include <string>
#include "Document.hpp"
#include "Person.hpp"
#include "Exception.hpp"



class Person;
class Document;

class Library {
public:
	Library();
	void add_student_member(std::string student_id, std::string student_name);
	void add_prof_member(std::string prof_name);
	void add_book(std::string book_title, int copies);
	void add_magazine(std::string magazine_title, int year, int number, int copies);
	void add_reference(std::string reference_title, int copies);
	void borrow(std::string member_name, std::string document_title);
	void extend(std::string member_name, std::string document_title);
	void return_document(std::string member_name, std::string document_title);
	int get_total_penalty(std::string member_name);
	std::vector< std::string > available_titles_list;
	std::vector< std::string > available_titles(){ return available_titles_list ;}
	void time_pass(int days);
	Person * find_member(std::string member_name);
	Document *find_docs(std::string docs_title);
    void delete_this_doc_from_titles(std::string title);
	void update();
private:
	std::vector<Document *> docs;
	std::vector<Person *> members;
	int date;
};

#endif