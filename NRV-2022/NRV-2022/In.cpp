#include "stdafx.h"

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN f;
		unsigned char ch = 'a';
		unsigned char l[8000] = "";
		int line = 0, position = 0, size = 0, ignor = 0, i = 0;
		std::ifstream in(infile);

		if (in.fail() == 0)
		{
			ch = in.get();			///получ. символ из файла
			while (!in.eof())
			{
				if (ch == ((unsigned char)'\n'))
				{
					line++;
				}
				if (f.code[(int)ch] == IN::T)
				{
					position++;
					l[i] = ch;
					i++;
				}
				else if (f.code[(int)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, line, position);	///Недопустимый символ в исходном коде
				}
				else if (f.code[(int)ch] == IN::I)
				{
					ignor++;
				}
				ch = in.get();
			}
			in.close();
			l[i] = '\0';
			f.size = i;			///кол-во символов
			f.text = l;			///текст в исх. коде
			f.lines = line;		///кол-во строк в файле
			f.ignor = ignor;	///кол-во проигнорированных
			f = OutText(f);
		}
		else
		{
			throw ERROR_THROW(110);	///Ошибка при открытии файла с исходным кодом
		}
		return f;
	}


	IN OutText(IN info) {
		IN out;
		
		unsigned char* buff = new unsigned char[info.size * 3];
		out.text = new unsigned char[info.size * 3];
		int k = 0, pr = 0;
		out.lines = 0;
		bool check = false;
		for (int i = 0; i <= info.size; i++)
		{
			if (info.text[i] == '\0')
			{
				buff[k++] = '\n';
			}
			if (info.text[i] == '(' || info.text[i] == ')' || info.text[i] == ',' || info.text[i] == '=' || info.text[i] == '+' || info.text[i] == '-'
				|| info.text[i] == '/' || info.text[i] == '*' || info.text[i] == '{' || info.text[i] == '}' || info.text[i] == ';')
			{
				buff[k++] = ' ';
				buff[k++] = info.text[i];
				buff[k++] = ' ';
			}
			else {
				buff[k] = info.text[i];
				k++;
			}
			
		
		}
		buff[k] = '\0';
		bool coment = false;
		for (int i = 0; i <= k; i++)
		{
			if (buff[i] == '#')
			{
				coment = true;
			}
			if (buff[i] == '\n')
			{
				coment = false;
			}
			if (!coment)
			{
				if (buff[i] == ' ' || buff[i] == '\0')
				{
					if (!check)
					{
						out.text[pr++] = buff[i];
						check = true;
					}


				}
				else {
					if (buff[i] == '\n')
					{
						out.text[pr++] = '|';
						out.text[pr++] = ' ';
						continue;
					}
					out.text[pr++] = buff[i];
					check = false;
				}
			}
			
			
		}
		out.text[pr] = '\0';
		out.size = pr;
		out.ignor = info.ignor;
		out.lines = info.lines + 1;
		return out;
	}

	char** splitText(unsigned char* origin, int size) { // Создаем массив строк, состоящий из лексем.
		char** words = new char* [max_word];
		for (int i = 0; i < max_word; i++)
			words[i] = new char[size_word] {NULL}; // Заполнение массив нулями.
		bool findSepSymb, findLiteral = false;
		bool coment = false;
		int count = 0;
		int j = 0;
		int pr = 0;
		char buff[20];
		char sepSymbArr[] = { " ,;(){}=+-*/|" };	// Массив символов сепараторов.
		for (int i = 0, k = 0; i < size - 1; i++, k++) {//sepSymbArr[t] == ' ' => true => k=-1+1=0
			findSepSymb = false;				// Флаг на нахождение апострафа.
			if (origin[i] == '\'')
			{
				findLiteral = !findLiteral;		// Нашли кавычку, меняем значение на противоположное.
				count++;
			}
			for (int t = 0; t < sizeof(sepSymbArr) - 1; t++)
			{
				if (origin[i] == sepSymbArr[t] && !findLiteral) { // findLiteral = false
					findSepSymb = true;			// Нашли сепаратор, меняем значение.
					if (words[j][0] != NULL)
					{
						words[j++][k] = '\0';		// Переход на новую строку.
						k = 0;
					}
					if (sepSymbArr[t] == ' ')		// Пробелы пропускаем!
					{
						k = -1;
						break;
					}
					words[j][k++] = sepSymbArr[t];// Не пробелы записываем.
					words[j++][k] = '\0';
					k = -1;
					break;
				}
			}
			if (!findSepSymb && origin[i] != '\n') {
				words[j][k] = origin[i];
			}
			

		}
		words[j] = NULL;
		if (count % 2 == 1)
		{
			throw ERROR_THROW(205)
		}
		for (int i = 0; i < j; i++)
			if (!strcmp((char*)words[i], ""))	// strcmp - осуществляет лексикографическую проверку двух строк.
				return NULL;					// strcmp - возвращает число, на сколько различаются.
		return words;
	}

	
		
	
};