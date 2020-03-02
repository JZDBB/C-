#pragma once
#include<string>
#include"Accumulator.h"
#include"date.h"
#include<map>

class Account{
public:
	~Account();
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	virtual void show() const;
	// �麯�����������������
	virtual void deposit(const Date& date, double amount, const std::string &desc) = 0;
	virtual void withdraw(const Date& date, double amount, const std::string &desc) = 0; //ȡ���ֽ�
	virtual void settle(const Date &date) = 0;

private:
	std::string id;
	double balance;
	static double total;

protected: // ������������ʵ���
	Account(const Date &date, const std::string &id);
	void record(const Date &date, double amount, const std::string &desc);
	void error(const std::string &msg)const;
};

class AccountRecord{ // ��Ŀ��¼
public:
	AccountRecord();
	~AccountRecord();

private:
	Date date;
	const Account *account;
	double amount;
	double balance;
	std::string desc;
};


AccountRecord::AccountRecord()
{
}

AccountRecord::~AccountRecord()
{
}


// �����
class SavingsAccount: public Account{
public:
	SavingsAccount(const Date& date, const string &id, double rate);
	~SavingsAccount();
	virtual void deposit(const Date& date, double amount, const std::string &desc); //�����ֽ�
	virtual void withdraw(const Date& date, double amount, const std::string &desc); //ȡ���ֽ�
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	virtual void settle(const Date &date);
	virtual void show() const;

private:
	Accumulator acc;
	double rate;
};


// ���ÿ���
class CreditAccount: public Account{
public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
	~CreditAccount();
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const;
	virtual void deposit(const Date &date, double amount, const std::string &desc); //�����ֽ�
	virtual void withdraw(const Date &date, double amount, const std::string &desc); //ȡ���ֽ�
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	virtual void settle(const Date &date);
	virtual void show() const;

private:
	Accumulator acc;
	double credit; // ���ö��
	double rate; //������
	double fee; // ���

	double getDebt() const {	//���Ƿ���
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
};
