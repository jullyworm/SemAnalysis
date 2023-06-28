// ���� ���������� ��� �������������� ���������� ����������

#ifndef IViewerSemanticVocH
#define IViewerSemanticVocH

#include <vector>
#include "ICaseFrame.h"
#include "IWordBase.h"
#include "IAktant.h"
#include "IExternalVoc.h"

class IViewerSemanticVoc {
public:
	// ������������ ������� ����� ������� ��������� ������������� ������� ������� ��������
	// aFirstWord, aSecondWord - ����������� �������
	virtual IAktant* TestCaseFrame(IWordBase* aFirstWord, IWordBase* aSecondWord) const = 0;
	virtual IAktant* TestCaseFrame(IWordBase* pWord, ICaseFrame* pCaseFrame) = 0;

	virtual ICaseFrame* TestCaseFrame(std::vector <IWordBase*> aWords) const = 0;
	//virtual bool TestCaseFrame(std::vector <IWordBase*> aWords, const char* name_case_frame) const = 0;
	//virtual bool TestCaseFrame(IWordBase* aFirstWord, const char* name_un_case_frame) const = 0;

	// ��������� ������������� �������� � �����
	virtual bool TestSemProp(IWordBase* pWord, ISemanticFeature* pSemanticFeature) const = 0;
	// ��������� ��������������� �������� � �����
	virtual bool TestMorphProp(IWordBase* pWord, ISemanticFeature* pSemFeature) const = 0;
	// ��������� �������������� ����� � ������ ����������
	virtual bool TestCaseFrame(IWordBase* pWord, ICaseFrame* pCaseFrame) const = 0;

	// ���������� ��������� �� ��������� ������ ���������� ��� �������
	virtual ICaseFrame* GetParentCaseFrame(IAktant* pAktant) const = 0;
	//������� ������������
	virtual bool MorphCompare(IWordBase* aFirstWord, IWordBase* aSecondWord, const char* attr) = 0;
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
	virtual void SaveToTXT(char* sFileName) const = 0;



	/*// ������������� ������ � ������ ���������� �� ������� � ������
	virtual ICaseFrame* GetCaseFrame(int Index) const = 0;
	// ������� ������ ���������� �� � ������� � ������
	virtual void DeleteCaseFrame(int Index) = 0;
	// ������ ����� ������ ������ ���������� � �������
	virtual ICaseFrame* CreateCaseFrame() = 0;

	// ���������� ����������� ������� ���������� � �������
	virtual int GetCaseFrameCount() const = 0;
	// ���������� ������ ������ ����������
	virtual int FindCaseFrame(ICaseFrame* pCaseFrame) const = 0;
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
	//���������� ������ ������ ���������� ������ ���������� �� � �����
	//������������ ��� �������� ������ �� �����
	virtual int FindCaseFrame(char* sName) const = 0;*/
};

#endif
