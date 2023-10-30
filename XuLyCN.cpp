#include"CN.h"
CN::CN(string ms, string ht, string bp, double spclctb, double cc) 
	: NLDXS(ms, ht, bp), dspclctb(spclctb), dcc(cc) {}
double CN::GetDSPCLCTB() {
	return dspclctb;
}
double CN::GetDCC() {
	return dcc;
}
void CN::SetDSPCLCTB(double spclctb) {
	while (spclctb < 0 || spclctb>10)
	{
		cout << "Nhap diem spclc trung binh: ";
		cin >> spclctb;
	}
	dspclctb = spclctb;
}
void CN::SetDCC(double cc) {
	while (cc < 0 || cc>100)
	{
		cout << "Nhap diem chuyen can: ";
		cin >> cc;
	}
	dcc = cc;
}
void CN::Nhap() {
	NLDXS::Nhap();
	do
	{
		cout << "Nhap diem spclc trung binh: ";
		cin >> this->dspclctb;
	} while (dspclctb < 0 || dspclctb>10);
	do
	{
		cout << "Nhap diem chuyen can: ";
		cin >> this->dcc;
	} while (dcc < 0 || dcc>100);
}
void CN::Xuat() {
	NLDXS::Xuat();
	cout << "";
	cout << "\tLoai: CN\tDSPCLCTB: " << dspclctb << "\tDCC: " 
		<< dcc << "\t" << "\tTien thuong: " << TinhTienThuong() << endl;
}
long CN::TinhTienThuong() {
	long thuong = 0;
	if (dcc >= 90)
		thuong = (dspclctb > 9 ? 2500000 : (dspclctb >= 8.5 ? 1500000 : 0));
	return thuong;
}
string CN::GetLoai() {
	return "CN";
}