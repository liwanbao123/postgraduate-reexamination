#define  _CRT_SECURE_NO_WARNINGS 1
#include "RSA.h"
void menu()
{
	printf("------------------------------------------\n");
	printf("*****        ��ѡ�����蹦��          *****\n");
	printf("*****          1.����Կ��            *****\n");
	printf("*****          2.����                *****\n");
	printf("*****          3.����                *****\n");
	printf("*****          4.�˳�                *****\n");
	printf("------------------------------------------\n");
}
ll primeNum(ll num)   //�ж�����
{
	if (num == 1 || num == 0)
	{
		return 0;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			// ������������0
			return 0;
		}
	}
	return 1; //����������1
}
//�ж��������Ƿ���
ll coprime(ll a, ll b)  //�жϻ���
{
	ll t;
	if (a < b)
	{
		t = a; 
		a = b; 
		b = t;
	}
	while (a % b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	//����ֵΪ1����a��b����
	return b;
}
//��������
ll candp(ll b, ll p, ll k) //b--���Ļ�����   p--ָ��(e/d)    k--ģ��
{
	if (p == 1)
	{
		return b % k;
	}
	if (p == 2)
	{
		return b * b % k;
	}
	if (p % 2 == 0)
	{
		ll sum = candp(b, p / 2, k);
		return sum * sum % k;
	}
	if (p % 2 == 1)
	{
		ll sun = candp(b, p / 2, k);
		return sun * sun * b % k;
	}
}
//������Կ
ll key()
{
	ll p, q, t, n, e, d;
	cout << "�������������� p,q: " << endl;    //������������q,p
	cin >> p >> q;
	if (primeNum(p)==0||primeNum(q)==0)
	{
		cout << "�����p��q��������" << endl;
		return 0;
	}
	n = p * q;
 
	//tΪn��ŷ������
	t = (p - 1) * (q - 1);
 
	cout << "��������Կe: " << endl;
	cin >> e;
	d = 1;
	//��e�ĳ˷���
	while (((e * d) % t) != 1) 
		d++;
 
	cout << "n = p * q = " << n << endl;
	cout << "t = (p - 1) * (q - 1) = " << t << endl;
	cout << ("��Կ(e,n)Ϊ:(") << e << "," << n << ")" << endl;
	cout << ("˽Կ(d,n)Ϊ:(") << d << "," << n << ")" << endl;
	return 0;
}
//����
ll encryption()
{
	ll n, e, x, y;
	cout << "�����빫Կ(e��n)" << endl;
	cin >> e >> n;
	cout << "����������: (������С��" << n << ")" << endl;  //��������
	cin >> x;
 
	y = candp(x, e, n);
	cout << "����Ϊ:" << y << endl;
	return 0;
}
//����
ll decode()
{
	ll n, d, x, y;
	cout << "������˽Կ(d��n)" << endl;
	cin >> d >> n;
	cout << "����������: ";  //��������
	cin >> y;
 
	x = candp(y, d, n);
	cout << "����Ϊ:" << x << endl;
	return 0;
}
