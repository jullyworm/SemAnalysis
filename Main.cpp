#include "Analysis.h"

#include <io.h>
#include <fstream>
#include <string>
#include <iostream>

struct SentenceType {
	std::string sentence;
	std::string type;
};

//���������� ����� �����
std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	std::string s(size, ' ');
	f.seekg(0);
	f.read(&s[0], size); // �� ��������� ����� � C++11, �� ����� �������� � �� ������ ������������
	return s;
}


//���������� � �������� ����� � ��������� ��������� ����������� (��� ������ ����� ������ ������ �������)
bool EndOfSentence(const char* text, int position) {
	int i = position;
	if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?') || (text[i] == '\n') || (text[i] == ';')) {
		if (!(
			((text[i - 1] == '�') && (text[i - 2] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == '�') && (text[i - 3] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == '�') && (text[i - 3] == ' ')) ||
			((text[i - 1] == '�') && (text[i - 2] == '�') && (text[i - 3] == '�') && (text[i - 4] == '�') && (text[i - 5] == '�') && (text[i - 6] == '�')) ||
			((text[i - 1] == '�') && (text[i - 2] == '�') && (text[i - 3] == '�') && (text[i - 4] == ' '))
			)) return true;
	}
	return false;
}

int SizeOfSentence(const char* text, int positionOfSentence) {
	int sizeOfSentence = 0;
	int size = strlen(text);
	for (int i = positionOfSentence; i < size; i++) {
		if (EndOfSentence(text, i)) {
			sizeOfSentence = i - positionOfSentence + 1;
			break;
		}
	}
	return sizeOfSentence;
}

std::string Sentence(const char* text, int positionOfSentence) {
	int sizeOfSentence = SizeOfSentence(text, positionOfSentence);
	std::string sentence;
	if (sizeOfSentence == 1) {
		return "\n";
	}
	for (int i = positionOfSentence; i < positionOfSentence + sizeOfSentence; i++) {
		std::string textstr = text;
		if (EndOfSentence(text, i)) {
			sentence = textstr.substr(positionOfSentence, sizeOfSentence);
			break;
		}
	}
	return sentence;
}

std::vector <std::string> ParseDocTXT(const char* TextFile) {
	std::string text = readFile(TextFile);
	int position_of_sentence = 0;
	std::vector <std::string> result;
	while (SizeOfSentence(text.c_str(), position_of_sentence) != 0) {
		std::string sentence = Sentence(text.c_str(), position_of_sentence);
		position_of_sentence = position_of_sentence + SizeOfSentence(text.c_str(), position_of_sentence);
		result.push_back(sentence);
	}
	return result;
}

//������ ������ ����� ��������������� ������
int MainAnalysis(const char* TextFile, char* ModelsFile, const char* VocFile, const char* OutFile) { // ��������� ��������

	std::vector <std::string> sentences = ParseDocTXT(TextFile);

	IKNManager* klan = GenerateAPIManager();

	//�������� ������ �� �����
	ISVLManager* manager = CreateAPIManager();
	ISemanticVoc* models = manager->GetSemanticVoc();
	models->LoadFromTXT(ModelsFile);

	klan->Create();

	klan->SetPath((char*)VocFile);
	if (klan->Load())
	{
		std::cout << "Vocabulary is not correct." << std::endl;
		try { klan->Release(); }
		catch (...) { return 0; }
		return 0;
	}

	std::ofstream fout(OutFile);

	for (const auto& sentence : sentences) {
		Analysis *analysis = new Analysis(models, klan);
		analysis->TestSentence(sentence.c_str());
		//���������� ������� ������
		fout << "S " << sentence << std::endl;
		for (int i = 0; i < analysis->GetCaseFrameWordsCount(); ++i) {
			fout << "	������ " << analysis->GetCaseFrameWords(i)->m_pCaseFrame->GetName() << ": " << std::endl;
			for (int j = 0; j < analysis->GetCaseFrameWords(i)->m_WordVec.size(); ++j) {
				IWordBase* word = analysis->GetCaseFrameWords(i)->m_WordVec[j]->m_pWord;
				IAktant* aktant = analysis->GetCaseFrameWords(i)->m_WordVec[j]->m_pAktant;
				if (aktant == nullptr) fout << "		��������: ";
				else fout << "		Aktant " << aktant->GetName() << ": ";
				if (word->GetPreText() != NULL) fout << word->GetPreText() << " ";
				fout << word->GetForm() << std::endl;
			}
			fout << std::endl;
		}
		for (int i = 0; i < analysis->GetUnCaseFrameWordCount(); ++i) {
			fout << "	������� ������ " << analysis->GetUnCaseFrameWord(i)->m_pUnCaseFrame->GetName() << ": ";
			IWordBase* word = analysis->GetUnCaseFrameWord(i)->m_pWord;
			fout << word->GetForm() << " " << std::endl;
		}
		for (int i = 0; i < analysis->GetBilexemaWordsCount(); ++i) {
			fout << "	��������� " << analysis->GetBilexemaWords(i)->m_pBilexema->GetName() << ": \"";
			for (int j = 0; j < analysis->GetBilexemaWords(i)->m_CFWordVec.size(); ++j) {
				CaseFrameWords* cf_word = analysis->GetBilexemaWords(i)->m_CFWordVec[j];
				for (int l = 0; l < cf_word->m_WordVec.size(); ++l) {
					IWordBase* word = cf_word->m_WordVec[l]->m_pWord;
					if (word->GetPreText() != NULL) fout << word->GetPreText() << " ";
					fout << word->GetForm() << " ";
				}				
			}
			fout <<"\"" << std::endl;
			for (int j = 0; j < analysis->GetBilexemaWords(i)->m_CFWordVec.size(); ++j) {
				CaseFrameWords* cf_word = analysis->GetBilexemaWords(i)->m_CFWordVec[j];
				fout << "	������ " << cf_word->m_pCaseFrame->GetName() << ": " << std::endl;
				for (int l = 0; l < cf_word->m_WordVec.size(); ++l) {
					IWordBase* word = cf_word->m_WordVec[l]->m_pWord;
					IAktant* aktant = cf_word->m_WordVec[l]->m_pAktant;
					if (aktant == nullptr) fout << "		��������: ";
					else fout << "		Aktant " << aktant->GetName() << ": ";
					if (word->GetPreText() != NULL) fout << word->GetPreText() << " ";
					fout << word->GetForm() << std::endl;
				}
				fout << std::endl;
			}
		}
		delete analysis;
	}
	fout.close();
	return 0;
}

// 1. argv[1] - ��� ����� c ������� (��� ����������?)
// 2. argv[2] - ��� ����� c �������� (��� ����������?)
// 3. argv[3] - ���� �� ������� ����
// 4. argv[4] - ��� ����� ���������� (�� �����������)
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	if (argc < 4 || _access(argv[1], 0) || _access(argv[2], 0) || _access(argv[3], 0))
	{
		std::cout << "Argument is not correct." << std::endl;
		return 0;
	}
	char* textFile = argv[1];
	char* modelsFile = argv[2];
	char* vocFile = argv[3];
	char nameResult[] = "result.txt";
	char* outFile;
	if (argc > 4) outFile = argv[4];
	else outFile = nameResult;
	MainAnalysis(textFile, modelsFile, vocFile, outFile);
	return 0;
};