#pragma once
#pragma comment(lib, "klan_core.lib")
#pragma comment(lib, "SV lib.lib")

#include "KNKernel.h"
#include "SemanticVocLibrary.h"
#include "CWordBase.h"

#include <vector>

struct AktantWord {
	IAktant* m_pAktant;
	IWordBase* m_pWord;
};
struct CaseFrameWords {
	ICaseFrame* m_pCaseFrame;
	std::vector < AktantWord* > m_WordVec;
};
struct UnCaseFrameWord {
	IUnCaseFrame* m_pUnCaseFrame; 
	IWordBase* m_pWord;
};
struct BilexemaWords {
	IBiLexema* m_pBilexema;
	std::vector < CaseFrameWords* > m_CFWordVec;
};

class Analysis 
{
public:
	Analysis(ISemanticVoc* pModels, IKNManager* pKlan);
	~Analysis();

	void TestSentence(const char* sSentence);

	int GetCaseFrameWordsCount() const;
	CaseFrameWords* GetCaseFrameWords(int Index) const;
	int GetUnCaseFrameWordCount() const;
	UnCaseFrameWord* GetUnCaseFrameWord(int Index) const;
	int GetBilexemaWordsCount() const;
	BilexemaWords* GetBilexemaWords(int Index) const;
	/*
	bool TestSemProp(IWordBase* pWord, ISemanticFeature* pSemanticFeature);
	bool TestMorphProp(IWordBase* pWord, ISemanticFeature* pSemFeature);
	bool TestCaseFrame(IWordBase* pWord, ICaseFrame* pCaseFrame);*/
	void TestCaseFrames(ILexema* pLexema, std::vector <IWordBase*> pWordVec);
	void TestUnCaseFrame(IWordBase* pWord, IUnCaseFrame* pUnCaseFrame);
	CaseFrameWords* TestCaseFrameBL(ILexema* pLexema, ICaseFrame* pCaseFrame, std::vector <IWordBase*> pWordVec);

	void FindBilexema(IBiLexema* pBilexema, std::vector < IWordBase*> pWordVec, int Index);

private:
	std::vector <CaseFrameWords*> m_CaseFrameVec;
	std::vector <UnCaseFrameWord*> m_UnCaseFrameVec;
	std::vector <BilexemaWords*> m_BilexemaVec;
	ISemanticVoc* m_pModels;
	IKNManager* m_pKlan;
};