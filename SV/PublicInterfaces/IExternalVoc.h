#ifndef IExternalVocH
#define IExternalVocH

class IExternalVoc {
public:
	// ”становка активной первой лексемы
	virtual void Init() = 0;
	// —делать активной следующую лексему
	virtual void SetNextLexemaActive() = 0;
	// ¬озвращает кол-во лексических терминов во внешнем словаре
	virtual int GetLexemaCount() const = 0;
	// ¬озвращает нормальную форму лексемы
	virtual const char* GetLexemaNormForm() const = 0;
	// ¬озвращает им€ части речи лексемы
	virtual const char* GetLexemaPartOfSpeach() const = 0;
	// ¬озвращает кол-во лексических признаков у лексемы
	virtual int GetLexemaLexikalFeatureCount() const = 0;
	// ¬озвращает им€ лекс. признака дл€ конкретной лексемы
	virtual const char* GetLexemaLexikalFeatureName(int uFeatureIndex) const = 0;
	// ¬озвращает значение лексического признака конкретной лексемы
	virtual const char* GetLexemaLexikalFeatureValue(int FeatureIndex) const = 0;
	// ¬озвращает кол-во грамматических характеристик
	virtual int GetGramFeatureCount() const = 0;
	// ¬озвращает им€ грам. х-ки
	virtual const char* GetGramFeatureName(int Index) const = 0;
	// ¬озвращает кол-во значений грам. х-ки
	virtual int GetGramFeatureValueCount(int Index) const = 0;
	// ¬озвращает конкретное значение дл€ грам. х-ки
	virtual const char* GetGramFeatureValue(int uFeatureIndex, int uValueIndex) const = 0;
	// ¬озвращает колличество семантических атрибутов
	virtual int GetSemAttrCount() const = 0;
	// ¬озвращает значение дл€ семантического атрибута
	virtual const char* GetSemAttrValue(int Index) const = 0;
	// ¬озвращает колличество частей речи во внешнем словаре
	virtual int GetPartOfSpeachCount() const = 0;
	// ¬озвращает часть им€ части речи внешнего словар€
	virtual const char* GetPartOfSpeach(int Index) const = 0;
};

#endif
