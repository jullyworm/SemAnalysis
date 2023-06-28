// ���� ���������� ��� ������ �������������� ��������������

#ifndef IGramFeatureH
#define IGramFeatureH

#include "IGramFeatureValue.h"

class IGramFeature {
public:
	// ���������� ��� �������������� ��������������
	virtual const char* GetName() const = 0;
	// ���������� ����������� ��������� �������� ��������������
	virtual int GetFeatureValueCount() const = 0;
	// ������ ����� �������� �������������� ��������������,
	// ���������� ������ ���������;
	// ���� ��������� �������� ��� ���������� � �������,
	// �� ���������� � ������, �� �������� �����
	virtual int CreateNewFeatureValue(char* sFeatureValue) = 0;
	// ������� �������� �������������� ��������������,
	// ���������� ��� ��� ������
	// 0 - �������� ������ �������
	// 1 - �������� �������� �� ������� �������
	// 2 - �������� ������������ � ��������� ������
	virtual short DeleteFeatureValue(int Index) = 0;
	// ���������� �������� �� ��� �������
	virtual IGramFeatureValue* GetGramFeatureValue(int Index) const = 0;
	// ���� �������� ��������������
	// ���������� ������, ���������� ������
	// -1 ���� �������� �� �������
	virtual int FindFeatureValue(const char* sValue) const = 0;
	// ���������� ��� �������������� ��������������
	// 0 - ��������������� ��������
	// 1 - ����� ����
	// 2 - �������
	virtual short GetGramFeatureType() const = 0;
	// �������� ��������, ���������� ��� ��� ������
	// 0 - �������� ������ �������
	// 1 - �������� ��������� �������� �� ������� �������
	// 3 - ����� �������� ��� ����
	// (�������� ������� �������)
	virtual short SetValue(int Index, char* sNewValue) = 0;
};

#endif
