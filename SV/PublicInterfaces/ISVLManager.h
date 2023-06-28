// ���� ���������� ��� ���������, ���������� ���������
// �������������� ���������� ����������

#ifndef ISVLManagerH
#define ISVLManagerH

#include "ISemanticVoc.h"
//#include "IViewerSemanticVoc.h"

class ISVLManager {
public:
	// ���������� ��������� ���������� � ����������� ������
	virtual void Release() = 0;
	// ������ ������������ ��������� �������������� ����������
	// ����������
	virtual ISemanticVoc* GetSemanticVoc() = 0;
};

#endif
