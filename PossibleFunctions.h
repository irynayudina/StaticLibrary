#pragma once
#include <iostream>
#include "BOOKwrapper.h";
using namespace std;
void cell_selector(int& s, int& r, int& c, BOOK& b);

void name_enterer(int& count, char*& new_name);

void openBook(BOOKwrapper& bw);

void closseBook(BOOKwrapper& b);

void renameBook(BOOKwrapper& b);

void openNSheet(BOOKwrapper& b);

void closeNSheet(BOOKwrapper& b);

void renameNSheet(BOOKwrapper& b);

void opennkCellFromjSheet(BOOKwrapper& b);

void closenkCellFromjSheet(BOOKwrapper& b);

void renamenkCellFromjSheet(BOOKwrapper& b);

void putValuenkCelljSheet(BOOKwrapper& b);

void getValuenkCelljSheet(BOOKwrapper& b);

void saveBookToDisk(BOOK& b);

void getBookFromDisk(BOOK& b);

void addingSheet(BOOKwrapper& b);


void useLeftSidedFunc(BOOKwrapper& b);

void printBookWithInfo(BOOKwrapper& bw, BOOK& b);