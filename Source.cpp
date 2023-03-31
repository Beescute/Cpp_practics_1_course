#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char surName[17];
	char ident[12];
	unsigned short year;
	float salary;
	struct Date date;
};

struct node {
	Record data;
	struct node* next;
};

struct node* myHead;
int countItem = 0;

void DrawLine() {
	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << "\n";
}

char* GetSpacebar(int count) {
	char* msg = new char[count];
	for (int i = 0; i < count; i++)
	{
		msg[i] = ' ';
	}
	msg[count] = '\0';
	return msg;
}

int GetSize(char* msg) {
	int size = 0;
	while (msg[size] != '\0')
		size++;
	return size;
}


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void Draw(struct Record* records, int num) {
	cout << endl;	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|����� ������"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|"; myCentr("�������", 16);
	cout << left << "|"; myCentr("��������", 11);
	cout << left << "|"; myCentr("��� ����", 10);
	cout << left << "|"; myCentr("�����", 10);
	cout << left << " |"; myCentr("���� ������ �� ������", 24);
	cout << "|" << endl;

	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	for (int i = 0; i < num; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].surName;
		cout << left << "|"; cout.width(11); cout << left << records[i].ident;
		cout << left << "|+"; cout.width(10); cout << left << records[i].year;
		std::cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << records[i].salary;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 26);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|����������: ����� ���������� �� ��������� �� 1 ������ 2000 ����"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

void editRusakov(struct Record* records) {
	for (int i = 0; i < 2; i++)
	{
		strcpy_s(records[i].surName, "�������");
	}
}

/// <summary>
/// Adding an element to the beginning of the dynamic list
/// </summary>
/// <param name="data"> element's data </param>
void addItem(Record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}
/// <summary>
/// Changing a list item
/// </summary>
/// <param name="index">index of the variable element</param>
/// <param name="data"> the value to change to </param>
void editItem(int index, Record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		current->data = data;
	}
	else {
		cout << endl << "������ ������ �� � ���������";
	}
}
/// <summary>
/// Inserting an item into a list
/// </summary>
/// <param name="index"> the index after which to insert </param>
/// <param name="data"> the value to be inserted </param>
void insertItem(int index, Record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

/// <summary>
/// Function for removing an item from a dynamic list
/// </summary>
/// <param name="index"> Index of the item being deleted </param>
void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem > 0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}
}

void printMyList() {
	struct node* current = myHead;
	cout << endl;
	while (current) {
		cout << " " << current->data.surName;
		current = current->next;
	}
}

