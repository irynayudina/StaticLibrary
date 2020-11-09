#pragma once
#include "CELLCOLUMNS.h"
class SHEET
{
protected:
	char* name = NULL;
	int name_length;
	bool protection;
	CELLCOLUMNS* content = NULL;
	int content_length;
public:
	SHEET(void)
	{
		name = new char[5];
		name_length = 5;
		name[0] = 's';
		name[1] = 'h';
		name[2] = 'e';
		name[3] = 'e';
		name[4] = 't';
		content = new CELLCOLUMNS[3];
		content_length = 3;
		//for (int i = 0; i < content_length; i++) {
		//	//content[i] = '0';
		//}
		protection = false;
	}
	SHEET(char* _name, int _name_length, CELLCOLUMNS* _content, int _content_length, bool _protection)
	{
		this->name = new char[_name_length];
		for (int i = 0; i < _name_length; i++) {
			this->name[i] = _name[i];
		}
		this->content = new CELLCOLUMNS[_content_length];
		for (int i = 0; i < _content_length; i++) {
			this->content[i] = _content[i];
		}
		this->protection = _protection;
		this->content_length = _content_length;
		this->name_length = _name_length;
	}
	SHEET(SHEET& other)
	{
		if (this->protection == false) {
			this->name = new char[other.get_name_length()];
			for (int i = 0; i < other.get_name_length(); i++) {
				this->name[i] = other.get_name()[i];
			}
			this->content = new CELLCOLUMNS[other.get_content_length()];
			for (int i = 0; i < other.get_content_length(); i++) {
				this->content[i] = other.get_content()[i];
			}
			this->protection = other.get_protection();
			this->content_length = other.get_content_length();
			this->name_length = other.get_name_length();
		}
	}
	~SHEET() { delete[] name; delete[] content; }
	CELLCOLUMNS& operator[] (int col)
	{
		if (col >= content_length)
			throw exception("Matrix subscript out of bounds");
		return content[col];
	}
	CELLCOLUMNS  operator[] (int col) const
	{
		if (col >= content_length)
			throw exception("const Matrix subscript out of bounds");
		return content[col];
	}
	SHEET& operator=(SHEET& other)//not const to use get methods
	{
		if (this->protection == false) {
			this->protection = other.get_protection();
			this->content_length = other.get_content_length();
			this->name_length = other.get_name_length();
			if (this->name != NULL) {
				delete[] this->name;
			}
			this->name = new char[name_length];
			for (int i = 0; i < name_length; i++) {
				this->name[i] = other.get_name()[i];
			}
			if (this->content != NULL) {
				delete[] this->content;
			}
			this->content = new CELLCOLUMNS[content_length];
			for (int i = 0; i < content_length; i++) {
				this->content[i] = other.get_content()[i];
			}
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, const SHEET& point);
	friend istream& operator>> (istream& out, SHEET& point);

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
		}
	}
	bool get_protection() { return this->protection; }
	void set_protection(bool value) { this->protection = value; }
	CELLCOLUMNS* get_content() { return this->content; }
	void set_content(int size, CELLCOLUMNS* value) {
		if (this->protection == false) {
			if (this->content != NULL) {
				delete[] this->content;
			}
			this->content = new CELLCOLUMNS[size];
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
	void put_value(int size, CELLCOLUMNS* value)
	{
		set_content(size, value);
		set_content_length(size);
	}
	void get_value() { CELLCOLUMNS* get_content(); }
	CELL& changeCell(int i, int j) {
		if (i < content_length) {
			if (j < content[i].get_cols_()) {
				return content[i][j];
			}
		}
		// return a reference to the i-jth element
	}
};