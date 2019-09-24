#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>


using namespace std;


int main()
{
		//system("chcp 1251>nul");
		setlocale(LC_ALL, "Russian");
		srand(time(NULL));

		// ������������ �������� (clc)
		int U_snos_clc;										// ���� �����
		int W_clc;										// ������� ��������
		int U_clc;										// �������� �����
		float sigma_clc;									// ����������� �����

		// ��������� �������� (std)
		int U_snos_std;										// ���� �����
		int W_std;										// ������� ��������
		int U_std;										// �������� �����
		float sigma_std;									// ����������� �����
		
		float V_ist;											// �������� �������� (400...900 ��/�)
		float Usl_kurs;										// �������� ����� (0...360 ����)
		float S_kontrol_step;									//  ����� ������������ ����� (50...300 ��)
		float FUPU;											// ����������� �������� ������� ���� (0...360 ����)
		float T_kontrol_step;								//  ����� ������������ ����� (0...1 ����)

		const double PI = 3.14159265;						// ���������� pi=3.14

		char Y;

		cout << "������ �������� ������? ���� ��, ������� Y" << endl;
		cin >> Y;

		if (Y =='Y')
		{
			cout << "������� �������� ������:" << endl;
			printf("������� �������� �������� �������� (400...900 ��/�):\n ");
			printf("V_ist = ");
			scanf("%d", &V_ist);
			printf(" ������� �������� ��������� ����� (0...360 ����):\n ");
			printf("Usl_kurs = ");
			scanf("%d", &Usl_kurs);
			printf(" ������� �������� ����� ������������ ����� (50...300 ��):\n ");
			printf("S_kontrol_step = ");
			scanf("%d", &S_kontrol_step);
			printf(" ������� �������� ������������ ��������� �������� ���� (0...360 ����):\n ");
			printf("FUPU = ");
			scanf("%d", &FUPU);
			printf(" ������� �������� ������� ������������ ����� (0...1 ����):\n ");
			printf("T_kontrol_step = ");
			scanf("%f", &T_kontrol_step);
		}

		else

		{
			V_ist = 400 + rand() % 501;					// ������� �������� �������� (400...900 ��/�)
			Usl_kurs = rand() % 361;					// ������� ��������� ����� (0...360 ����)
			S_kontrol_step = 50 + rand() % 251;			// ������� ����� ������������ ����� (50...300 ��)
			FUPU = rand() % 361;						// ������� ������������ ��������� �������� ���� (0...360 ����)
			T_kontrol_step = 0.01*(rand() % 101);		// ������� ������� ������������ ����� (0...1 ����)
		}
	
			// ������ ���� �����:									
			U_snos_std = (FUPU - Usl_kurs);//*(PI / 180);

			// ������ ������� ��������
			W_std = S_kontrol_step / T_kontrol_step;

			// ������ �������� �����
			U_std = sqrt(pow(V_ist, 2) + pow(W_std, 2) - 2 * V_ist*W_std*cos(U_snos_std));

			// �������� ���� � ���

			//Usl_kurs= Usl_kurs * (PI / 180);

			// ������ ����������� �����
			sigma_std = asin ((W_std*sin(Usl_kurs)) / 518) + 250;

			/*if (sigma_std > 0)
				sigma_std -= 360;
			else
				sigma_std += 360;
				*/
	
			// ����� �������� ������ (�������� ��������):
			printf("-------------------------------------\n ");
			cout << "�������� ������: " << endl;
			printf("-------------------------------------\n ");
			printf("�������� �������� = %d ��/�\n ", V_ist);
			printf("�������� ���� = %d ����. \n ", Usl_kurs);
			printf("����� ������������ ����� = %d ��\n ", S_kontrol_step);
			printf("���� = %d ����. \n ", FUPU);
			cout << "����� ������������ ����� = " << T_kontrol_step << " ����" << endl;
			printf("-------------------------------------\n ");

			//���� ������ ���������:
			printf("������� �������� ���� ����� (���):\n "); 
			printf("U_snos_clc = ");
			scanf("%d", &U_snos_clc);
			printf(" ������� �������� ������� �������� (��/�):\n ");
			printf("W_clc = ");
			scanf("%d", &W_clc);
			printf(" ������� �������� �������� ����� (��/�):\n ");
			printf("U_clc = ");
			scanf("%d", &U_clc);
			printf(" ������� �������� ����������� ����� (����):\n ");
			printf("sigma_clc = ");
			scanf("%d", &sigma_clc);

			if (sigma_clc == sigma_std) // ����������� �����
			{
				cout << "�������� ������ 5" << endl;
			}
			else 
				if (U_clc == U_std)//�������� �����
			{
				cout << "\n�������� ������ 4" << endl;
				printf(" \n�� �������� ��� ������� ����������� ����� sigma_std = %d ����\n ", sigma_std);
			}
			else 
				if (W_clc == W_std /*&& U_snos_clc == U_snos_std*/)//������� �������� � ���� �����
			{
				cout << "\n �������� ������ 3" << endl;
				printf(" \n�� �������� ��� ������� ��������  ����� U_std = %d ��/�\n ", U_std);

			}
			else 
				if (W_clc == W_std)// ������� ��������
			{
				cout << " \n�������� ������ 2" << endl;
				cout << " \n�� �������� ��� ������� ���� ����� = " << U_snos_std << " ���." << endl;
			}
			else
				cout << " \n�������� ������ 2" << endl;
				printf(" \n�� �������� ��� ������� ������� �������� = %d ��/�\n ", W_std);

		
			//����� �����������:
			printf("-------------------------------------\n ");
			cout << "���������� �������� (������): " << endl;
			printf("-------------------------------------\n ");
			cout << "���� ����� = " << U_snos_std << " ���." << endl;
			printf(" ������� �������� = %d ��/�\n ", W_std);
			printf("�������� ����� = %d ��/�\n ", U_std);
			printf("����������� ����� = %d ����\n ", sigma_std);
			
			
			
			system("pause>nul");
			return 0;
}
