// PackMessg.h: interface for the CPackMessg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKMESSG_H__DF511BFD_1563_412D_85B5_EF323A3074EF__INCLUDED_)
#define AFX_PACKMESSG_H__DF511BFD_1563_412D_85B5_EF323A3074EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPackMessg :public CObject
{

public:
	CString m_strText;

public:

	CPackMessg();
	virtual ~CPackMessg(){};
	
	//��ʼ����Ա�����ĺ���
	void Init();
	//���ش��л��ĺ���,ʵ�ֽ���Ϣ���л�
	virtual void Serialize(CArchive& ar);   

};

#endif // !defined(AFX_PACKMESSG_H__DF511BFD_1563_412D_85B5_EF323A3074EF__INCLUDED_)
