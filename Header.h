#pragma once
#include <iostream>// ���������� �����-������
#include <fstream>// ���������� ��� ������ � �������
#include <string>// ���������� ��� ������ �� ��������
#include <time.h>// ���������� ��� ������ �� ��������
#include <vector>// ���������� ��� �������� �������
#include <cstdlib>// ���������� ��� ������ � �������� srand
using namespace std;
class wed 
{
public:
	string male_name;// ��� ������
	string female_name;// ��� �������
	string marrige_date;
	int male_year;// ��� �������� ������
	int female_year;// ��� �������� �������
	/*���������� ������*/
	wed(string _male_name = "None", int _male_year = 0, string _female_name = "None", \
		int _female_year = 0, string _marrige_date = "None")
	{
		male_name = _male_name;
		male_year = _male_year;
		female_name = _female_name;
		female_year = _female_year;
		marrige_date = _marrige_date;
	}
	//wed(string& s);
	/*������������� ������� ���������� ���������*/
	friend bool operator== (wed b1, wed b2);
	friend bool operator< (wed b1, wed b2);
	friend bool operator> (wed b1, wed b2);
	friend bool operator<= (wed b1, wed b2);
	friend bool operator>= (wed b1, wed b2);
};
/*��������� ������ �������*/
void generate_database(int number, string path = "database.csv");// ���������� ������ ���� ������
void menu();// ������� ����
