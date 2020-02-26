#include "Clock.h"
#include<iostream>
using namespace std;

//Clock::Clock() : hour(0), minute(0), second(0){}
Clock::Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS)
{
}


Clock::~Clock()
{
}

void Clock::showTime() const{
	cout << hour << ":" << minute << ":" << second << endl;
}

void Clock::setTime(int newH, int newM, int newS) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
		this->hour = newH;
		this->minute = newM;
		this->second = newS;
	}
	else
	{
		cout << "Time error!" << endl;
	}		
}


Clock & Clock::operator ++ () { // ���ص�ǰ��������ã���һ����ֵ
	second++;
	if (second>=60)
	{
		second -= 60;
		minute++;
		if (minute>=60)
		{
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator ++ (int) {
	Clock old = *this;
	++(*this); // ����ǰ�����㣬ǰ�úͺ�������ͳһ
	return old;
}

// ǰ�úͺ��õ�������Կ���
// ǰ��ʹ�õ��������ֵ����return����                            ����������ֵ
// ������ʹ�õ������һ֮ǰ�ĸ�������ʵ�ϱ�������Ѿ���һ�ˡ�    ����������ֵ
