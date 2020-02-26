#pragma once
#ifndef COMPLEX_H_
#define COMPLEX_H_

class Clock
{
public:
	void setTime(int newH, int newM, int newS);
	void showTime() const;
	// Clock() = default;
	Clock(int newH, int newM, int newS);
	Clock & operator ++ ();// ǰ������
	Clock operator ++ (int); // �������� intֻ����������ǰ�úͺ���
	~Clock();
private:
	int hour, minute, second;
};


#endif // !COMPLEX_H_