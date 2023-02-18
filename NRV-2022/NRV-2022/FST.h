#pragma once
#include "stdafx.h"
#include "In.h"
#include "Parm.h"
namespace FST
{
	struct RELATION //ребро
	{
		char symbol;	///символ перехода
		short nnode;	///номер инцидентной вершины
		RELATION(
			char c = 0x00,
			short ns = NULL
		);
	};

	struct NODE	//вершина графа
	{
		short n_relation;		///количество инцидентных ребер
		RELATION *relations;	///инцидентные ребра
		NODE();
		NODE(
			short n,
			RELATION rel, ...
		);
	};

	struct FST	//КА
	{
		char *string;	///цепочка(строка, завершается 0x00)
		short position;	///текущая позиция в цепочке
		short nstates;	///кол-во состояний автомата
		NODE *nodes;	///граф переходов: [0] - начальное сост., [nstate-1] - конечное
		short *rstates;	///возможные состояния автомата на данной позиции
		FST(
			char *s,
			short ns,
			NODE n, ...
		);
	};

	bool execute(	//выполнить распознавание цепочки
		FST &fst
	);
};