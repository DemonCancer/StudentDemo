
// Test1953Doc.h : CTest1953Doc ��Ľӿ�
//


#pragma once


class CTest1953Doc : public CDocument
{
protected: // �������л�����
	CTest1953Doc();
	DECLARE_DYNCREATE(CTest1953Doc)

// ����
public:

// ����
public:
////////////////////////////////////////////
public:
	CPtrList m_List;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CTest1953Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
};
