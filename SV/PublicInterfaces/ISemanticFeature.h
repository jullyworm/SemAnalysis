// ���� ���������� ��� ������ ���������� ������������ ���������
// ����� ��������� ������� ������������� ������������ �������

#ifndef ISemanticFeatureH
#define ISemanticFeatureH

#include "ISemanticAttr.h"
#include "IMorphFeature.h"

class ISemanticFeature {
public:
	// ��������� ������������� �������� � ����������
	// ������������ ������ ��������� �� �������
	// ����������:
	// false - ��������� ��������� ��� ���� � ����������
	// true - ������� �������� ����� ��������
	virtual bool AddSemanticAttr(int uAttrTableIndex) = 0;
	// ������� ������������� �������� �� ����������
	virtual void DeleteSemanticAttr(int Index) = 0;
	// ������������ ������ � �������������� ��������� �� �������
	virtual ISemanticAttr* GetSemanticAttr(int Index) const = 0;
	// ���������� ���-�� ������������� ���������� � ����������
	virtual int GetSemanticAttrCount() const = 0;
	// ������ ����� ������ ���������� ��������������� ���������
	virtual IMorphFeature* CreateMorphFeature() = 0;
	// ���������� ���������� ��������������� ���������
	virtual IMorphFeature* GetMorphFeature(int Index) const = 0;
	// ������� ���������� ��������������� ���������
	virtual void DeleteMorphFeature(int Index) = 0;
	// ���������� ���-�� ���������� ��������������� ���������
	virtual int GetMorphFeatureCount() const = 0;
};

#endif
