#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void save()
{
	double fare;  //Ʊ��
	char flightNumber[13];  //�����
	string departureTime;  //���ʱ��
	string fallTime; //����ʱ��
        string destination; //�ִ����
        double discount; //�ۿ�
        int total;  //��λ����
	ofstream outfile("FlightInfo.dat" , ios::app); //�����ļ������������������ʽ�򿪴����ļ�
	if(!outfile)
	{
		cerr << "���ļ�FlightInfo.datʧ��" << endl;
		exit(1);
	}
	cout << "�����뺽��š�Ʊ�ۡ����ʱ�䡢����ʱ�䡢�ִ���С��ۿۡ���λ���� (�ո�ָ�)"<<endl;
	cin>>flightNumber>>fare>>departureTime>>fallTime>>destination>>discount>>total;
	outfile<< flightNumber << "\t" <<fare<< "\t" << departureTime << "\t" << fallTime<< "\t" << destination << "\t" <<discount << "\t" << total  <<endl;
	outfile.close();
}

void read()
{
	double fare;  //Ʊ��
	char flightNumber[13];  //�����
	string departureTime;  //���ʱ��
	string fallTime; //����ʱ��
        string destination; //�ִ����
        double discount; //�ۿ�
        int total;  //��λ����
        ifstream infile("FlightInfo.dat" , ios::in);
        if(!infile){
		cerr << "���ļ�FlightInfo.datʧ��" << endl;
		exit(1);
        }

        while(infile >> flightNumber >> fare >> departureTime >> fallTime >> destination >> discount >> total){
        	cout << flightNumber << "\t" <<fare<< "\t" << departureTime << "\t" << fallTime<< "\t" << destination << "\t" <<discount << "\t" << total  <<endl;
        }
        infile.close();
}

char* demo()
{
	char* str = new char[5];
	int i = 0;
	while(i > 0)
	{
		//cin >> str[i];
		str[i] = 'a';
		i++;
	}
	return str;
}

string getNumber()
{
	srand(time(0));  //��ʼ�����������
	string str = "FFF000000";
	for(int i = 3 ; i < 9 ; i++)
	{
		str[i] = rand() % 10 + '0';
	}
	return str;
}

int main()
{
	//save();
	//read();
	//string str1 = "1" , str2 = "1";
	//if(str1 == str2)
	//{
	//	cout << "true" ;
	//}
	//char* str = demo();
	//cout << str;
	cout << getNumber();
	return 0;
}
