#pragma once
#include "BOOK.h"

class BOOKwrapper
{
	BOOK* book;
	int num_of_changes_in_the_book;
public:
	BOOKwrapper(BOOK* bk)
	{
		book = bk;
		num_of_changes_in_the_book = 0;
	}
	BOOK* operator->() {
		num_of_changes_in_the_book++;
		return book;
	}
	int get_num_of_changes_in_the_book() {
		return num_of_changes_in_the_book;
	}
	void decr_num_of_changes_in_the_book() {
		--num_of_changes_in_the_book;
	}
};