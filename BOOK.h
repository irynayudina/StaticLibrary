#pragma once
#include "SHEET.h"
#include<fstream>
class BOOK
{
protected:
	char* name = NULL;
	int name_length;
	bool protection;
	SHEET* content = NULL;
	int content_length;
public:
	BOOK(void)
	{
		name = new char[5];
		name_length = 5;
		name[0] = 'b';
		name[1] = 'o';
		name[2] = 'o';
		name[3] = 'k';
		name[4] = '1';
		content = new SHEET[1];
		content_length = 1;
		protection = false;
	}
	BOOK(char* _name, int _name_length, SHEET* _content, int _content_length, bool _protection)
	{
		this->name = new char[_name_length];
		for (int i = 0; i < _name_length; i++) {
			this->name[i] = _name[i];
		}
		this->content = new SHEET[_content_length];
		for (int i = 0; i < _content_length; i++) {
			this->content[i] = _content[i];
		}
		this->protection = _protection;
		this->content_length = _content_length;
		this->name_length = _name_length;
	}
	BOOK(BOOK& other)
	{
		if (this->protection == false)
		{
			this->name = new char[other.get_name_length()];
			for (int i = 0; i < other.get_name_length(); i++) {
				this->name[i] = other.get_name()[i];
			}
			this->content = new SHEET[other.get_content_length()];
			for (int i = 0; i < other.get_content_length(); i++) {
				this->content[i] = other.get_content()[i];
			}
			this->protection = other.get_protection();
			this->content_length = other.get_content_length();
			this->name_length = other.get_name_length();
		}
	}
	~BOOK() { delete[] name; delete[] content; }
	SHEET& operator[] (int col)
	{
		if (col >= content_length)
			throw exception("Matrix subscript out of bounds");
		return content[col];
	}
	SHEET  operator[] (int col) const
	{
		if (col >= content_length)
			throw exception("const Matrix subscript out of bounds");
		return content[col];
	}
	BOOK& operator=(BOOK& other)
	{
		if (this->protection == false)
		{
			this->protection = other.get_protection();
			this->content_length = other.get_content_length();
			this->name_length = other.get_name_length();
			if (this->name != NULL) {
				delete[] this->name;
			}
			this->name = new char[other.get_name_length()];
			for (int i = 0; i < other.get_name_length(); i++) {
				this->name[i] = other.get_name()[i];
			}
			if (this->content != NULL) {
				delete[] this->content;
			}
			this->content = new SHEET[other.get_content_length()];
			for (int i = 0; i < other.get_content_length(); i++) {
				this->content[i] = other.get_content()[i];
			}
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, const BOOK& point);
	friend istream& operator>> (istream& out, BOOK& point);

	void save_to_the_disk()
	{
		ofstream writer("theCeil.txt", ofstream::app);
		writer << *this;
		writer.close();
	}
	void get_from_the_disk()
	{
		ifstream reader("theCeil.txt");
		reader >> *this;
		reader.close();
	}
	char* get_name() { return this->name; }
	void set_name(int size, char* value) {
		if (this->protection == false) {
			if (this->name != NULL) {
				delete[] this->name;
			}
			this->name = new char[size];
			for (int i = 0; i < size; i++) {
				this->name[i] = value[i];
			}
			set_name_length(size);
		}
	}
	bool get_protection() { return this->protection; }
	void set_protection(bool value) { this->protection = value; }
	SHEET* get_content() { return this->content; }
	void set_content(int size, SHEET* value) {
		if (this->protection == false) {
			if (this->content != NULL) {
				delete[] this->content;
			}
			this->content = new SHEET[size];
			for (int i = 0; i < size; i++) {
				this->content[i] = value[i];
			}
		}
	}
	int get_name_length() { return this->name_length; }
	void set_name_length(int value) {
		if (this->protection == false) {
			this->name_length = value;
		}
	}
	int get_content_length() { return this->content_length; }
	void set_content_length(int value) {
		if (this->protection == false) {
			this->content_length = value;
		}
	}

	void open() { set_protection(false); }
	void close() { set_protection(true); }
	void change_name(int size, char* value)
	{
		this->set_name(size, value);
		set_name_length(size);
	}
	void put_value_of_all_book(int size, SHEET* value)
	{
		set_content(size, value);
		set_content_length(size);
	}
	void get_value__of_all_book() { SHEET* get_content(); }
	BOOK* get_book() {
		return this;
	}
	void add_value(SHEET& value) {
		SHEET* temp_sheet = new SHEET[this->content_length];
		for (int i = 0; i < this->content_length; i++) {
			temp_sheet[i] = this->content[i];
		}
		this->content_length = this->content_length + 1;
		delete[] this->content;
		this->content = new SHEET[this->content_length];
		for (int i = 0; i < (this->content_length - 1); i++) {
			this->content[i] = temp_sheet[i];
		}
		this->content[this->content_length - 1] = value;
	}
};
