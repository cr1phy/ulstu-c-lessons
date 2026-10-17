#include <stdio.h>
#include "input.h"
#include "menu.h"
#include "L71.h"
#include "L72.h"

void menu_L71(void) {
	while (1) {
		printf("\n===== ЛР 7.1. Работа с символами и строками =====\n");
		printf(" 1. Задача 7.1.1   - 20 символов от CH до CH+19\n");
		printf(" 2. Задача 7.1.2   - 30 символов от CH до CH-29\n");
		printf(" 3. Задача 7.1.3   - подсчёт пробелов\n");
		printf(" 4. Задача 7.1.4   - пробелы -> '#'\n");
		printf(" 5. Задача 7.1.5.1 - цифры -> '$' (isdigit)\n");
		printf(" 6. Задача 7.1.5.2 - цифры -> '$' (своя isdigit)\n");
		printf(" 7. Задача 7.1.6   - маленькие латинские -> большие\n");
		printf(" 8. Задача 7.1.7   - вариант\n");
		printf(" 0. Назад\n\n");

		int choice = read_choice();
		if (choice == 0)
			return;

		switch (choice) {
		case 1: L711();  break;
		case 2: L712();  break;
		case 3: L713();  break;
		case 4: L714();  break;
		case 5: L7151(); break;
		case 6: L7152(); break;
		case 7: L716();  break;
		case 8: L717();  break;
		default:
			printf("Нет такого пункта.\n");
		}
	}
}

void menu_L72(void) {
	while (1) {
		printf("\n===== ЛР 7.2. Работа со строками через указатели =====\n");
		printf(" 1. Задача 7.2.1   - strlen (массив, указатель)\n");
		printf(" 2. Задача 7.2.2   - strcmp (массив, указатель)\n");
		printf(" 3. Задача 7.2.3   - strcpy\n");
		printf(" 4. Задача 7.2.4   - strcat\n");
		printf(" 5. Задача 7.2.5   - strchr (массив, указатель)\n");
		printf(" 6. Задача 7.2.6.1 - CreateNewString, ввод строки\n");
		printf(" 7. Задача 7.2.6.2 - CreateNewStringP, ввод строки\n");
		printf(" 8. Задача 7.2.6   - тесты CreateNewString и CreateNewStringP\n");
		printf(" 9. Все тесты\n");
		printf(" 0. Назад\n\n");

		int choice = read_choice();
		if (choice == 0)
			return;

		switch (choice) {
		case 1: test_strlen();    break;
		case 2: test_strcmp();    break;
		case 3: test_strcpy();    break;
		case 4: test_strcat();    break;
		case 5: test_strchr();    break;
		case 6: demo_L7261();     break;
		case 7: demo_L7262();     break;
		case 8: test_newstring(); break;
		case 9: test_all();       break;
		default:
			printf("Нет такого пункта.\n");
		}
	}
}
