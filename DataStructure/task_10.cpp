#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void save()
{
	double fare;  //票价
	char flightNumber[13];  //航班号
	string departureTime;  //起飞时间
	string fallTime; //降落时间
        string destination; //抵达城市
        double discount; //折扣
        int total;  //座位总数
	ofstream outfile("FlightInfo.dat" , ios::app); //定义文件输入流对象，以输出方式打开磁盘文件
	if(!outfile)
	{
		cerr << "打开文件FlightInfo.dat失败" << endl;
		exit(1);
	}
	cout << "请输入航班号、票价、起飞时间、降落时间、抵达城市、折扣、座位总数 (空格分隔)"<<endl;
	cin>>flightNumber>>fare>>departureTime>>fallTime>>destination>>discount>>total;
	outfile<< flightNumber << "\t" <<fare<< "\t" << departureTime << "\t" << fallTime<< "\t" << destination << "\t" <<discount << "\t" << total  <<endl;
	outfile.close();
}

void read()
{
	double fare;  //票价
	char flightNumber[13];  //航班号
	string departureTime;  //起飞时间
	string fallTime; //降落时间
        string destination; //抵达城市
        double discount; //折扣
        int total;  //座位总数
        ifstream infile("FlightInfo.dat" , ios::in);
        if(!infile){
		cerr << "打开文件FlightInfo.dat失败" << endl;
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
	srand(time(0));  //初始化随机数种子
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
