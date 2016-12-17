#include <stdio.h>
#include <time.h>
#include <locale.h>

void readprints(FILE* file)
{
	char next;
	while(feof(file) == 0 && (next = fgetc(file))) putchar(next);
	putchar('\n');
}

long breadi(FILE* file, int size)
{
	long ret = 0;
	for(--size; size >= 0 && feof(file) == 0; --size)
	{
		ret += fgetc(file) << (size * 8);
	}
	return ret;
}

long lreadi(FILE* file, int size)
{
	long ret = 0;
	int i =0;
	for(; i < size && feof(file) == 0; ++i)
	{
		ret += fgetc(file) << (i * 8);
	}
	return ret;
}

double lreadf(FILE* file)
{
	double ret = 0;
	fread(&ret, 8, 1, file);
	return ret;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	
	const int flagc = 5;
	int flagv[] = {0x1, 0x2, 0x4, 0x10, 0x20};
	char* flagn[] = {
		"информация о положении",
		"информация о цифровых входах",
		"информация о цифровых выходах",
		"бит тревоги",
		"информация об идентификаторе водителя"
	};
	char* blockHiddens[] = {"параметр скрыт", "параметр открыт"};
	char* blockDataTypes[] = {"текстовый", "бинарный", "целочисленный", "дробный", "целочисленный"};
	
	char* filename = argv[1];
	for(; argc > 1; argc--, argv++, filename = argv[1])
	{
		printf("\nВходящий пакет %s:\n", filename);
		FILE* inp = fopen(filename, "rb");
		if(!inp)
		{
			printf("Не удалось прочитать данные\n");
			continue ;
		}
		
		int fileSize, flags;
		time_t timeUTC;
		
		fileSize = lreadi(inp, 4);
		printf("Размер пакета: %d байт\n", fileSize + 4);
		
		printf("Идентификатор контроллера: ");
		readprints(inp);
		
		timeUTC = breadi(inp, 4);
		printf("Время: %s", asctime(gmtime(&timeUTC)));
		
		flags = breadi(inp, 4);
		if(flags > 0)
		{
			printf("Флаги:\n");
			int i = 0;
			for(; i < flagc; ++i)
			{
				if(flags & flagv[i]) printf("\t%s\n", flagn[i]);
			}
		}

		//Блоки
		printf("Чтение блоков:\n");
		while(feof(inp) == 0)
		{
			short blockType = breadi(inp, 2);
			if(feof(inp)) break;
			printf("\nБлок типа %d\n", blockType);

			int blockSize = breadi(inp, 4);
			printf("Размер блока %d байт\n", blockSize + 6);

			unsigned char blockHidden = breadi(inp, 1);
			if(blockHidden < 2) printf("Скрытость: %s\n", blockHiddens[blockHidden]);

			unsigned char blockDataType = breadi(inp, 1);
			if(blockDataType - 1 < 5) printf("Тип данных: %s\n", blockDataTypes[blockDataType - 1]);

			printf("Имя блока: ");
			readprints(inp);
			
			printf("Значение: ");
			switch(blockDataType)
			{
			case 0x1: readprints(inp); break;
			case 0x3: case 0x5: printf("%ld\n", breadi(inp, (blockDataType - 1) * 2)); break;
			case 0x4: printf("%f\n", lreadf(inp)); break;
			case 0x2:
				printf("\n\tДолгота %f", lreadf(inp));
				printf("\n\tШирота %f", lreadf(inp));
				printf("\n\tВысота %f", lreadf(inp));
				printf("\n\tСкорость %d", (unsigned short)breadi(inp, 2));
				printf("\n\tКурс %d", (unsigned short)breadi(inp, 2));
				printf("\n\tКоличество спутников %d\n", (unsigned char)breadi(inp, 1));
			}
		}
		
		fclose(inp);
	}

	printf("\nКонец работы программы...\n");
    return 0;
}