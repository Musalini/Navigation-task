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

		// рассчитанные значения (clc)
		int U_snos_clc;										// угол сноса
		int W_clc;										// путевая скорость
		int U_clc;										// скорость ветра
		float sigma_clc;									// направление ветра

		// эталонные значения (std)
		int U_snos_std;										// угол сноса
		int W_std;										// путевая скорость
		int U_std;										// скорость ветра
		float sigma_std;									// направление ветра
		
		float V_ist;											// истинная скорость (400...900 км/ч)
		float Usl_kurs;										// условный курса (0...360 град)
		float S_kontrol_step;									//  длина контрольного этапа (50...300 км)
		float FUPU;											// фактический условный путевой угол (0...360 град)
		float T_kontrol_step;								//  время контрольного этапа (0...1 часа)

		const double PI = 3.14159265;						// постоянная pi=3.14

		char Y;

		cout << "Задать исходные данные? Если да, нажмите Y" << endl;
		cin >> Y;

		if (Y =='Y')
		{
			cout << "Введите исходные данные:" << endl;
			printf("Введите значение истинной скорости (400...900 км/ч):\n ");
			printf("V_ist = ");
			scanf("%d", &V_ist);
			printf(" Введите значение условного курса (0...360 град):\n ");
			printf("Usl_kurs = ");
			scanf("%d", &Usl_kurs);
			printf(" Введите значение длины контрольного этапа (50...300 км):\n ");
			printf("S_kontrol_step = ");
			scanf("%d", &S_kontrol_step);
			printf(" Введите значение фактического условного путевого угла (0...360 град):\n ");
			printf("FUPU = ");
			scanf("%d", &FUPU);
			printf(" Введите значение времени контрольного этапа (0...1 часа):\n ");
			printf("T_kontrol_step = ");
			scanf("%f", &T_kontrol_step);
		}

		else

		{
			V_ist = 400 + rand() % 501;					// задание истинной скорости (400...900 км/ч)
			Usl_kurs = rand() % 361;					// задание условного курса (0...360 град)
			S_kontrol_step = 50 + rand() % 251;			// задание длины контрольного этапа (50...300 км)
			FUPU = rand() % 361;						// задание фактического условного путевого угла (0...360 град)
			T_kontrol_step = 0.01*(rand() % 101);		// задание времени контрольного этапа (0...1 часа)
		}
			// расчет угла сноса:									
			U_snos_std = (FUPU - Usl_kurs);//*(PI / 180);

			// расчет путевой скорости
			W_std = S_kontrol_step / T_kontrol_step;

			// расчет скорости ветра
			U_std = sqrt(pow(V_ist, 2) + pow(W_std, 2) - 2 * V_ist*W_std*cos(U_snos_std));

			// условный курс в рад

			//Usl_kurs= Usl_kurs * (PI / 180);

			// расчет направления ветра
			sigma_std = asin ((W_std*sin(Usl_kurs)) / 518) + 250;

			/*if (sigma_std > 0)
				sigma_std -= 360;
			else
				sigma_std += 360;
				*/
	
			// Вывод исходных данных (слуайные значения):
			printf("-------------------------------------\n ");
			cout << "Исходные данные: " << endl;
			printf("-------------------------------------\n ");
			printf("Истинная скорость = %d км/ч\n ", V_ist);
			printf("Условный курс = %d град. \n ", Usl_kurs);
			printf("Длина контрольного этапа = %d км\n ", S_kontrol_step);
			printf("ФУПУ = %d град. \n ", FUPU);
			cout << "Время контрольного этапа = " << T_kontrol_step << " часа" << endl;
			printf("-------------------------------------\n ");

			//Ввод данных студентом:
			printf("Введите значение угла сноса (рад):\n "); 
			printf("U_snos_clc = ");
			scanf("%d", &U_snos_clc);
			printf(" Введите значение путевой скорости (км/ч):\n ");
			printf("W_clc = ");
			scanf("%d", &W_clc);
			printf(" Введите значение скорости ветра (км/ч):\n ");
			printf("U_clc = ");
			scanf("%d", &U_clc);
			printf(" Введите значение направления ветра (град):\n ");
			printf("sigma_clc = ");
			scanf("%d", &sigma_clc);

			if (sigma_clc == sigma_std) // направление ветра
			{
				cout << "Итоговая оценка 5" << endl;
			}
			else 
				if (U_clc == U_std)//скорость ветра
			{
				cout << "\nИтоговая оценка 4" << endl;
				printf(" \nВы ошиблись при расчете направления ветра sigma_std = %d град\n ", sigma_std);
			}
			else 
				if (W_clc == W_std /*&& U_snos_clc == U_snos_std*/)//путевая скорость и угол сноса
			{
				cout << "\n Итоговая оценка 3" << endl;
				printf(" \nВы ошиблись при расчете скорости  ветра U_std = %d км/ч\n ", U_std);
			}
			else 
				if (W_clc == W_std)// путевая скоромть
			{
				cout << " \nИтоговая оценка 2" << endl;
				cout << " \nВы ошиблись при расчете угла сноса = " << U_snos_std << " рад." << endl;
			}
			else
				cout << " \nИтоговая оценка 2" << endl;
				printf(" \nВы ошиблись при расчете путевой скорости = %d км/ч\n ", W_std);

			//Вывод результатов:
			printf("-------------------------------------\n ");
			cout << "Результаты расчетов (эталон): " << endl;
			printf("-------------------------------------\n ");
			cout << "Угол сноса = " << U_snos_std << " рад." << endl;
			printf(" Путевая скорость = %d км/ч\n ", W_std);
			printf("Скорость ветра = %d км/ч\n ", U_std);
			printf("Направление ветра = %d град\n ", sigma_std);
			
			system("pause>nul");
			return 0;
}
