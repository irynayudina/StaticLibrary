#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class CELL
{
protected:
	char* name = NULL;
	int name_length;
	bool protection;
private:
	char* content = NULL;
	int content_length;
public:

	CELL(void)
	{
		name = new char[5];
		name_length = 5;
		name[0] = 'c';
		name[1] = 'e';
		name[2] = 'i';
		name[3] = 'l';
		name[4] = '1';
		content = new char[100];
		content_length = 100;
		for (int i = 0; i < content_length; i++) {
			content[i] = '0';
		}
		protection = false;

	}
	CELL(char* _name, int _name_length, char* _content, int _content_length, bool _protection)
	{
		this->name = new char[_name_length];
		for (int i = 0; i < _name_length; i++) {
			this->name[i] = _name[i];
		}
		this->content = new char[_content_length];
		for (int i = 0; i < _content_length; i++) {
			this->content[i] = _content[i];
		}
		this->protection = _protection;
		this->content_length = _content_length;
		this->name_length = _name_length;
	}
	CELL(CELL& other)
	{
		if (this->protection == false) {
			this->name = new char[other.get_name_length()];
			for (int i = 0; i < other.get_name_length(); i++) {
				this->name[i] = other.get_name()[i];
			}
			this->content = new char[other.get_content_length()];
			for (int i = 0; i < other.get_content_length(); i++) {
				this->content[i] = other.get_content()[i];
			}
			this->protection = other.get_protection();
			this->content_length = other.get_content_length();
			this->name_length = other.get_name_length();
		}
	}
	~CELL() { delete[] name; delete[] content; }
	char& operator[] (int col)
	{
		if (col >= content_length)
			throw exception("Matrix subscript out of bounds");
		return content[col];
	}
	char  operator[] (int col) const
	{
		if (col >= content_length)
			throw exception("const Matrix subscript out of bounds");
		return content[col];
	}
	CELL& operator=(CELL& other)
	{
		if (this->protection == false) {
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
			this->content = new char[other.get_content_length()];
			for (int i = 0; i < other.get_content_length(); i++) {
				this->content[i] = other.get_content()[i];
			}
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, const CELL& point);
	friend istream& operator>> (istream& out, CELL& point);

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
	char* get_content() { return this->content; }
	void set_content(int size, char* value) {
		if (this->protection == false) {
			if (this->content != NULL) {
				delete[] this->content;
			}
			this->content = new char[size];
			for (int i = 0; i < size; i++) {
				this->content[i] = value[i];
			}
		}
	}
	bool get_protection() { return this->protection; }
	void set_protection(bool value) { this->protection = value; }
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
	void put_value(int size, char* value)
	{
		set_content(size, value);
		set_content_length(size);
	}
	void get_value() { char* get_content(); }

};