void DrawWithList() {
	cout << endl;	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|����� ������"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|"; myCentr("�������", 16);
	cout << left << "|"; myCentr("��������", 11);
	cout << left << "|"; myCentr("��� ����", 10);
	cout << left << "|"; myCentr("�����", 10);
	cout << left << " |"; myCentr("���� ������ �� ������", 24);
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(16); cout << left << current->data.surName;
		cout << left << "|"; cout.width(11); cout << left << current->data.ident;
		cout << left << "|+"; cout.width(10); cout << left << current->data.year;
		cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << current->data.salary;
		cout << left << "|";
		printDate(current->data.date.day, current->data.date.month, current->data.date.year, 26);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|����������: ����� ���������� �� ��������� �� 1 ������ 2000 ����"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3];
	const int num = 3;

	records[0] = { "������", "�.�.", 1975, 517.50, {01,02,2010} };
	records[1] = { "��������", "�.�.", 1956, 219.10, {02,03,2020} };
	records[2] = { "����������", "�.�.", 1967, 300.10, {12,12,2012} };

	cout << "---�������� 0: �������� �������---";
	cout << endl << "���������� ������� ���������:";
	Draw(records, 3);
	cout << endl << "---�������� 1: ������ ���������---";
	cout << endl << "����� ������������ ��� ������ ����������� ��������� ������� ��������.";
	cout << endl << "��������� ������� � ������� �� �������:";
	editRusakov(records);
	Draw(records, 3);

	const int OLD_SIZE = 3;
	const int NEW_SIZE = 10;

	Record* A = (Record*)malloc(OLD_SIZE * sizeof(Record));
	if (!A) {
		cerr << "�� ������� �������� ������!" << endl; exit(1);
	}
	for (int i = 0; i < OLD_SIZE; i++) {
		strcpy_s(A[i].surName, records[i].surName);
	}
	Record** B = (Record**) new Record * [NEW_SIZE];
	for (int i = 0; i < NEW_SIZE; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = A[i];
	}
	A = (Record*)realloc(A, NEW_SIZE * sizeof(Record));

	//��� NEW_SIZE ���������� ���� ����� ������ �������
	B = (Record**) new Record * [10];
	for (int i = 0; i < NEW_SIZE; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = A[i];

	}
	cout << endl << "---�������� 2: ������������ ������ (3 ��������)---" << endl;
	for (int i = 0; i < NEW_SIZE; i++) {
		cout << " ����� A[i] = " << &A[i] << " ��������� ���� -> " << A[i].surName << endl;
		cout << " ����� B[i] = " << &B[i] << " ��������� ���� -> " << B[i]->surName << endl;
	}
	for (int i = 0; i < NEW_SIZE; i++) {
		delete B[i];
	}
	delete[] B;
	free(A);

	addItem(records[0]);
	addItem(records[1]);
	addItem(records[2]);
	cout << endl << "---�������� 3: ������������ ������---";
	cout << endl << "����� ���������� ������������� ������:";
	DrawWithList();
	struct Record newRecord = { "���������", "�.�.", 1984, 712.50, {01,02,2023} };
	insertItem(1, newRecord);
	cout << endl << "����� ���������� ��������:";
	DrawWithList();
	deleteItem(3);
	cout << endl << "����� �������� ��������:";
	DrawWithList();
	struct Record editRecord = { "������", "�.�.", 1962, 2000.75, {01,02,2023} };
	editItem(1, editRecord);
	cout << endl << "����� ��������� ��������:";
	DrawWithList();

	cout << endl << "---�������� 4: �����---";
	cout << endl << "��������� ������ �����:";

	FILE* textFile;
	fopen_s(&textFile, "textFile.txt", "w+");
	for (int i = 0; i < 3; i++) {
		fprintf(textFile, "%s %s %d %f %d %d %d \n", \
			records[i].surName, \
			records[i].ident, \
			records[i].year, \
			records[i].salary, \
			records[i].date.day, records[i].date.month, records[i].date.year);
	}
	fclose(textFile);

	fopen_s(&textFile, "textFile.txt", "r");
	Record readRecords[3];
	for (int i = 0; i < 3; i++) {
		fscanf_s(textFile, "%s", readRecords[i].surName, _countof(readRecords[i].surName));
		fscanf_s(textFile, "%s", readRecords[i].ident, _countof(readRecords[i].ident));
		fscanf_s(textFile, "%d", &readRecords[i].year);
		fscanf_s(textFile, "%f", &readRecords[i].salary);
		fscanf_s(textFile, "%d", &readRecords[i].date.day);
		fscanf_s(textFile, "%d", &readRecords[i].date.month);
		fscanf_s(textFile, "%d", &readRecords[i].date.year);
	}
	fclose(textFile);
	Draw(readRecords, 3);

	cout << endl << "�������� ������ �����:";
	FILE* binaryFile;
	fopen_s(&binaryFile, "binaryFile.txt", "w");
	fwrite(records, sizeof(records), 1, binaryFile);
	fclose(binaryFile);

	fopen_s(&binaryFile, "binaryFile.txt", "rb");
	fread_s(readRecords, sizeof(readRecords), sizeof(readRecords), 1, binaryFile);
	fclose(binaryFile);
	Draw(readRecords, 3);
	return 0;
}