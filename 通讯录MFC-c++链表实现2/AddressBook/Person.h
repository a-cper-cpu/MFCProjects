// Person.h: interface for the CPerson class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__873A555F_8884_4E8F_9C9B_5F8D5AB6CB2A__INCLUDED_)
#define AFX_PERSON_H__873A555F_8884_4E8F_9C9B_5F8D5AB6CB2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPerson:public CObject  
{
public:
    DECLARE_SERIAL(CPerson) //对类进行串行化宏定义
	CPerson();
	virtual ~CPerson();
	CString m_Name;    //姓名
	CString m_Phone;   //电话
	CString m_Company; //公司
	CString m_Email;   //Email
public:
	virtual void Serialize(CArchive& ar);


};

#endif // !defined(AFX_PERSON_H__873A555F_8884_4E8F_9C9B_5F8D5AB6CB2A__INCLUDED_)
