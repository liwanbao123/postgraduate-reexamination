#include "RSA.h"
void RSA()
{
	while (1)
	{
		menu();
		ll i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
			key();
			break;
		case 2:
			encryption();
			break;
		case 3:
			decode();
			break;
		case 4:
			exit(0);
		default:
			cout << "�������,����������" << endl;
		}
	}
}
void menu1()
{
	printf("******************************************\n");
	printf("******************************************\n");
	printf("*****     ��ӭ����RSA���ܲ���ϵͳ   ******\n");
	printf("******************************************\n");
	printf("******************************************\n");
}
int main()
{
	menu1();
	RSA();
	return 0;
}
