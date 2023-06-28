#ifndef IWordBaseH
#define IWordBaseH

class IWordBase {
public:
	//�������� ������������ �����
	virtual const char* GetForm() const = 0;
	// ������� ������������� �������
	//-----------------------------------------------------------
	// �������� ���������� ����� �������
	virtual const char* GetWordNormalForm() const = 0;
	// ���������� ����������� ����������� ������������� ������� (��, ��� ������. � �.�.)
	virtual int GetLexikalFeatureCount() const = 0;
	// ���������� ��� ���������� ����������� ��������������
	virtual const char* GetLexikalFeatureName(int Index) const = 0;
	// ���������� �������� ���������� ����������� ��������������
	virtual const char* GetLexikalFeatureValue(int Index) const = 0;
	//-----------------------------------------------------------
	// ������� ���������� �������� ��� ���������� ����������
	// ���������� ����������� ������������� �������������
	virtual int GetSemanticFeatureCount() const = 0;
	// ���������� ���������� ������������� ��������������
	virtual const char* GetSemanticFeature(int Index) const = 0;
	// ���������� ����������� ����� ��������������� �������������
	virtual int GetMorphFeatureGroupCount() const = 0;
	// ���������� ����������� ��������������� �������������
	virtual int GetMorphFeatureCount(int uGroupIndex) const = 0;
	// ���������� ��� ��������������� ��������������
	virtual const char* GetMorphFeatureName(int uGroupIndex, int Index) const = 0;
	// ���������� �������� ��������������� ��������������
	virtual const char* GetMorphFeatureValue(int uGroupIndex, int Index) const = 0;
	// ���������� ����� ����
	virtual const char* GetPartOfSpeech() const = 0;
	// ����� ��������
	virtual const char* FindPretext() = 0;
	// ���������� �������
	virtual const char* GetPreText() const = 0;
	virtual void SetPreText(char* sPretext) = 0;
};

#endif
