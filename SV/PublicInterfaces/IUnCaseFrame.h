// ���� ���������� ��� ������ ������� ������ ����������

#ifndef IUnCaseFrameH
#define IUnCaseFrameH

#include "ISemanticFeature.h"

class IUnCaseFrame
{
public:
	// ���������� ���������� ������������� �������
	virtual int GetID() const = 0;
	// ������������� ������ � ���������� ������������� ��������� �� �������
	virtual ISemanticFeature* GetSemanticFeature(int Index) const = 0;
	// ������� ���������� ������������� ���������
	virtual void DeleteSemanticFeature(int Index) = 0;
	// ������ ����� ������ ���������� ������������� ���������
	virtual ISemanticFeature* CreateSemanticFeature() = 0;
	// ���������� ����������� ���������� ������������� ���������
	virtual int GetSemanticFeatureCount() const = 0;
	// ������ � ������
	virtual const char* GetName() const = 0;
	virtual void SetName(char* sNewName) = 0;
};

#endif