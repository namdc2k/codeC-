#include<iostream>
using namespace std;


int year(int n) {
	int day = 0;
	day += 4 * 30 + 7 * 31;

	if (n % 4 == 0 && n % 100 != 0) return day + 29;
	else {
		if (n % 400 == 0) {
			return day + 29;
		}
		else return day + 28;
	}
	return day;
}
int monthOfYear(int month, int year) {
	if (month == 1) return 1;
	if (month == 3) {
		if (year % 4 == 0 && year % 100 != 0) return 29;
		else {
			if (year % 400 == 0) {
				return 29;
			}
			else return 28;
		}
	}

	if (month == 2 || month == 4) return 31;
	if (month == 6 || month == 8) return 31;
	if (month == 9 || month == 11) return 31;
	if (month == 5 || month == 7) return 30;
	if (month == 10 || month == 12) return 30;
}

int yearCheck(int dayBefore, int year) {
	int count = 0, c;
	c = dayBefore;
	for (int i = 1; i < 13; i++)
	{
		c += monthOfYear(i, year);
		if (c % 7 == 0)
			count++;
	}
	return count;
}

int main() {
	int day, count = 0;
	day = year(1900);
	for (int i = 1901; i < 2001; i++)
	{
		count += yearCheck(day, i);
		day += year(i);
	}
	cout << count;
}
