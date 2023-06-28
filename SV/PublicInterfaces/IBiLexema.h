#pragma once

#ifndef IBiLexemaH
#define IbiLexemaH

#include "ILexema.h"

class IBiLexema {
public:
	// Возвращает уникальный идентификатор билексемы
	virtual int GetID() const = 0;
	//Устанавливает имя билексемы
	virtual void SetName(char* aNewName) = 0;
	//Возвращает имя билексемы (ЭТО ЕСТЬ? ЭТО НУЖНО?)
	virtual const char* GetName() const = 0;
	//Возвращает число лексем
	virtual int GetLexemaCount() const = 0;
	// Возвращает лексему по индексу
	virtual ILexema* GetLexema(int Index) const = 0;
	virtual int FindLexema(ILexema* pLexema) const = 0;
	//Возвращает МУ
	virtual ICaseFrame* GetCaseFrame(int LexemaIndex, int CaseFrameIndex) const = 0;
	//Возвращает число МУ в лексеме
	virtual int GetCaseFrameCount(int LexemaIndex) const = 0;

};

#endif