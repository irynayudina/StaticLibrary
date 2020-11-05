// StaticLibrary.cpp : Определяет функции для статической библиотеки.
//
#include "StaticLibrary.h"
#include "pch.h"
#include "framework.h"
#include "BOOK.h"
#include "BOOKwrapper.h"
#include "CELL.h"
#include "CELLCOLUMNS.h"
#include "PossibleFunctions.h"
#include "SHEET.h"

ostream& operator<<(ostream& out, const BOOK& point)
{
	out << '\n' << point.name_length << " ";
	for (int i = 0; i < point.name_length; i++)
	{
		out << point.name[i];
	}
	out << " " << point.content_length << " ";
	for (int i = 0; i < point.content_length; i++)
	{
		out << point.content[i];
	}
	out << " " << point.protection << '\n';;
	return out;
}
istream& operator>> (istream& out, BOOK& point)
{
	out >> point.name_length;
	for (int i = 0; i < point.name_length; i++)
	{
		out >> point.name[i];
	}
	out >> point.content_length;
	for (int i = 0; i < point.content_length; i++)
	{
		out >> point.content[i];
	}
	out >> point.protection;
	return out;
}
ostream& operator<<(ostream& out, const CELL& point)
{
	out << '\n' << point.name_length << " ";
	for (int i = 0; i < point.name_length; i++)
	{
		out << point.name[i];
	}
	out << " " << point.content_length << " ";
	for (int i = 0; i < point.content_length; i++)
	{
		out << point.content[i];
	}
	out << " " << point.protection << '\n';;
	return out;
}
istream& operator>> (istream& out, CELL& point)
{
	int nl, cl, p;
	char* n; char* c;
	out >> nl;
	point.set_name_length(nl);
	n = new char[nl];
	for (int i = 0; i < nl; i++)
	{
		out >> n[i];
	}
	point.set_name(nl, n);
	out >> cl;
	point.set_content_length(cl);
	c = new char[cl];
	for (int i = 0; i < cl; i++)
	{
		out >> c[i];
	}
	point.set_content(cl, c);
	out >> p;
	point.set_protection(p);
	return out;
}
ostream& operator<<(ostream& out, const CELLCOLUMNS& point)
{
	out << '\n' << point.cols_ << " ";
	for (int i = 0; i < point.cols_; i++)
	{
		out << point.data_[i] << " ";
	}
	out << '\n';
	return out;
}
istream& operator>> (istream& out, CELLCOLUMNS& point)
{
	out >> point.cols_;
	for (int i = 0; i < point.cols_; i++)
	{
		out >> point.data_[i];
	}
	return out;
}
ostream& operator<<(ostream& out, const SHEET& point)
{
	out << '\n' << point.name_length << " ";
	for (int i = 0; i < point.name_length; i++)
	{
		out << point.name[i];
	}
	out << " " << point.content_length << " ";
	for (int i = 0; i < point.content_length; i++)
	{
		out << point.content[i];
	}
	out << " " << point.protection << '\n';;
	return out;
}
istream& operator>> (istream& out, SHEET& point)
{
	out >> point.name_length;
	for (int i = 0; i < point.name_length; i++)
	{
		out >> point.name[i];
	}
	out >> point.content_length;
	for (int i = 0; i < point.content_length; i++)
	{
		out >> point.content[i];
	}
	out >> point.protection;
	return out;
}
void cell_selector(int& s, int& r, int& c, BOOK& b)
{
    cout << "the number of SHEET: " << endl;
    cin >> s;
    cout << "the number of row: " << endl;
    cin >> r;
    cout << "the number of column: " << endl;
    cin >> c;
    if (s <0 || s > b.get_content_length() - 1) {
        s = 0;
    }
    if (r <0 || r > b.get_content()[s].get_content_length() - 1) {
        r = 0;
    }
    if (c <0 || c > b.get_content()[s][r].get_content_length() - 1) {
        c = 0;
    }
}

void name_enterer(int& count, char*& new_name)
{
    char ch = 1;
    char new_name_temp[100];
    while (ch != '/') {
        cout << "enter the symbol('/' to finish)" << endl;
        cin >> ch;
        if (ch != '/') {
            new_name_temp[count] = ch;
            ++count;
        }
    }
    new_name = new char[count];
    for (int i = 0; i < count; i++) {
        new_name[i] = new_name_temp[i];
    }
}




void openBook(BOOKwrapper& bw)
{
    bw->open();
}
void closseBook(BOOKwrapper& b)
{
    b->close();
}
void renameBook(BOOKwrapper& b)
{
    int count = 0;
    char* new_name = NULL;
    cout << "enter the name of the book without spaces:" << endl;
    name_enterer(count, new_name);
    b->change_name(count, new_name);
}

void openNSheet(BOOKwrapper& b)
{
    int nums;
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b->get_content_length()) {
        nums = 0;
    }
    b.decr_num_of_changes_in_the_book();
    b->get_content()[nums].open();
}

void closeNSheet(BOOKwrapper& b)
{
    int nums;
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b->get_content_length()) {
        nums = 0;
    }
    b.decr_num_of_changes_in_the_book();
    b->get_content()[nums].close();
}

void renameNSheet(BOOKwrapper& b)
{
    int count = 0;
    char* new_name = NULL;
    int num;
    cout << "enter the number of the sheet" << endl;
    cin >> num;
    if (num <0 || num > b->get_content_length()) {
        num = 0;
    }
    b.decr_num_of_changes_in_the_book();
    cout << "enter the name of the sheet without spaces:" << endl;
    name_enterer(count, new_name);
    b->get_content()[num].change_name(count, new_name);
}

void opennkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    b->get_content()[j][n][k].open();
}

void closenkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    b->get_content()[j][n][k].close();
}

void renamenkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    name_enterer(count, new_name);
    b->get_content()[j][n][k].change_name(count, new_name);
}

void putValuenkCelljSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    name_enterer(count, new_name);
    b->get_content()[j][n][k].put_value(count, new_name);
}

void getValuenkCelljSheet(BOOKwrapper& b)
{

    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    cell_selector(j, n, k, bk);
    name_enterer(count, new_name);
    b->get_content()[j][n][k].get_value();
}

void saveBookToDisk(BOOK& b)
{
    b.save_to_the_disk();
    cout << b << endl;
}

void getBookFromDisk(BOOK& b)
{
    b.get_from_the_disk();
    cout << b << endl;
}


void addingSheet(BOOKwrapper& b)
{
    SHEET s2;
    char* nameofcell;
    int sizeofname = 0;
    name_enterer(sizeofname, nameofcell);
    s2[0][0].change_name(sizeofname, nameofcell);
    b->add_value(s2);
}

void useLeftSidedFunc(BOOKwrapper& b)
{
    int s, r, c, sr;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(s, r, c, bk);
    cout << "number of sheet to get the first cell from: " << endl;
    cin >> sr;
    if (sr <0 || sr > b->get_content_length() - 1) {
        sr = 0;
    }
    b.decr_num_of_changes_in_the_book();
    bk[s].changeCell(r, c) = bk[sr][0][0];
}

void printBookWithInfo(BOOKwrapper& bw, BOOK& b)
{
    cout << "number of changes ever made to the book: " << endl;
    cout << bw.get_num_of_changes_in_the_book() << endl;
    cout << "the book: " << endl;
    cout << b << endl;
}