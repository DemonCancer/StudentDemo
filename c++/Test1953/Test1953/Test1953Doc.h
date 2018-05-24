
// Test1953Doc.h : CTest1953Doc 类的接口
//


#pragma once


class CTest1953Doc : public CDocument
{
protected: // 仅从序列化创建
	CTest1953Doc();
	DECLARE_DYNCREATE(CTest1953Doc)

// 特性
public:

// 操作
public:
////////////////////////////////////////////
public:
	CPtrList m_List;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CTest1953Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
};
