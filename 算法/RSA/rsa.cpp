#define  _CRT_SECURE_NO_WARNINGS 1
#include "RSA.h"
void menu()
{
	printf("------------------------------------------\n");
	printf("*****        请选择所需功能          *****\n");
	printf("*****          1.生成钥匙            *****\n");
	printf("*****          2.加密                *****\n");
	printf("*****          3.解密                *****\n");
	printf("*****          4.退出                *****\n");
	printf("------------------------------------------\n");
}
ll primeNum(ll num)   //判断素数
{
	if (num == 1 || num == 0)
	{
		return 0;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			// 不是素数返回0
			return 0;
		}
	}
	return 1; //是素数返回1
}
//判断两个数是否互素
ll coprime(ll a, ll b)  //判断互质
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
	//返回值为1，则a，b互素
	return b;
}
//计算密文
ll candp(ll b, ll p, ll k) //b--明文或密文   p--指数(e/d)    k--模数
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
//生成密钥
ll key()
{
	ll p, q, t, n, e, d;
	cout << "请输入两个素数 p,q: " << endl;    //输入两个素数q,p
	cin >> p >> q;
	if (primeNum(p)==0||primeNum(q)==0)
	{
		cout << "输入的p或q不是素数" << endl;
		return 0;
	}
	n = p * q;
 
	//t为n的欧拉函数
	t = (p - 1) * (q - 1);
 
	cout << "请输入密钥e: " << endl;
	cin >> e;
	d = 1;
	//求e的乘法逆
	while (((e * d) % t) != 1) 
		d++;
 
	cout << "n = p * q = " << n << endl;
	cout << "t = (p - 1) * (q - 1) = " << t << endl;
	cout << ("公钥(e,n)为:(") << e << "," << n << ")" << endl;
	cout << ("私钥(d,n)为:(") << d << "," << n << ")" << endl;
	return 0;
}
//加密
ll encryption()
{
	ll n, e, x, y;
	cout << "请输入公钥(e，n)" << endl;
	cin >> e >> n;
	cout << "请输入明文: (明文需小于" << n << ")" << endl;  //计算密文
	cin >> x;
 
	y = candp(x, e, n);
	cout << "密文为:" << y << endl;
	return 0;
}
//解密
ll decode()
{
	ll n, d, x, y;
	cout << "请输入私钥(d，n)" << endl;
	cin >> d >> n;
	cout << "请输入密文: ";  //计算密文
	cin >> y;
 
	x = candp(y, d, n);
	cout << "明文为:" << x << endl;
	return 0;
}
