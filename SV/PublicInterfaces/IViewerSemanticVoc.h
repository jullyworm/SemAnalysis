// Файл интерфейса для семантического словарного компонента

#ifndef IViewerSemanticVocH
#define IViewerSemanticVocH

#include <vector>
#include "ICaseFrame.h"
#include "IWordBase.h"
#include "IAktant.h"
#include "IExternalVoc.h"

class IViewerSemanticVoc {
public:
	// Осуществляет быстрый поиск актанта используя согласованный внешний словарь терминов
	// aFirstWord, aSecondWord - проверяемые лексемы
	virtual IAktant* TestCaseFrame(IWordBase* aFirstWord, IWordBase* aSecondWord) const = 0;
	virtual IAktant* TestCaseFrame(IWordBase* pWord, ICaseFrame* pCaseFrame) = 0;

	virtual ICaseFrame* TestCaseFrame(std::vector <IWordBase*> aWords) const = 0;
	//virtual bool TestCaseFrame(std::vector <IWordBase*> aWords, const char* name_case_frame) const = 0;
	//virtual bool TestCaseFrame(IWordBase* aFirstWord, const char* name_un_case_frame) const = 0;

	// Проверяет семантические признаки у слова
	virtual bool TestSemProp(IWordBase* pWord, ISemanticFeature* pSemanticFeature) const = 0;
	// Проверяет морфологические признаки у слова
	virtual bool TestMorphProp(IWordBase* pWord, ISemanticFeature* pSemFeature) const = 0;
	// Проверяет принадлежность слова к модели управления
	virtual bool TestCaseFrame(IWordBase* pWord, ICaseFrame* pCaseFrame) const = 0;

	// Возвращает указатель на интерфейс модели управления для актанта
	virtual ICaseFrame* GetParentCaseFrame(IAktant* pAktant) const = 0;
	//Функция согласования
	virtual bool MorphCompare(IWordBase* aFirstWord, IWordBase* aSecondWord, const char* attr) = 0;
	// Добавляет данные из внешнего словаря
	virtual void AddFromExternalVoc(IExternalVoc* pExternalVoc) = 0;
	// Сохраняет словарь в файл
	virtual short SaveToFile(char* sFileName) const = 0;
	// Загружает словарь из файла
	virtual short LoadFromFile(char* sFileName) = 0;
	// Добавляет данные из файла в словарь
	virtual int AddFromFile(char* sFileName) = 0;
	//Загружает модели управления из текстового файла
	virtual void LoadFromTXT(char* sFileName) = 0;
	// Сохраняет модели управления в текстовый файл
	virtual void SaveToTXT(char* sFileName) const = 0;



	/*// Предоставялет доступ к модели управления по индексу в списке
	virtual ICaseFrame* GetCaseFrame(int Index) const = 0;
	// Удаляет модель управления по её индексу в списке
	virtual void DeleteCaseFrame(int Index) = 0;
	// Создаёт новый обеъкт модели управления в словаре
	virtual ICaseFrame* CreateCaseFrame() = 0;

	// Возвращает колличество моделей управления в словаре
	virtual int GetCaseFrameCount() const = 0;
	// Возвращает индекс модели управления
	virtual int FindCaseFrame(ICaseFrame* pCaseFrame) const = 0;
	// Предоставляет доступ к лексеме по её индексу в списке
	virtual ILexema* GetLexema(int Index) const = 0;
	// Удаляет лексему по её индексу в списке
	virtual void DeleteLexema(int Index) = 0;
	// Создаёт новый объект лексемы в словаре
	virtual ILexema* CreateLexema(char* sNormForm) = 0;
	// Возвращает колличество лексем в словаре
	virtual int GetLexemaCount() const = 0;
	// Ставит в соответствие лексеме модель упарвление
	virtual void AddCaseFrameToLexema(ICaseFrame* pCaseFrame, ILexema* pLexema) = 0;
	// Убирает соответствие модели управления и лексемы
	virtual void RemoveCaseFrameFromLexema(ILexema* pLexema, int CaseFrameIndex) = 0;
	// Проводит полную очистку словаря (удаляет лексемы, модели управления, отсальные данные выставляет по умолчанию)
	virtual void Clear() = 0;
	// Предоставляет доступ к таблице семантчиеских характеристик
	virtual ISemanticTable* GetSemanticTable() const = 0;
	// Предоставляет доступ к таблице грамматических характеристик
	virtual IGramTable* GetGramTable() const = 0;
	//Сохраняют таблицы атрибутов в файл по умолчанию
	// возвращаемое значение
	// 0 - ошибка при сохранении
	// 1 - операция прошла успешно
	virtual short SaveTables() = 0;
	//Возвращает индекс первой подходящей лексемы по её нормальной форме
	//Используется для быстрого поиска по части
	virtual int FindLexema(char* sNormForm) const = 0;
	// Возвращает индекс лексемы
	virtual int FindLexema(ILexema* pLexema) const = 0;
	//Возвращает индекс первой подходящей модели управления по её имени
	//Используется для быстрого поиска по части
	virtual int FindCaseFrame(char* sName) const = 0;*/
};

#endif
