#include "stdafx.h"

namespace IT
{
	IdTable Create(int size)				//Создать ТИ
	{
		IdTable* tabl = new IdTable;
		if (size > TI_MAXSIZE)
		{
			throw ERROR_THROW(115);		///Заданное количество строк > 4096
		}
		tabl->maxsize = size;
		tabl->size = 0;
		tabl->table = new Entry[size];	///новая строка ТИ
		return*tabl;
	}

	void Add(IdTable& idtable, Entry entry)	//Добавить строку в ТИ
	{
		if (idtable.size + 1 > idtable.maxsize)
		{
			throw ERROR_THROW(116);		///Превышено количество строк в ТИ
		}

		idtable.table[idtable.size] = entry;
		idtable.size += 1;
	}

	Entry GetEntry(IdTable& idtable, int n)	//Возвр. ид. по номеру строки
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])	//Возвр. № строки
	{
		for (int i = 0; i < idtable.size; i++)
		{
			if (strcmp(idtable.table[i].id, id) == 0)
				return i;
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)	//Удалить ТИ
	{
		delete[] idtable.table;
		//delete &idtable;
	}


	void ShowTable(IdTable idt, std::ostream& stream_out)
	{
		int i, j, numberOP = 0;
		stream_out << "\n";
		stream_out << std::setfill('-') << std::setw(87) << '-' << std::endl;
		stream_out << "   #" << " | " << "Идентификатор" << " | " << "Тип данных" << " | " << "Тип идентификатора"
			<< " | " << "Значение" << std::endl;
		stream_out << std::setw(87) << '-' << std::endl;

		for (i = 0, j = 0; i < idt.size; i++, j++) {
			stream_out << std::setfill('0') << std::setw(4) << std::right << j << " | ";
			stream_out << std::setfill(' ') << std::setw(13) << std::left << idt.table[i].id << " | ";

			if (idt.table[i].idtype == IT::OP) stream_out << std::setw(10) << std::left << "-" << " | ";
			else
			{
				switch (idt.table[i].iddatatype)
				{
				case STR:
					stream_out << std::setw(10) << std::left;
					stream_out << "str" << " | ";
					break;
				case UINT:
					stream_out << std::setw(10) << std::left;
					stream_out << "uint" << " | ";
					break;
				case BOOL:
					stream_out << std::setw(10) << std::left;
					stream_out << "bool" << " | ";
					break;
				default:
					stream_out << std::setw(10) << std::left << "unknown" << " | ";
					break;
				}
			}

			switch (idt.table[i].idtype) {
			case V: stream_out << std::setw(18) << std::left << "переменная" << " | "; break;
			case F: stream_out << std::setw(18) << std::left << "функция" << " | "; break;
			case P: stream_out << std::setw(18) << std::left << "параметр" << " | "; break;
			case L: stream_out << std::setw(18) << std::left << "литерал" << " | "; break;
			case OP:
				stream_out << std::setw(18) << std::left << "оператор" << " | ";
				numberOP++;
				break;
			default: stream_out << std::setw(18) << std::left << "unknown" << " | "; break;
			}
			//stream_out << std::setw(11) << std::left << idt.table[i].idxfirstLE << " | ";

			if (idt.table[i].iddatatype == UINT && (idt.table[i].idtype == V || idt.table[i].idtype == L))
				stream_out << std::setw(18) << std::left << idt.table[i].value.vuint;
			else if (idt.table[i].iddatatype == BOOL && (idt.table[i].idtype == V || idt.table[i].idtype == L))
				stream_out << std::setw(18) << std::left << idt.table[i].value.vbool;
			else if (idt.table[i].iddatatype == STR && (idt.table[i].idtype == V || idt.table[i].idtype == L))
				stream_out << "[" << idt.table[i].value.vstr.len << "]\"" << idt.table[i].value.vstr.str << "\"";
			else stream_out << "-";
			stream_out << std::endl;
		}

		stream_out << std::setfill('-') << std::setw(87) << "-" << std::endl;
		stream_out << "Количество идентификаторов: " << i << std::endl;
		stream_out << std::setw(87) << "-" << std::endl;


	}
};