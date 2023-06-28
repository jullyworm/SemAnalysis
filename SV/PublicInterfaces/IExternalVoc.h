#ifndef IExternalVocH
#define IExternalVocH

class IExternalVoc {
public:
	// ��������� �������� ������ �������
	virtual void Init() = 0;
	// ������� �������� ��������� �������
	virtual void SetNextLexemaActive() = 0;
	// ���������� ���-�� ����������� �������� �� ������� �������
	virtual int GetLexemaCount() const = 0;
	// ���������� ���������� ����� �������
	virtual const char* GetLexemaNormForm() const = 0;
	// ���������� ��� ����� ���� �������
	virtual const char* GetLexemaPartOfSpeach() const = 0;
	// ���������� ���-�� ����������� ��������� � �������
	virtual int GetLexemaLexikalFeatureCount() const = 0;
	// ���������� ��� ����. �������� ��� ���������� �������
	virtual const char* GetLexemaLexikalFeatureName(int uFeatureIndex) const = 0;
	// ���������� �������� ������������ �������� ���������� �������
	virtual const char* GetLexemaLexikalFeatureValue(int FeatureIndex) const = 0;
	// ���������� ���-�� �������������� �������������
	virtual int GetGramFeatureCount() const = 0;
	// ���������� ��� ����. �-��
	virtual const char* GetGramFeatureName(int Index) const = 0;
	// ���������� ���-�� �������� ����. �-��
	virtual int GetGramFeatureValueCount(int Index) const = 0;
	// ���������� ���������� �������� ��� ����. �-��
	virtual const char* GetGramFeatureValue(int uFeatureIndex, int uValueIndex) const = 0;
	// ���������� ����������� ������������� ���������
	virtual int GetSemAttrCount() const = 0;
	// ���������� �������� ��� �������������� ��������
	virtual const char* GetSemAttrValue(int Index) const = 0;
	// ���������� ����������� ������ ���� �� ������� �������
	virtual int GetPartOfSpeachCount() const = 0;
	// ���������� ����� ��� ����� ���� �������� �������
	virtual const char* GetPartOfSpeach(int Index) const = 0;
};

#endif
