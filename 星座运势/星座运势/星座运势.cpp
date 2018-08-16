// 星座运势.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>

#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
	int flag;

public:
	Date(int a, int b, int c) { year = a; month = b; day = c; }
	int runian() {
		if (year % 4 == 0 && year % 100 != 0)
		{
			//cout << "是闰年" << endl;
			flag = 1;
			return 1;
		}
		else if (year % 400 == 0)
		{
			//cout << "是闰年" << endl;
			flag = 1;
			return 1;
		}
		else {
			//cout << "不是闰年" << endl;
			flag = 0;
			return 0;
		}
	}
	int date() {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int i, x = 0;
		for (i = 0; i<month - 1; i++)
			x += a[i];
		x = x + day;
		if (month>2)
			if (flag)
				x++;
		return x;
	}

};
//判断是否闰年
int runnian(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return 1;
	}
	else if (year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int bornyear, bornmonth, bornday;
	cout << "请输入您的出生日期" << endl;
	cin >> bornyear >> bornmonth >> bornday;
	Date j(bornyear, bornmonth, bornday);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	//printf("%4d/%02d/%02d ", sys.wYear, sys.wMonth, sys.wDay);
	cout << "今年是  " << sys.wYear << "年  " << sys.wMonth << "月  " << sys.wDay << "日" << endl;
	Date k(sys.wYear, sys.wMonth, sys.wDay);
	Date l(sys.wYear, bornmonth, bornday);
	cout << "您今年 " << sys.wYear - bornyear << "岁" << endl;
	int livingdays, i;//已活天数

	if (runnian(bornyear))
		livingdays = 366 - j.date();
	else livingdays = 365 - j.date();
	for (i = sys.wYear; i > bornyear + 1; i--)
	{
		if (runnian(i))
			livingdays = livingdays + 366;
		else livingdays = livingdays + 365;
	}
	cout << "您已经出生了" << livingdays + k.date() << "天" << endl;
	int gap;
	if(l.date()> k.date()|| l.date()==k.date())
	{
		gap = l.date() - k.date();
		cout << "距离下一个生日还有" << gap << "天" << endl;
	}
	else
	{
		if (runnian(sys.wYear))
			gap = 366 - k.date() + j.date();
		else gap = 365 - k.date() + j.date();
		cout<< "距离下一个生日还有" << gap << "天" << endl;
	}


	
	if (j.runian())
		cout << "是闰年" << endl;
	else cout << "不是闰年" << endl;
		cout << "这天是该年第" << j.date() << "天" << endl;
	if (bornmonth == 1 && bornday >= 20)
		cout << "这天是水瓶座" << endl;
	else if (bornmonth == 2 && bornday <= 18)
		cout << "这天是水瓶座" << endl;
	else if (bornmonth == 2 && bornday > 18)
		cout << "这天是双鱼座" << endl;
	else if (bornmonth == 3 && bornday <= 20)
		cout << "这天是双鱼座" << endl;
	else if (bornmonth == 3 && bornday > 20)
		cout << "这天是白羊座" << endl;
	else if (bornmonth == 4 && bornday <= 19)
		cout << "这天是白羊座" << endl;
	else if (bornmonth == 4 && bornday >= 20)
		cout << "这天是金牛座" << endl;
	else if (bornmonth == 5 && bornday <= 20)
		cout << "这天是金牛座" << endl;
	else if (bornmonth == 5 && bornday >= 21)
		cout << "这天是双子座" << endl;
	else if (bornmonth == 6 && bornday <= 21)
		cout << "这天是双子座" << endl;
	else if (bornmonth == 6 && bornday >= 22)
		cout << "这天是巨蟹座" << endl;
	else if (bornmonth == 7 && bornday <= 22)
		cout << "这天是巨蟹座" << endl;
	else if (bornmonth == 7 && bornday >= 23)
		cout << "这天是狮子座" << endl;
	else if (bornmonth == 8 && bornday <= 22)
		cout << "这天是狮子座" << endl;
	else if (bornmonth == 8 && bornday >= 23)
		cout << "这天是处女座" << endl;
	else if (bornmonth == 9 && bornday <= 22)
		cout << "这天是处女座" << endl;
	else if (bornmonth == 9 && bornday >= 23)
		cout << "这天是天秤座" << endl;
	else if (bornmonth == 10 && bornday <= 23)
		cout << "这天是天秤座" << endl;
	else if (bornmonth == 10 && bornday >= 24)
		cout << "这天是天蝎座" << endl;
	else if (bornmonth == 11 && bornday <= 22)
		cout << "这天是天蝎座" << endl;
	else if (bornmonth == 11 && bornday >= 23)
		cout << "这天是射手座" << endl;
	else if (bornmonth == 12 && bornday <= 21)
		cout << "这天是射手座" << endl;
	else if (bornmonth == 12 && bornday >= 22)
		cout << "这天是摩羯座" << endl;
	else if (bornmonth == 1 && bornday <= 19)
		cout << "这天是摩羯座" << endl;

	
	return 0;
}