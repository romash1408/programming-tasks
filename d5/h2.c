#include <stdio.h>

int days(int month){
    switch(month){
    case 2:
    return 29;
    case 4:
    case 6:
    case 9:
    case 11:
    return 30;
    default:
    return 31;
    }
}

int main()
{
	int day, month;
	char* zod[12];
	zod[0] = "Водолей";
	zod[1] = "Рыбы";
	zod[2] = "Овен";
	zod[3] = "Телец";
	zod[4] = "Близнецы";
	zod[5] = "Рак";
	zod[6] = "Лев";
	zod[7] = "Дева";
	zod[8] = "Весы";
	zod[9] = "Скорпион";
	zod[10] = "Стрелец";
	zod[11] = "Козерог";
	
	printf("Для выхода используйте сочетание [ctrl+D]\n");
	do
	{
		printf("Введите день и номер месяца вашего рождения: ");
		if(scanf("%d %d", &day, &month) < 2)
		{
			printf("\n");
			continue;
		}
		
		if(month < 1 || month > 12)
		{
			printf("Неверно введён номер месяца(%02d)\n", month);
			continue ;
		}
		if(day < 1 || day > days(month))
		{
			printf("В заданном месяце(%02d) нет выбранного дня(%02d)\n", month, day);
			continue ;
		}
		
		int before = 0;
		switch(month)
		{
		case 6:
		case 12: before = day <= 21; break;
		case 7:
		case 11: before = day <= 22; break;
		case 8:
		case 9:
		case 10: before = day <= 23; break;
		default: before = day <= 20;
		}
	
		printf("Ваш знак Зодиака(для %02d.%02d): %s\n", day, month, zod[(12 + month - before - 1) % 12]);
	} while(getchar() != EOF);
	return 0;
}