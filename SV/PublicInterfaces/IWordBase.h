#ifndef IWordBaseH
#define IWordBaseH

class IWordBase {
public:
	//Получить используемую форму
	virtual const char* GetForm() const = 0;
	// Функции характеризует лексему
	//-----------------------------------------------------------
	// Получить нормальную форму лексемы
	virtual const char* GetWordNormalForm() const = 0;
	// Возвращает колличество лексических характеристик лексемы (ЧР, имя собств. и т.д.)
	virtual int GetLexikalFeatureCount() const = 0;
	// Возвращает имя конкретной лексической характеристики
	virtual const char* GetLexikalFeatureName(int Index) const = 0;
	// Возвращает значение конкретной лексической характеристики
	virtual const char* GetLexikalFeatureValue(int Index) const = 0;
	//-----------------------------------------------------------
	// Функции возвращают значения для конкретной словоформы
	// Возвращает колличество семантических характеристик
	virtual int GetSemanticFeatureCount() const = 0;
	// Возвращает конкретную семантическую характеристику
	virtual const char* GetSemanticFeature(int Index) const = 0;
	// Возвращает колличество групп морфологических характеристик
	virtual int GetMorphFeatureGroupCount() const = 0;
	// Возвращает колличество морфологических характеристик
	virtual int GetMorphFeatureCount(int uGroupIndex) const = 0;
	// Возвращает имя морфологической характеристики
	virtual const char* GetMorphFeatureName(int uGroupIndex, int Index) const = 0;
	// Возвращает значение морфологической характеристики
	virtual const char* GetMorphFeatureValue(int uGroupIndex, int Index) const = 0;
	// Возвращает часть речи
	virtual const char* GetPartOfSpeech() const = 0;
	// Поиск предлога
	virtual const char* FindPretext() = 0;
	// Возвращает предлог
	virtual const char* GetPreText() const = 0;
	virtual void SetPreText(char* sPretext) = 0;
};

#endif
