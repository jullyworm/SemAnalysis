// Файл интерфейса для класса семантического аттрибута

#ifndef ISemanticAttrH
#define ISemanticAttrH

class ISemanticAttr {
public:
	// Возвращает значение семантического аттрибута
	virtual const char* GetSemanticAttrValue() const = 0;
};

#endif
