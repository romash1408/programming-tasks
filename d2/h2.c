#include <stdio.h>

int main()
{
	int seconds, minutes, hourses, days;
	
	printf("Input seconds:");
	scanf("%d", &seconds);
	
	if(seconds < 0){
		printf("Wrang seconds count!");
		return 1;
	}
	
	minutes = seconds / 60;
	seconds -= minutes * 60;

	hourses = minutes / 60;
	minutes -= hourses * 60;

	days = hourses / 24;
	hourses -= days * 24;

	printf("%dd %dh %dm %ds\n", days, hourses, minutes, seconds);
	
	return 0;
}
