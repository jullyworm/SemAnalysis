// ���� ���������� ��� ������ �������������� ���������

#ifndef ISemanticAttrH
#define ISemanticAttrH

class ISemanticAttr {
public:
	// ���������� �������� �������������� ���������
	virtual const char* GetSemanticAttrValue() const = 0;
};

#endif
