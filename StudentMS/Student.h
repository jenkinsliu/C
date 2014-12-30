// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__A56709F7_F63D_42ED_A925_4F49D1CE6EA3__INCLUDED_)
#define AFX_STUDENT_H__A56709F7_F63D_42ED_A925_4F49D1CE6EA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



struct SStu
{
	int id;
	char name[10];
	float score;
};

typedef struct SStu DATA;

struct SNode
{
	DATA data;
	SNode * next;
};

typedef bool(*FP)(DATA d1,DATA d2);


class CStudent  
{
private:
	SNode *m_pHead;
	int m_iCount;
public:
	void menu();
	void input();
	void print();
	void addToTail(SNode *node);
	void addToHead(SNode *node);
    void save();
    void load();
    void sort(FP fp);
    int getCount();
    void sortMenu();
    SNode ** copyToArray();
    SNode *query(int id);
	CStudent();
	virtual ~CStudent();

};

#endif // !defined(AFX_STUDENT_H__A56709F7_F63D_42ED_A925_4F49D1CE6EA3__INCLUDED_)
