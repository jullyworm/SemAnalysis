// ���� ���������� ��� ������ ���������� ��������������� ���������
// ����� ��������� ������� ��������������� ������������ �������
// ����������� ����������� ������������� ��������

#ifndef IMorphFeatureH
#define IMorphFeatureH

#include "IGramFeature.h"
#include "IGramFeatureValue.h"

class IMorphFeature {
public:
	// ��������� �������� � ����������
	// ���������� false, ���� �������� � ����� ������ ��� ����,
	// ����� true
	virtual bool AddMorphAttr(int uAttrGramTableIndex, int uValueIndex) = 0;
	// ������������� ������ � ��������� �� �������
	virtual IGramFeature* GetGramFeature(int Index) const = 0;
	// ���������� ��� ���������
	virtual const char* GetGramFeatureName(int Index) const = 0;
	// ���������� �������� ���������
	virtual const char* GetGramFeatureValue(int Index) const = 0;
	// ������������� ������ � �������� ���������
	virtual IGramFeatureValue* GetGramFeatureValueObj(int Index) const = 0;
	// ������� ��������
	virtual void DeleteMorphAttr(int Index) = 0;
	// ���������� ����������� ���������� � ����������
	virtual int GetMorphAttrCount() const = 0;
	// ��������� ������� ��������� ���� �������
	// true - ���� � ���������� ������ �������
	virtual bool IsWithPreText() const = 0;
	// ��������� ������� ��������� ���� ����� ����
	// true - ���� � ���������� ������ ����� ����
	virtual bool IsWithPartOfSpeach() const = 0;
};

#endif
