// ���� ���������� ��� ������ �������

#ifndef ILexemaH
#define ILexemaH

#include "ICaseFrame.h"
#include "ISemanticAttr.h"
#include "IGramFeature.h"
#include "IGramFeatureValue.h"

class ILexema {
public:
	// ���������� ���������� ������������� �������
	virtual int GetID() const = 0;
	// ���������� ����������� ������� ���������� ��������������� ������ �������
	virtual int GetCaseFrameCount() const = 0;
	// ������������� ������ � ������ ���������� �� ������� � ������
	virtual ICaseFrame* GetCaseFrame(int Index) const = 0;
	// ���������� ���������� ����� �������
	virtual const char* GetNormForm() const = 0;
	// ������������� ����� �������� ���������� �����, ���������� ��� ��� ������
	// 0 - �������� ������ �������
	// 1 - �������� ���������� ����� �������� �� ������� �������
	// (�������� ������� �������)
	virtual short SetNormForm(char* sValue) = 0;

	// ������ � �������������� �������������
	//--------------------------------------------------------------------------
	// ��������� ������������� �����������
	// ���������� false, ���� ����� ����������� ��� ����,
	// ����� true
	virtual bool AddSemanticLimit(int uAttrSemanticTableIndex) = 0;
	// ������� ������������� �����������
	virtual void DeleteSemanticLimit(int Index) = 0;
	// ������������� ������ � �������������� �����������
	virtual ISemanticAttr* GetSemanticLimit(int Index) const = 0;
	// ���������� ���-�� ������������� �����������
	virtual int GetSemanticLimitCount() const = 0;
	//--------------------------------------------------------------------------

	// ������ � ���������������� �������������
	//--------------------------------------------------------------------------
	// ��������� ��������������� �����������
	// ���������� false, ���� ���������� � ����� ������ ��� ����,
	// ����� true
	virtual bool AddMorphLimit(int uAttrGramTableIndex, int uValueIndex) = 0;
	// ������������� ������ � ��������� �����������
	virtual IGramFeature* GetMorphLimitGramFeature(int Index) const = 0;
	// ���������� �������� ��������� �����������
	virtual IGramFeatureValue* GetMorphLimitGramValue(int Index) const = 0;
	// ������� �����������
	virtual void DeleteMorphLimit(int Index) = 0;
	// ���������� ���-�� ��������������� �����������
	virtual int GetMorphLimitCount() const = 0;
	//--------------------------------------------------------------------------

	// ������ � ������������ ����������
	//--------------------------------------------------------------------------
	// ��������� ����������� �������
	// ���������� false, ���� ������� � ����� ������ ��� ����,
	// ����� true
	virtual bool AddLexikalFeature(int uAttrGramTableIndex, int uValueIndex) = 0;
	// ������������� ������ � ��������
	virtual IGramFeature* GetLexikalFeature(int Index) const = 0;
	// ���������� �������� ��������
	virtual IGramFeatureValue* GetLexikalFeatureGramValue(int Index) const = 0;
	// ������� ����������� �������
	virtual void DeleteLexikalFeature(int Index) = 0;
	// ���������� ���-�� ����������� ���������
	virtual int GetLexikalFeatureCount() const = 0;
	// ���� ����������� ������� �� �����, ���������� ������
	virtual	int FindLexikalFeature(const char* sName) const = 0;
	//--------------------------------------------------------------------------

	// ������������� ������� ��� �������
	virtual void SetPreText(char* sPreText) = 0;
	// ������� ������� �� �������
	virtual void ClearPreText() = 0;
	// ���������� �������
	virtual const char* GetPreText() const = 0;
};

#endif
