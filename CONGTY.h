#pragma once
#ifndef _CONGTY
#define _CONGTY
#include"NLDXS.h"
#include<fstream>
class CONGTY
{
private:
	NLDXS** pnldxs;
	int sl;
public:
	CONGTY();
	~CONGTY();
	int GetSL();
	void Nhap();
	void Xuat();
	NLDXS* Nhap1();
	void LietKeCQCoTu8KHCL();
	int DemCNCODCCToiDa();
	long TinhTongTienThuongNVCo5SKKNTroLen();
	double TinhDSPCLCTBCuaCNCODCCDuoi50();
	bool KiemTraCQChuaCoKHCL();
	void TimNVCoSKKNNhieuNhat();
	string DoiChuoiInHoa(string);
	string DoiChuoiInThuong(string);
	void SapXepMaSoTangDan();
	void TimNLDXSThuocBoPhan(string);
	void CapNhatThongTinTheoMaSo(string);
	void Them(NLDXS*, int);
	int Xoa(string);
	void GhiFile(string);
	void DocFile(string);
	void DocFileNLDXS(string);
	void GhiFileNLDXS(string);
};
#endif

