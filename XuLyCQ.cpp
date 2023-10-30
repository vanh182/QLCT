#include"CQ.h"
CQ::CQ(string ms, string ht, string bp, int khcl) :NLDXS(ms, ht, bp), sokhcl(khcl){};
int CQ::GetSoKHCL() {
	return sokhcl;
}
void CQ::SetSoKHCL(int khcl) {
	while (khcl < 0)
	{
		cout << "Nhap so khcl: ";
		cin >> khcl;
	}
	sokhcl = khcl;
}
void CQ::Nhap() {
	NLDXS::Nhap();
	do {
		cout << "Nhap so khcl: ";
		cin >> this->sokhcl;
	} while (sokhcl < 0);
}
void CQ::Xuat() {
	NLDXS::Xuat();
	cout << "\tLoai: CQ\tSoKHCL: " << sokhcl << "\tTien thuong: " << TinhTienThuong() << endl;
}
long CQ::TinhTienThuong() {
	long thuong, them;
	thuong = sokhcl * 50000000;
	them = (sokhcl >= 8 ? 30000000 : (sokhcl >= 5 ? 20000000 : 0));
	return thuong + them;
}
string CQ::GetLoai() {
	return "CQ";
}