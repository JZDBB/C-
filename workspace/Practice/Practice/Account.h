#pragma once
#include<string>
#include"Accumulator.h"
class Account{
public:
	~Account();
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;
	// �麯�����������������
	virtual void deposit(const Date& date, double amount, const std::string &desc);
	virtual void withdraw(const Date& date, double amount, const std::string &desc); //ȡ���ֽ�
	virtual void settle(const Date &date);

private:
	std::string id;
	double balance;
	static double total;

protected: // ������������ʵ���
	Account(const Date &date, const std::string &id);
	void record(const Date &date, double amount, const std::string &desc);
	void error(const std::string &msg)const;
};


// �����
class SavingsAccount: public Account{
public:
	SavingsAccount(const Date& date, const string &id, double rate);
	~SavingsAccount();
	void deposit(const Date& date, double amount, const std::string &desc); //�����ֽ�
	void withdraw(const Date& date, double amount, const std::string &desc); //ȡ���ֽ�
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(const Date &date);
	void show() const;

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
	void deposit(const Date &date, double amount, const std::string &desc); //�����ֽ�
	void withdraw(const Date &date, double amount, const std::string &desc); //ȡ���ֽ�
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(const Date &date);
	void show() const;

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
