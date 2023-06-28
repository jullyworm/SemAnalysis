// ���� ���������� ��� �������������� ���������� ����������
#pragma once

#ifndef ISemanticVocH
#define ISemanticVocH

#include "IViewerSemanticVoc.h"
#include "ILexema.h"
#include "IBiLexema.h"
#include "IUnCaseFrame.h"
#include "ISemanticTable.h"
#include "IGramTable.h"


class ISemanticVoc : public IViewerSemanticVoc {
public:
	/*// ������������ ������� ����� ������� ��������� ������������� ������� ������� ��������
	// aFirstWord, aSecondWord - ����������� �������
	virtual IAktant* TestCaseFrame(IWordBase* aFirstWord, IWordBase* aSecondWord) = 0;
	// ���������� ��������� �� ��������� ������ ���������� ��� �������
	virtual ICaseFrame* GetParentCaseFrame(IAktant* pAktant) = 0;
	//������� ������������
	virtual bool MorphCompare(IWordBase* aFirstWord, IWordBase* aSecondWord, bool bRodFlag, bool bChisloFlag, bool bCaseFlag) = 0;
	// ��������� ������ �� �������� �������
	virtual void AddFromExternalVoc(IExternalVoc* pExternalVoc) = 0;
	// ��������� ������� � ����
	virtual short SaveToFile(char* sFileName) const = 0;
	// ��������� ������� �� �����
	virtual short LoadFromFile(char* sFileName) = 0;
	// ��������� ������ �� ����� � �������
	virtual int AddFromFile(char* sFileName) = 0;
	//��������� ������ ���������� �� ���������� �����
	virtual void LoadFromTXT(char* sFileName) = 0;
	// ��������� ������ ���������� � ��������� ����
	virtual void SaveToTXT(char* sFileName) const = 0;*/


	// ������������� ������ � ������ ���������� �� ������� � ������
	virtual ICaseFrame* GetCaseFrame(int Index) const = 0;
	// ������� ������ ���������� �� � ������� � ������
	virtual void DeleteCaseFrame(int Index) = 0;
	// ������ ����� ������ ������ ���������� � �������
	virtual ICaseFrame* CreateCaseFrame() = 0;

	// ������������� ������ � ������ ���������� �� ������� � ������
	virtual IUnCaseFrame* GetUnCaseFrame(int Index) const = 0;
	// ������� ������ ���������� �� � ������� � ������
	virtual void DeleteUnCaseFrame(int Index) = 0;
	// ������ ����� ������ ������ ���������� � �������
	virtual IUnCaseFrame* CreateUnCaseFrame() = 0;

	// ���������� ����������� ������� ���������� � �������
	virtual int GetCaseFrameCount() const = 0;
	// ���������� ����������� ������� ������� ���������� � �������
	virtual int GetUnCaseFrameCount() const = 0;
	// ���������� ������ ������ ����������
	virtual int FindCaseFrame(ICaseFrame* pCaseFrame) const = 0;

	// ������������� ������ � ��������� �� � ������� � ������
	virtual IBiLexema* GetBiLexema(int Index) const = 0;
	// ������� ��������� �� � ������� � ������
	virtual void DeleteBiLexema(int Index) = 0;
	// ������ ����� ������ ��������� � �������
	virtual IBiLexema* CreateBiLexema(char* sNormForm) = 0;
	// ���������� ����������� �������� � �������
	virtual int GetBiLexemaCount() const = 0;
	virtual int FindBilexemaWithLexema(ILexema* pLexema) const = 0;
	// ��������� ������� � ���������
	virtual void AddLexemaToBilexema(ILexema* pLexema, IBiLexema* pBiLexema) = 0;
	// ������� ������� �� ���������
	//virtual void RemoveLexemaFromBilexema(IBiLexema* pBilexema, int LexemaIndex) = 0;

	// ������������� ������ � ������� �� � ������� � ������
	virtual ILexema* GetLexema(int Index) const = 0;
	// ������� ������� �� � ������� � ������
	virtual void DeleteLexema(int Index) = 0;
	// ������ ����� ������ ������� � �������
	virtual ILexema* CreateLexema(char* sNormForm) = 0;
	// ���������� ����������� ������ � �������
	virtual int GetLexemaCount() const = 0;
	// ������ � ������������ ������� ������ ����������
	virtual void AddCaseFrameToLexema(ICaseFrame* pCaseFrame, ILexema* pLexema) = 0;
	// ������� ������������ ������ ���������� � �������
	virtual void RemoveCaseFrameFromLexema(ILexema* pLexema, int CaseFrameIndex) = 0;
	// �������� ������ ������� ������� (������� �������, ������ ����������, ��������� ������ ���������� �� ���������)
	virtual void Clear() = 0;
	// ������������� ������ � ������� ������������� �������������
	virtual ISemanticTable* GetSemanticTable() const = 0;
	// ������������� ������ � ������� �������������� �������������
	virtual IGramTable* GetGramTable() const = 0;
	//��������� ������� ��������� � ���� �� ���������
	// ������������ ��������
	// 0 - ������ ��� ����������
	// 1 - �������� ������ �������
	virtual short SaveTables() = 0;
	//���������� ������ ������ ���������� ������� �� � ���������� �����
	//������������ ��� �������� ������ �� �����
	virtual int FindLexema(char* sNormForm) const = 0;
	// ���������� ������ �������
	virtual int FindLexema(ILexema* pLexema) const = 0;
	// ���������� ��������� �� �������
	virtual ILexema* FindLexema(IWordBase* pWord) const = 0;
	//���������� ������ ������ ���������� ������ ���������� �� � �����
	//������������ ��� �������� ������ �� �����
	virtual int FindCaseFrame(char* sName) const = 0;
};

#endif

