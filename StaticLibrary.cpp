// StaticLibrary.cpp : Определяет функции для статической библиотеки.
//

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