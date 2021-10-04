#include<iostream>
#include<time.h>
#include<Windows.h>
#include<cstdlib>
using namespace std;
char pan[21][60];
char Pan[21][60]={  "   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19",
					"1  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"2  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"3  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"4  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"5  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"6  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"7  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"8  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"9  |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"10 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"11 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"12 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"13 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"14 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"15 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"16 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"17 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"18 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|",
					"19 |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|"};
					
void clean();
void show();
void unit();
bool begin();
bool end(int n);
int iswin();
void Bgo();
void Wgo();

void clean()
{
	system("cls");
	show();
}

void show()
{
	system("cls");
	for(int i=0;i<21;++i)
	{
		for(int j=0;j<60;++j)
		{
			cout<<pan[i][j];
		}
		cout<<endl;
	}
}

void unit()
{
	for(int i=0;i<21;++i)
	{
		for(int j=0;j<60;++j)
		{
			pan[i][j]=Pan[i][j];
		}
	}
}

bool begin()
{
	
	return true;
}

int iswin()
{
	for(int i=1;i<20;++i)
	{
		for(int j=3;j<60;j+=3)
		{
			if(pan[i][j]!='|')
			{
				char qi=pan[i][j];
				if((qi==pan[i+1][j]&&qi==pan[i+2][j]&&qi==pan[i+3][j]&&qi==pan[i+4][j]))
				{
					if(qi==1)
						return 1;
					else
						return 2;					
				}
				else if((qi==pan[i][j+3]&&qi==pan[i][j+6]&&qi==pan[i][j+9]&&qi==pan[i][j+12]))
				{
					if(qi==1)
						return 1;
					else
						return 2;		
				}
				else if((qi==pan[i+1][j+3]&&qi==pan[i+2][j+6]&&qi==pan[i+3][j+9]&&qi==pan[i+4][j+12]))
				{
					if(qi==1)
						return 1;
					else
						return 2;		
				}
			}
		}
	}
	return 0;
}

bool end(int winner)
{
	char key;
	for(int i=0;i<5;i++)
	{
		system("cls");
		Sleep(1000);
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                     ****************************************"<<endl;
		cout<<"                     *                                      *"<<endl;
		cout<<"                     *               ʤ������               *"<<endl;
		cout<<"                     *               ��"; 
		if(winner==1)
			cout<<"����";
		else
			cout<<"����";
		cout<<"��               *"<<endl;
		cout<<"                     *                                      *"<<endl;
		cout<<"                     ****************************************"<<endl;
		Sleep(1000);
	}
		cout<<"                                    �Ƿ������"<<endl; 
		cout<<"                                     ��Y/N��"<<endl; 
		cout<<"                                        "; 
		getchar();
		cin>>key;
		if(key=='y'||key=='Y')
			return true;
		else
			return false;
}

int error(int x,int y)
{
	if(pan[x][3*y]=='|')
		return 1;
	else
		return 0;
}

void Wgo()
{
	cout<<"��������壺"<<endl<<"������2 3��"<<endl;
	int x,y;
	cin>>x>>y;
	int fa=error(x,y);
	if(fa==1)
		pan[x][3*y]=1;
	else
	{
		system("cls");
		show();
		cout<<"��λ���Ѿ������ӣ�"<<endl;
		Wgo(); 
	}
}

void Bgo()
{
	cout<<"��������壺"<<endl<<"������2 3��"<<endl;
	int x,y;
	cin>>x>>y;
	int fa=error(x,y);
	if(fa==1)
		pan[x][3*y]=2;
	else
	{
		system("cls");
		show();
		cout<<"��λ���Ѿ������ӣ�"<<endl;
		Bgo(); 
	}
}

int main()
{
	bool start=begin();
	int winner;
	while(start)
	{
		unit();
		system("cls");
		show();
		while(1){
			Bgo();
			if(iswin()!=0)
			{
				winner=iswin();
				break;
			}
			show();
			Wgo();
			if(iswin()!=0)
			{
				winner=iswin();
				break;
			}
			show();
		}
		start=end(winner);
	}
	return 0;
}
