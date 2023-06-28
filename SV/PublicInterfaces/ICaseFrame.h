// ���� ���������� ��� ������ ������ ����������

#ifndef ICaseFrameH
#define ICaseFrameH

#include "IAktant.h"

class ICaseFrame {
public:
	// ���������� ���������� ������������� ������ ����������
	virtual int GetID() const = 0;
	// ������������� ������ � ������� �� ��� �������
	virtual IAktant* GetAktant(int Index) const = 0;
	// ������� ������
	virtual void DeleteAktant(int Index) = 0;
	// ������ ����� ������ �������
	virtual IAktant* CreateAktant() = 0;
	// ���������� ����������� �������� ������ ������ ����������
	virtual int GetAktantCount() const = 0;
	// ������ � ������ ������ ����������
	virtual const char* GetName() const = 0;
	virtual void SetName(char* sNewName) = 0;
};

#endif
