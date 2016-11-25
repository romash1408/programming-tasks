#include <stdio.h>

int days(int month, int vis){
    switch(month){
    case 2:
	return 28 + vis;
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
    int day, month, year;
    printf("Введите дату в формате дд.мм.гггг: ");
    while(scanf("%2d.%2d.%4d", &day, &month, &year) != 3)
    {
	printf("Неправильный формат даты. Попробуйте ещё раз: ");
    }
    
    if(day < 1 || month < 1 || month > 12)
    {
	printf("Неверные данные\n");
    }
    
    int vis = (year % 4 == 0 && year % 100 != 0);
    if(day > days(month, vis))
    {
	printf("В указанном месяце меньше дней\n");
	exit(1);
    }
    for(int m = 1; m < month; ++m)
    {
	day += days(m, vis);
    }
    
    printf("Порядковый номер дня в году: %d", day);
    return 0;
}