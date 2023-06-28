// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Usage notes: ������ (������) ���������� �� ������
//===================================================================
// ������������ : 
//===================================================================
// ����������   : <mem.h>
//===================================================================
// Oct 2002                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef KNPointerVectorHPP
#define KNPointerVectorHPP
//---------------------------------------------------------------------------
#include <string.h>
//#include <string.h>
//---------------------------------------------------------------------------
/** ������ (������) ���������� �� ������ */
template <class T > class KNPointerVector{
public:
    T* *list;
    unsigned Max, Count;
public:
    KNPointerVector( unsigned iMax=50 );
    KNPointerVector( const KNPointerVector& );
    ~KNPointerVector();
public:
//    void Add( T& );
//    void Insert( T&,unsigned );
    void Add( T* );
    void Insert( T*,unsigned );

    unsigned GetIndex( T* );
   
    // Flag=0 - ��� ������� ������ ���������, 1 - ������� ������
    void Release( int Flag=1 );
    // Flag=0 - ������ �������, 1 - ���������� ������� �� ������
    void Delete( unsigned, int Flag=1 );
    // C ��������� �� Count
    T* At(unsigned) const;
    // ��� ��������� = operator[]
    T* At_(unsigned) const;
    // ��� ��������� �� Count
    // (0 is the first index)
    T*& operator[](unsigned);
    T* operator[](unsigned) const;
//    T*& operator[](unsigned);
//    T* operator[](unsigned) const;
    bool operator==(KNPointerVector&) const;
    unsigned Size() {return Count;}
    // �������� �������
    void Move(unsigned, unsigned);
    // ��������������� �������������� �����
    void ReservePlus(unsigned);
private:
    void CopyPlus();
};

typedef KNPointerVector <unsigned> KNList;

        // =====================================
        // Implementation of templates functions
        // =====================================
template <class T >
KNPointerVector<T>::KNPointerVector(unsigned iMax) {
    Count=0;
    Max = iMax ? iMax:1;
    list=new (T*[Max]);
}

template <class T >
KNPointerVector<T>::KNPointerVector(const KNPointerVector& st){
    Count = st.Count;
    Max = st.Max;
    list = new (T*[Max]);
    memcpy(list, st.list, sizeof(T*)*Count);
}

template <class T >
KNPointerVector<T>::~KNPointerVector(){
    delete [] list;
}

template <class T >
void KNPointerVector<T>::CopyPlus(){
    Max*=2;
    T**body = new (T*[Max]);
    memcpy(body, list, sizeof(T*)*Count);
    delete [] list;
    list = body;
}

template <class T >
void KNPointerVector<T>::ReservePlus(unsigned delta){
//    if(!delta) return;
    Max+=delta;
    T**body = new (T*[Max]);
    memcpy(body, list, sizeof(T*)*Count);
    delete [] list;
    list = body;
}
/*
template <class T >
void KNPointerVector<T>::Add(T& x){
	if (Count>=Max) CopyPlus();
	list[Count++] = &x;
} //*/

template <class T >
void KNPointerVector<T>::Move(unsigned n1, unsigned n2)
{
//    if(Count<=n1 || Count<=n2) return;
//	try {
    T* x = list[n1];
    list[n1] = list[n2];
    list[n2] = x;
//	} catch(...){}
}

template <class T >
void KNPointerVector<T>::Add(T* x){
//    if (!x) return;
    if (Count>=Max) CopyPlus();
    list[Count++] = x;
}
/*
template <class T >
void KNPointerVector<T>::Insert(T& x,unsigned n){
//    if (n>Count) return;
//  if (Count>=Max) CopyPlus(); // �� ����������
    if (Count == Max) // CopyPlus()
    {
        Max*=2; T**body = new (T*[Max]);
        if( n ) memcpy(body, list, sizeof(T*)*n);
        body[n] = &x;
        if( Count-n ) memmove(body+n+1, list+n, sizeof(T*)*(Count-n));
        delete [] list;
        list = body;
        Count++;
        return;
    }
    if( Count-n ) memmove(list+n+1, list+n, sizeof(T*)*(Count-n));
    Count++;
    list[n] = &x;
} //*/

template <class T >
void KNPointerVector<T>::Insert(T* x,unsigned n){
//    if (!x) return;
//    if (n>Count) return;
//    if (Count>=Max) CopyPlus(); // �� ����������
//    if( Count-n )
//        memmove(list+n+1, list+n, sizeof(T*)*(Count-n));
    if (Count == Max) // CopyPlus()
    {
        Max*=2; T**body = new (T*[Max]);
        if( n ) memcpy(body, list, sizeof(T*)*n);
        body[n] = x;
        if( Count-n ) memmove(body+n+1, list+n, sizeof(T*)*(Count-n));
        delete [] list;
        list = body;
        Count++;
        return;
    }
    if( Count-n ) memmove(list+n+1, list+n, sizeof(T*)*(Count-n));
    Count++;
    list[n] = x;
}

template <class T >
unsigned KNPointerVector<T>::GetIndex(T* x){
	for(unsigned i=0; i<Count; i++)
		if( list[i] == x ) return i;
    return Count;
}

template <class T >
void KNPointerVector<T>::Release(int Flag){
    if( !Flag )
        for(unsigned i=0; i<Count; i++)
            delete list[i];
//      delete [] list;
    Count=0;
}

template <class T >
void KNPointerVector<T>::Delete(unsigned n, int Flag){
//    if (n>=Count) return;
    if (!Flag) delete list[n];
    if( Count-n-1 )
        memmove(list+n, list+n+1, sizeof(T*)*(Count-n-1));
    Count--;
}

template <class T >
T* KNPointerVector<T>::At(unsigned n) const{
	return n<Count ? list[n] : 0;
//	try { return list[n]; }
//	catch (...) {return 0;}
} //*/

template <class T >
T* KNPointerVector<T>::At_(unsigned n) const{
    return list[n];
}

template <class T >
T*& KNPointerVector<T>::operator[](unsigned n) {
    return list[n];
}

template <class T >
T* KNPointerVector<T>::operator[](unsigned n) const {
    return list[n];
}

template <class T >
bool KNPointerVector<T>::operator==(KNPointerVector<T> &Pr) const{
    if (Count != Pr.Count) return 0;
    return !memcmp(list, Pr.list, sizeof(T*)*Count);
}

//---------------------------------------------------------------------------
#endif
