#include "Library.hpp"
#include <iostream>

using namespace std;



int main() {
	Library ut_lib;
	ut_lib.add_student_member("fff", "hasan");

	ut_lib.add_book("book1",2);
	ut_lib.add_book("book2" , 5);
	ut_lib.add_reference("R1" , 1);
	ut_lib.add_magazine("m1" , 4 , 1 ,2 );
	ut_lib.borrow("hasan" , "book1");
	ut_lib.add_prof_member("ali" );
	ut_lib.borrow("ali" , "m1");
	ut_lib.borrow("ali" , "book1");
	ut_lib.time_pass(1);

	ut_lib.extend("ali" , "book1");




	
	ut_lib.extend("ali" , "m1");

	ut_lib.return_document("ali" , "m1");
	cout << ut_lib.get_total_penalty("ali") << '\n';

	ut_lib.time_pass(10);

	cout << ut_lib.get_total_penalty("hasan") << '\n';
	cout << ut_lib.get_total_penalty("ali") << '\n';

}