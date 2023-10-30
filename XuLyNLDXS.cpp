#include"NLDXS.h"
NLDXS::NLDXS (string ms, string ht, string bp) : maso(ms), hoten(ht), bophan(bp) {}
string NLDXS::GetMaSo() 
{ 
	return maso; 
}
string NLDXS::GetHoTen()
{
	return hoten;
}
string NLDXS::GetBoPhan()
{
	return bophan;
}
void NLDXS::SetHoTen(string ht)
{
	hoten = ht;
}
void NLDXS::SetBoPhan(string bp)
{
	bophan = bp;
}
//cac ham ao
int NLDXS::GetSoKHCL()
{
	return -1;
}
double NLDXS::GetDSPCLCTB()
{
	return -1;
}
double NLDXS::GetDCC()
{
	return -1;
}
int NLDXS::GetSoSK()
{
	return -1;
}
void NLDXS::SetSoKHCL(int khcl)
{
	return;
}
void NLDXS::SetDSPCLCTB(double dspclctb)
{
	return;
}
void NLDXS::SetDCC(double cc)
{
	return;
}
void NLDXS::SetSoSK(int sk)
{
	return;
}
void NLDXS::Nhap()
{
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maso);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap bo phan: ";
	getline(cin, bophan);
}
void NLDXS::Xuat()
{
	cout << "MS: " << maso << "\tTen: " << hoten << "\tBo phan: " << bophan;
}
