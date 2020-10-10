#include "Header.h"// ����������� ������������� �����
/*���������� ���������� ���������*/
bool operator== (wed w1, wed w2)
{
    return w1.male_name == w2.male_name and w1.marrige_date == w2.marrige_date;
}
bool operator!= (wed w1, wed w2)
{
    return (w1 != w2);
}
bool operator<= (wed w1, wed w2)
{
    return ((w1 < w2) || (w1 == w2));
}
bool operator>= (wed w1, wed w2)
{
    return ((w1 > w2) || (w1 == w2));
}
bool operator< (wed w1, wed w2)
{
    return((w1.male_name < w2.male_name) && (stoi(w1.marrige_date) < stoi(w2.marrige_date) || \
        (w1.marrige_date == w2.marrige_date)));// stoi ��������� string � integer
}
bool operator> (wed w1, wed w2)
{
    return((w1.male_name > w2.male_name) && (stoi(w1.marrige_date) > stoi(w2.marrige_date) || \
        (w1.marrige_date == w2.marrige_date)));// stoi ��������� string � integer
}
/*������� ��������� ������ ������� ����*/
void female_names_generator(int number)
{
    /*��������� ������� ����*/
    ofstream name_base("female_name_base.csv");// ������� � ������� �������� ���
    ifstream name_1("Female_names_1.txt");// ��������� ���� � �������� �������
    ifstream name_2("Female_names_2.txt");// ��������� ���� � �������� ���������
    ifstream name_3("Female_names_3.txt");// ��������� ���� � �������� ����������
    /*�������� ������� �������� (�����, ������� � ��������) ��� ����������� �� ����������*/
    /*����� � ������ ����� �� 100 ����, 100 ������� � 100 �������*/
    vector<string> names_1(0);// ������ �� ����� �������
    vector<string> names_2(0);// ������ �� ����� ���������
    vector<string> names_3(0);// ������ �� ����� ����������
    /*��������� �������*/
    for (int i = 0; i < 100; i++)
    {
        string buf;
        name_1 >> buf;
        names_1.push_back(buf);
        name_2 >> buf;
        names_2.push_back(buf);
        name_3 >> buf;
        names_3.push_back(buf);
    }
    /*� ����� �������� �� ���������� �������� ���������� ��� ����������� number*/
    for (int i = 0; i < number; i++)
    {
        name_base << names_1[rand() % 100] << ' ' << names_2[rand() % 100] \
            << ' ' << names_3[rand() % 100] << '\n';
    }
    /*���������� �����*/
    name_base.close();
    name_1.close();
    name_2.close();
    name_3.close();
}
/*���������� ���� ������*/
void generate_database(int number, string path)
{
    /*��������� � ����� ���������� ������ ������� ����� � ���� ������,
    ����������� ���������� �����, ��� � ��� ������� ����*/
    ofstream database(path);// ���� ���� ������
    ifstream name_1("Male_names_1.txt");// ��������� ���� � �������� �������
    ifstream name_2("Male_names_2.txt");// ��������� ���� � �������� ���������
    ifstream name_3("Male_names_3.txt");// ��������� ���� � �������� ����������
    ifstream female_names("female_name_base.csv");// ������� ������� � ������� �������� �������
    /*�������� ������� �������� (�����, ������� � ��������) ��� ����������� �� ����������*/
    /*����� � ������ ����� �� 100 ����, 100 ������� � 100 �������*/
    vector<string> names_1(0);// ������ �� ����� �������
    vector<string> names_2(0);// ������ �� ����� ���������
    vector<string> names_3(0);// ������ �� ����� ����������
    /*��������� �������*/
    for (int i = 0; i < 100; i++)
    {
        string buf;
        name_1 >> buf;
        names_1.push_back(buf);
        name_2 >> buf;
        names_2.push_back(buf);
        name_3 >> buf;
        names_3.push_back(buf);
    }
    /*�������� ��������� ���� ���������������*/
    int month = 1 + (rand() % 12);
    int days = 31;
    int year = 2006 + (rand() % 13);
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 2) //������� ���� �� ������������, ����� ������� � ������� 28 ����
    {
        if (year % 4 != 0)
            days = 28;
        else if (year % 100 != 0)
            days = 29;
        else if (year % 400 == 0)
            days = 29;
        else days = 28;
    }
    /*��������� � ���������� ������������� ������ (��� ������, ��� �������� ������,
    ��� �������, ��� �������� �������, ���� �������������)*/

    for (int i = 0; i < number; i++)
    {
        string buf;// ���� ����� ���������� ��������� ��� ������������ ������ ��� �������
        getline(female_names, buf);// ������� ������ ������� ���
        database << names_1[rand() % 100] + ' ' + names_2[rand() % 100] \
            + ' ' + names_3[rand() % 100] + ';' + to_string(1970 + rand() % 30) + ';' + buf + ';' \
            + to_string(1970 + rand() % 30) + ';' + to_string(1 + rand() % days) + '.' + \
            to_string(month) + '.' + to_string(year) + '\n';
    }
    /*���������� �����*/
    database.close();
    name_1.close();
    name_2.close();
    name_3.close();
    female_names.close();
}
/*������� ���������� �������� ���� ������ � ������*/
vector<wed> make_vector(string path)
{
    string buf;
    ifstream data(path);// �������� ���� � ����� ������
    vector<wed> record(0);// ������� ������ ������
    while (getline(data, buf, ';'))// ��������� �� ����� �� ����������� ���� �� ���������� ���� 
    {
        int groom_birth, bride_birth;
        string groom_name, bride_name, wed_date;
        groom_name = buf;
        getline(data, buf, ';');
        groom_birth = stoi(buf);// ��������� int � string
        getline(data, buf, ';');
        bride_name = buf;
        getline(data, buf, ';');
        bride_birth = stoi(buf);// ��������� int � string
        getline(data, buf);
        wed_date = buf;
        record.push_back(wed(groom_name, groom_birth, bride_name, bride_birth, wed_date));
    }
    data.close();// �������� ����
    return record;
}
/*������� ��������� �������*/
void selection_sorting(vector<wed>& num)
{
    int size = num.size();
    wed temp;// ������� ���������� ��� 
    int min; // ������ ������������ ��������
    for (int i = 0; i < size; i++)
    {
        min = i; //������ �������� �������� ��������� �� �����������
        /*����� ������������ �������� ������� � i + 1 - ��� �����*/
        for (int j = i + 1; j < size; j++)  // ����� �� ���� ���������, ������� � i + 1 - ���
        {
            if (num[j] < num[min]) // ���� ������� ������� ������ ������������
                min = j;// ���������� ��� ������ � min
        }
        temp = num[i];// ������ ������� i-�� ������� � ����������� ����� ������� ����������
        num[i] = num[min];
        num[min] = temp;
    }
}
/*������� ������-���������*/
void shaker_sorting(vector<wed>& num)
{
    int left = 0;// ����� ������� ���������� ����� �������
    int count = num.size();
    int right = count - 1;// ������ ������� ���������� ����� �������
    /*���� � ����� ������ ������ � ����� ���� ������ ������� �� ���������� � ���� ���� �����������*/
    while ((left < right))
    {
        for (int i = left; i < right; i++)// ������ ����� �� �����
        {
            if (num[i] > num[i + 1])// ���� ��������� ������ ��������, �� ������ �������
            {
                wed t = num[i];// ������� �������� ����������
                num[i] = num[i + 1];
                num[i + 1] = t;
            }
        }
        right--;// �������� ������ ������� �� ���������� �������
        for (int i = right; i > left; i--)// ������ ������ ������
        {
            if (num[i - 1] > num[i]) // ���� ���������� ������ ��������, �� ������ �������
            {
                wed t = num[i];// ������� �������� ����������
                num[i] = num[i - 1];
                num[i - 1] = t;
            }
        }
        left++;// �������� ����� ������� �� ��������� �������
    }
}
/*���� ��������� ���� ������ ������ ��������*/
void sorting(void(*function)(vector<wed>&), string path_old, string path_new)
{
    vector<wed> a = make_vector(path_old);//���������� ���� ������ � ������
    function(a);// �������� ������
    ofstream data;
    data.open(path_new);// ��������� ���� ������ ��� ����������
    for (int i = 0; i < a.size(); i++)
    {
        data << a[i].male_name + ";" + to_string(a[i].male_year) + ";" + a[i].female_name \
            + ";" + to_string(a[i].female_year) + ";" + a[i].marrige_date + "\n";
    }
    data.close();// ��������� ����
}
/*���������� ��� ��������������� ���� ������*/
void time_of_sorting_unsorted_data(int n, void (*function)(vector<wed>&))
{
    unsigned int start_time = clock();// �������� ����� ���������� ����������
    sorting(function, "database.csv", "database(sorted).csv"); //���������� ������
    unsigned int end_time = clock();
    cout << " ����� ���������� " << n << " ���������: " << (end_time - start_time) * 1.0 / 1000 \
        << ' c' << endl;
}
/*���������� ����������������� ������*/
void time_of_sorting_already_sorted_data(int n, void (*function)(vector<wed>&))
{
    unsigned int start_time = clock();// �������� ����� ���������� ����������
    sorting(function, "database(sorted).csv", "database.csv"); //���������� ������
    unsigned int end_time = clock();
    cout << " ����� ���������� " << n << " ���������: " << (end_time - start_time) * 1.0 / 1000 \
        << ' c' << endl;
}
void menu()
{
    /*������������ ������ ������� ��������� ������������*/
    int b = 0;
    cout << "Press 1 to sort 100 items" << endl;
    cout << "Press 2 to sort 200 items" << endl;
    cout << "Press 3 to sort 400 items" << endl;
    cout << "Press 4 to sort 600 items" << endl;
    cout << "Press 5 to sort 800 items" << endl;
    cout << "Press 6 to sort 1000 items" << endl;
    cout << "Input the number: ";
    while (b < 1 || b > 6) // ���� �� ����� ���������� �������� ��������� ����
    {
        cin >> b;
        if ((b < 1) || (b > 6))
        {
            cout << "WRONG INPUT!" << endl;
            cout << "Enter a number from 1 to 6" << endl;
            cin.clear();// ������� ����� �����, ���� ��� ������ ������ ����, ��������� �� int 
            /*���������� ����������� ������, ����� ����� ����� �� ����� ������ � ������� �� �����*/
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    switch (b)
    {
    case 1:
    {
        
        female_names_generator(100);
        generate_database(100);
        cout << "���������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_unsorted_data(100, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_unsorted_data(100, selection_sorting);
        cout << "������� �������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_already_sorted_data(100, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_already_sorted_data(100, selection_sorting);
        break;
    }
    case 2:
    {
        female_names_generator(200);
        generate_database(200);
        cout << "���������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_unsorted_data(200, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_unsorted_data(200, selection_sorting);
        cout << "������� �������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_already_sorted_data(200, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_already_sorted_data(200, selection_sorting);
        break;
    }
    case 3:
    {
        female_names_generator(400);
        generate_database(400);
        cout << "���������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_unsorted_data(400, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_unsorted_data(400, selection_sorting);
        cout << "������� �������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_already_sorted_data(400, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_already_sorted_data(400, selection_sorting);
        break;
    }
    case 4:
    {
        
        female_names_generator(600);
        generate_database(600);
        cout << "���������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_unsorted_data(600, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_unsorted_data(600, selection_sorting);
        cout << "������� �������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_already_sorted_data(600, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_already_sorted_data(600, selection_sorting);
        break;
    }
    case 5:
    {
        female_names_generator(800);
        generate_database(800);
        cout << "���������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_unsorted_data(800, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_unsorted_data(800, selection_sorting);
        cout << "������� �������������� ������: " << endl;
        cout << "Shaker_sort:";
        time_of_sorting_already_sorted_data(800, shaker_sorting);
        cout << "Selection_sort:";
        time_of_sorting_already_sorted_data(800, selection_sorting);
        break;
    }
    case 6:
    {
        for (int i = 0; i < 5; i++) {
            female_names_generator(1000);
            generate_database(1000);
            cout << "���������������� ������: " << endl;
            cout << "Shaker_sort:";
            time_of_sorting_unsorted_data(1000, shaker_sorting);
            cout << "Selection_sort:";
            time_of_sorting_unsorted_data(1000, selection_sorting);
            cout << "������� �������������� ������:" << endl;
            cout << "Shaker_sort:";
            time_of_sorting_already_sorted_data(1000, shaker_sorting);
            cout << "Selection_sort:";
            time_of_sorting_already_sorted_data(1000, selection_sorting);
        }
        break;
    }
    }
}