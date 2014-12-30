// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "Student.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudent::CStudent()
{
	this->m_pHead = NULL;
}

CStudent::~CStudent()
{
	
}
extern bool compareIdAndName(DATA d1,DATA d2);
bool compareId(DATA d1,DATA d2)
{
    return d1.id>d2.id;
}

bool compareScore(DATA d1,DATA d2)
{
    return d1.score>d2.score;
}

bool compareName(DATA d1,DATA d2)
{
    return strcmp(d1.name,d2.name);
}
void CStudent::addToHead(SNode *node)
{
	node->next = m_pHead;
    m_pHead = node;
}

void CStudent::addToTail(SNode *node)
{
	SNode * p = m_pHead;
	if(m_pHead==NULL){
		m_pHead = node;
	}else{
		while(p->next!=NULL){
			p=p->next;
		}
		p->next = node;
		node->next = NULL;
	}
}

void CStudent::save()
{
    FILE *fp = fopen("stu.txt","w+");
    if(fp!=NULL)
    {
        SNode *p = m_pHead;
        while(p!=NULL)
        {
            fprintf(fp,"%d %s %f\n",p->data.id,p->data.name,p->data.score);
            p=p->next;
        }
    }else
    {
        cout<<"open file stu.txt failed"<<endl;
    }
    fclose(fp);
}

void CStudent::load()
{
    FILE * fp = fopen("stu.txt","r");
    if(fp!=NULL)
    {
        SNode * node = new SNode;
        while(fscanf(fp,"%d %s %f\n",&node->data.id,node->data.name,&node->data.score)!=EOF)
        {
            node ->next = m_pHead;
            m_pHead = node;
            node = new SNode;
        }
    }else
    {
        cout<<"load failed for open stu.txt failed"<<endl;
    }
    fclose(fp);
}
    
SNode* CStudent::query(int id)
{
    SNode *p = m_pHead;
    while(p!=NULL)
    {
        if(p->data.id==id)
        {
            cout<<"find him"<<endl;
            cout<<"id:"<<p->data.id<<",name:"<<p->data.name<<",score:"<<p->data.score<<endl;
            return p;
        }
        p=p->next;
    }
    cout<<"not find"<<endl;
    return NULL;
}

SNode** CStudent::copyToArray()
{
   int count = 0;
   SNode *p = m_pHead;
   while(p!=NULL)
   {
        count++;
        p=p->next;
   }
   SNode ** list = new SNode*[count];
   p = m_pHead;
   int i=0;
   while(p!=NULL)
   {
        list[i++] = p;
        p = p->next;
   }
   return list;
}

void CStudent::sort(FP fp)
{
    SNode ** list = this->copyToArray();
    int count = this->getCount();
    if(count>0)
    {
        for(int i=0;i<count;i++)
        {
            for(int j=i;j<count;j++)
            {
                if((*fp)(list[j]->data,list[i]->data))
                {
                    DATA temp = list[j]->data;
                    list[j]->data = list[i]->data;
                    list[i]->data = temp;
                }
            }
        }
    }
    delete list;
}

int CStudent::getCount()
{
    int count = 0;
    SNode * p = m_pHead;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void CStudent::print()
{
	SNode *p=m_pHead;
	while(p!=NULL)
	{
		cout<<"id:"<<p->data.id<<",name:"<<p->data.name<<",score:"<<p->data.score<<endl;
        p=p->next;
	}
}

void CStudent::sortMenu()
{
    cout<<"1.sort by id"<<endl;
    cout<<"2.sort by name"<<endl;
    cout<<"3.sort by score"<<endl;
    cout<<"4.exit"<<endl;
    int c = 0;
    cin>>c;
    FP fp = NULL;
    while(c!=4)
    {
        switch(c)
        {
            case 1:
                fp = compareId;
                break;
            case 2:
                fp = compareName;
                break;
            case 3:
                fp = compareScore;
                break;
        }
        this->sort(fp);
        this->print();
        cout<<"1.sort by id"<<endl;
        cout<<"2.sort by name"<<endl;
        cout<<"3.sort by score"<<endl;
        cout<<"4.exit"<<endl;
        cin>>c;
    }
}

void CStudent::input()
{	
	cout<<"1.insert into head"<<endl;
	cout<<"2.insert into tail"<<endl;
	cout<<"3.exit"<<endl;
	int c;
	cin>>c;
	SNode *node = NULL;
	DATA data;
	while(c!=3)
	{
		switch(c)
		{
		case 1:
			cout<<"please input student's id name score"<<endl;
			scanf("%d %s %f",&data.id,data.name,&data.score);
			getchar();
			node = new SNode;
			node->data = data;
			node->next = NULL;
			this->addToHead(node);
			break;
		case 2:
			cout<<"please input student's id name score"<<endl;
			scanf("%d%s%f",&data.id,data.name,&data.score);
			getchar();
			node = new SNode;
			node->data = data;
			node->next = NULL;
			this->addToTail(node);
			break;
		case 3:
			break;
		default:
			break;
		}
		cout<<"1.insert into head"<<endl;
		cout<<"2.insert into tail"<<endl;
		cout<<"3.exit"<<endl;
		cin>>c;
	}
	
}

void CStudent::menu()
{
	cout<<"1.input student"<<endl;
	cout<<"2.browse"<<endl;
	cout<<"3.save"<<endl;
    cout<<"4.query"<<endl;
    cout<<"5.sort"<<endl;
	cout<<"0.exit"<<endl;
	int c;
	cin>>c;
    this->load();
	while(c!=0)
	{
		switch(c)
		{
		case 1:
			this->input();
			break;
		case 2:
			this->print();
			break;
		case 3:
            this->save();
			break;
		case 4:
            int id;
            cout<<"please input the id:"<<endl;
            cin>>id;
            this->query(id);
			break;
        case 5:
            sortMenu();
            break;
		}
		cout<<"1.input student"<<endl;
		cout<<"2.browse"<<endl;
		cout<<"3.save"<<endl;
		cout<<"4.query"<<endl;
        cout<<"5.sort"<<endl;
		cout<<"0.exit"<<endl;
		cin>>c;
	}
}
