#include "7.6.h"


Account::pst Account::come = 11; //��̬��Ա�ĸ�ֵ  ��ȫ�ֱ����Ķ����ʼ��һ����ֻ�������������������˵�������ĸ��࣬��̬����������ʹ�����е�pst��Ҫʹ��������������ƶ���Account��
double Account::interestRate = initRate(); //����initRate����Ҫʹ�������������˵�������ĸ�������Ϊǰ���interestRate�Ѿ�ָ����Account���ˡ�
//��Account���к���һ����rate���������ⶨ����Ҫ�����������˵������Account�࣬���Ǻ�������б�����ʹ�õ��������ͺͱ�������Ҫ�����������˵�������Ǻ����ķ������Ͳ�����������Ȩ��
constexpr int Account::period; //ֵ�������Ѿ������ˣ����ֻ�ǰ�period����������ʹ������Ҫ�����ⲿ���壬���periodҪ�����û���ָ������Ҫ�����ⶨ��

Account::Account() //��̬��Ա�����ڹ��캯����ʼʱ������ �ǳ�����ʱ�����ģ�һֱ�����ڳ�������������У�һ����ֻ��һ��ͬ���ľ�̬��Ա
{
	const int &num = period;
}

void Account::rate( double newRate ) //���ⲿ���徲̬��Ա��������Ҫ�ظ�static������
{
	interestRate = newRate;
}

Account::~Account()
{
}

double Account::initRate()
{
	return 0.0;
}
