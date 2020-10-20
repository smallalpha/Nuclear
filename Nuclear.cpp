/*
����������������120Kg/s��һ��·ѹ����15MPa����ȴ���������²�Ϊ30�棻
����·�౥��ѹ��5MPa������·��ˮ�¶�230�棻
�۹�����3.28 �� 10-5 ������������Ϊ��������1%��
Ҫ�󣺸���������������ƵĴ�����������ܷ�ʽ������ֱ����
*/
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define C 1.09
#define Dg 120
#define P1 15
#define P2 5
#define DetT 30
#define T_o 305.50
#define T_i 275.50
#define T2 230
#define T1 263.91121
#define Emission_rate 0.01//������
#define Rf 0.0000328//�۹�����
#define D1 17.5 //���ȹ��⾶��mm
#define D2 15.5//���ȹ��ھ���mm
#define M 4875//��ȴ���ܵ�����ȴ��������������Kg/s
#define D 269 //��ȴ���ܵ��ھ���mm
#define Pr 0.8845719
#define Pi 3.1415629
double n = 8.61659802338818E-05;
double i_f = 1155.1377, i_s = 2794.1767,i_i= 990.636209939523;//��ֵ
double r = i_s - i_f;
double Q, Re,det_min,det_max,det_ln,Nu,a1,Rw,k1,k2,a2,q,temp,F;
int main()
{
	int i = 0;
	time_t tmpcal_ptr;
	struct tm* tmp_ptr = NULL;
	time(&tmpcal_ptr);
	tmp_ptr = gmtime(&tmpcal_ptr);
	tmp_ptr = localtime(&tmpcal_ptr);
	F = 0;
	 Re = 4 / Pi * (M / (n * D * 10E-03));
	 det_min = T_i - T1; det_max = T_o - T2;
	 det_ln = (det_max - det_min) / log(det_max / det_min);
	 Q = Dg * r + (1 + Emission_rate) * Dg * (i_f - i_i);
	 Nu = 0.023 * pow(Re, 0.8) * pow(Pr, 0.3);
	 a1 = Nu * 0.550753838002047 / D;
	 Rw = D1 / (2 * 60.3) * log(D1 / D2);
	 k1 = 90; k2 = 100;

	 printf("%lf\n", (k2 - k1) / k2);
	 printf("%d", (k2 - k1) / k2<0.05);
	 while ((k2 - k1) / k2 >0.05)
	 {
		 i++;
		 printf("��%d�μ���\n",i);
		 printf("��ʱk1=%lf,k2=%lf\n", k1, k2);
		 k2 = k1;
		 q = k2 * det_ln;
		 a2 = 0.557 * pow((P2 + 0.1) * 10E+06, 0.15) * pow(q, 0.7);
		 temp = D2 / D1 * (1 / a1) + Rw + 1 / a2;
		 temp = temp + Rf;
		 k1 = 1 / temp;

	 }
	 printf("����ϵ��������\n");
	 printf("��ʱk1=%lf,k2=%lf\n", k1, k2);
	 F = Q / (k1 * det_ln);
	 printf("������ԣ��������£��������Ϊ%lf\n", F);
	 F = C * F;
	 printf("����ԣ��������£��������Ϊ%lf\n",F);
	 printf("�������\n");
	 printf("������:%d.%d.%d ", (1900 + tmp_ptr->tm_year), (1 + tmp_ptr->tm_mon), tmp_ptr->tm_mday);
	 printf("%d:%d:%d\n", tmp_ptr->tm_hour, tmp_ptr->tm_min, tmp_ptr->tm_sec);
	 printf("���������Ұݸ���������\n");
	 system("pause");

}

