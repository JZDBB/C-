#include "CDROM.h"
#include<iostream>
using namespace std;

CDROM::CDROM(CD_CONNECT c, CD_INSTALL i, int cv) { con = c; install = i; cdvolume = cv; cout << "������һ��CDROM\n"; }
CDROM::CDROM() {};
CDROM::~CDROM() { cout << "������һ��CDROM\n"; };

//���ݽӿ� ��ΪɶҪ��const��
CD_CONNECT CDROM::GetCD_CONNECT()const { return con; };
CD_INSTALL CDROM::GetCD_INSTALL()const { return install; };
int CDROM::Getcdvolume()const { return cdvolume; }

void CDROM::setCD_CONNECT(CD_CONNECT c) { con = c; }
void CDROM::setCD_INSTALL(CD_INSTALL i) { install = i; }
void CDROM::setcdvolume(int cv) { cdvolume = cv; }

void CDROM::run() { cout << "CDROM begin!\n"; };
void CDROM::stop() { cout << "CDROM stop!\n"; };
