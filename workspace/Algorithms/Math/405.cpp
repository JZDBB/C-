#include"Math.h"

// 405. ����ת��Ϊʮ��������
string toHex(int num) {
	string hexs = "0123456789abcdef";
	string res = "";
	if (num == 0){
		return "0";
	}
	//32λ���ɣ����������ʮ�����Ƶĳ��Ȳ�����8
	while (res.size() < 8 && num){
		res = hexs[num & 0xf] + res;
		num >>= 4;
	}
	return res;
}
