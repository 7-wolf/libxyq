#include "Wdf.h"


#pragma pack (push)
#pragma pack (1)
struct TGAFILEHEADER{
	uchar bIDLength;						//������Ϣ����
	uchar bPalType;						//��ɫ����Ϣ(��֧��)
	uchar bImageType;					//ͼ������(ֻ֧�� 2,10)
	ushort wPalIndex;						//��ɫ���һ������ֵ
	ushort wPalLength;					//��ɫ��������
	uchar bPalBits;						//һ����ɫ�嵥λλ��(15,16,24,32)
	ushort wLeft;							//ͼ���������(��������)
	ushort wBottom;						//ͼ��׶�����(��������)
	ushort wWidth;						//ͼ����
	ushort wHeight;						//ͼ��߶�
	uchar bBits;							//һ������λ��
	uchar bAlphaBits : 4;					//Alphaλ��
	uchar bReserved : 1;					//����,����Ϊ0
	uchar bTopDown : 1;					//Ϊ1��ʾ���ϵ���(ֻ֧�ִ��µ���)
	uchar bInterleaving : 2;				//����(һ��Ϊ0)
};
#pragma pack (pop)

void WPixel::operator=(ushort color)
{
	blue = color & 0x1f;
	green = (color >> 5 & 0x1f) << 1;
	if (green)green += 1;
	red = color >> 10 & 0x1f;
}
void WPixel::operator=(ulong color1)
{
	red = color1 >> 3 & 0x1f;
	green = (color1 >> 11 & 0x1f) << 1;
	if (green)green += 1;
	blue = color1 >> 19 & 0x1f;
}

bool CWdf::Open(const char* FileName)
{
// 	static WdfReader r;
// 	r.clear();
// 	r.load(FileName);
// 	if (r.getWdfs().empty())
// 	{
// 		return false;
// 	}
	m_File.open(FileName, ios::binary);
	if (!m_File)
	{
// 		MessageBoxA(/*g_hWnd*/nullptr, "û���ҵ��ļ�", "", MB_OK);
// 		assert(0);
		ccc_log("û���ҵ�WDF�ļ�:%s", FileName);
		return false;
	}
// 	const auto& wdf = r.getWdfs().front();
// 	m_pIndex = new WDataFileIndex[m_Number = wdf.indexsCount];
// 	memcpy(m_pIndex, wdf.indexs, m_Number * sizeof(WDataFileIndex));
// 	return true;

	//��ȡ�ļ�ͷ
	WDataFileHeader header;
	m_File.read((char*)&header, sizeof(header));

	//ȷ����WDF�ļ�
	if (header.id != 'WDFP')
	{
		m_File.close();
		//		MessageBoxA(g_hWnd, "��Ч��WDF�ļ�", "", MB_OK);
		ccc_log("��Ч��WDF�ļ�:%s", FileName);
		return false;
	}
	//�������ļ��б�
	m_pIndex = new WDataFileIndex[header.number];
	m_File.seekg(header.offset, ios_base::beg);
	int size = sizeof(ulong);
	for (int i = 0; i < header.number; i++)
	{
		m_File.read((char*)&m_pIndex[i].uid, size);
		m_File.read((char*)&m_pIndex[i].offset, size);
		m_File.read((char*)&m_pIndex[i].size, size);
		m_File.read((char*)&m_pIndex[i].space, size);
	}
	m_Number = header.number;
	return true;
}



bool CWdf::Free()
{
	SAFE_DELETE_ARRAY(m_pIndex);
	return true;
}


