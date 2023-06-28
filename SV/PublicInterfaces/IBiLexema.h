#pragma once

#ifndef IBiLexemaH
#define IbiLexemaH

#include "ILexema.h"

class IBiLexema {
public:
	// ���������� ���������� ������������� ���������
	virtual int GetID() const = 0;
	//������������� ��� ���������
	virtual void SetName(char* aNewName) = 0;
	//���������� ��� ��������� (��� ����? ��� �����?)
	virtual const char* GetName() const = 0;
	//���������� ����� ������
	virtual int GetLexemaCount() const = 0;
	// ���������� ������� �� �������
	virtual ILexema* GetLexema(int Index) const = 0;
	virtual int FindLexema(ILexema* pLexema) const = 0;
	//���������� ��
	virtual ICaseFrame* GetCaseFrame(int LexemaIndex, int CaseFrameIndex) const = 0;
	//���������� ����� �� � �������
	virtual int GetCaseFrameCount(int LexemaIndex) const = 0;

};

#endif