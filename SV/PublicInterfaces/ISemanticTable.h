// ���� ���������� ��� ������ ������� ������������� ����������

#ifndef ISemanticTableH
#define ISemanticTableH

#include "ISemanticAttr.h"

class ISemanticTable {
public:
	// ���������� ����������� ������������� ���������� � �������
	virtual int GetSemanticAttrCount() const = 0;
	// ������ ����� ������������� �������� � �������,
	// ���������� ������ ���������;
	// ���� �������� � ��������� ��������� ��� ���������� � �������,
	// �� ���������� ��� ������, �� �������� ������
	virtual int CreateNewSemanticAttr(char* sSemanticAttrValue) = 0;
	// ������� �������������� �������� �� �������,
	// ���������� ��� ��� ������
	// 0 - �������� ������ �������
	// 1 - �������� ��������� �������� �� ������� �������
	// 2 - �������� ������������ � ��������� ������
	virtual short DeleteSemanticAttr(int Index) = 0;
	// ���������� ������������� �������� �� ��� �������
	virtual ISemanticAttr* GetSemanticAttr(int Index) const = 0;
	// ���� ������������� �������� �� ��� ��������,
	// ���������� ������, ���� ����� ��������� �����
	virtual int FindSemanticAttr(const char* sSemanticAttrValue) const = 0;
	// �������� �������� ���������, ���������� ��� ��� ������
	// 0 - �������� ������ �������
	// 1 - �������� ��������� �������� �� ������� �������
	// 3 - ����� ������� ��� ���� � �������
	// (�������� ������� �������)
	virtual short SetSemanticAttrValue(int Index, char* sNewSemanticAttrValue) = 0;
};

#endif
