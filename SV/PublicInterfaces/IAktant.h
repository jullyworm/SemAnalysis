// ���� ���������� ��� ������ �������

#ifndef IAktantH
#define IAktantH

#include "IUnCaseFrame.h"
//#include "ISemanticFeature.h"

class IAktant: public IUnCaseFrame {
public:
	//���������� ID ������������ ������ ����������
	virtual int GetIDParentCaseFrame() const = 0;
};

#endif
