#include <iostream>
#include <locale>
using namespace std;

class Сoder
{
public:
	static char* encode(char* str, char* alpha)
	{
		char beta[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
		int str_length = strlen(str) + 1;
		char* result = new char[str_length];
		for (int i = 0; i < strlen(str); i++)
		{
			for (int j = 0; j < strlen(alpha); j++)
			{
				if (str[i] == beta[j])
				{
					result[i] = alpha[j];
				}
			}
		}
		result[str_length - 1] = '\0';

		return result;
	}

	static char* decode(char* str, char* alpha)
	{
		char beta[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
		int str_length = strlen(str) + 1;
		char* result = new char[str_length];
		for (int i = 0; i < strlen(str); i++)
		{
			for (int j = 0; j < strlen(beta); j++)
			{
				if (str[i] == alpha[j])
				{
					result[i] = beta[j];
				}
			}
		}
		result[str_length - 1] = '\0';

		return result;
	}
private:
};

int main()
{
	setlocale(LC_ALL, "rus");
	int menu = 1;
	int selection = 0;
	char replacement[53] = "GgJjMmAaHhVvWwRrFfUuZzEeSsPpBbLlOoYyXxLiQqCcDdNnTtKk";
	char word[80];
	cout << "Программа для шифровки и расшифровки слов." << endl;
	while (menu == 1)
	{
		cout << "Введите слово не длиннее 79 символов, используя буквы латинского алфавита:" << endl;
		cin >> word;
		cout << "Укажите требуемую операцию: (1 - зашифровать, 2 - расшифровать)" << endl;
		cin >> selection;
		if (selection == 1)
		{
			cout << Сoder::encode(word, replacement); cout << endl;
		}
		else if (selection == 2)
		{
			cout << Сoder::decode(word, replacement); cout << endl;
		}
		else
		{
			cout << "Несуществующая операция, повторите ввод:" << endl;
		}
		cout << "Чтобы повторить операцию, введите 1. Для завершения программы введите любой символ." << endl;
		cin >> menu;
	}
}