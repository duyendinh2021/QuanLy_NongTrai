#include"NongTrai.h"
int main() {
	NongTrai* nt = new NongTrai();
	GiaSuc* gs = NULL;
	nt->nhap();
	nt->xuat();
	/*float suabo = nt->tinhTongLuongSuaBo();
	cout << "\nLuong sua Bo thu duoc:\t" << suabo;
	NongTrai TimTheoMs = nt->timMaSoGiaSuc();
	cout << "\nKet qua:";
	TimTheoMs.xuat();*/
	/*cout << "\nTim luong sua max:";
	float SuaMax = nt->timLuongSuaMax();
	cout << "\nLuong sua max:" << SuaMax;*/
	//NongTrai dsGiaSucSuaMax = nt->TimGiaSucCoLuongSuaMax();
	//dsGiaSucSuaMax.xuat();
	//bool timTheoMS = nt->timTheoMS(gs);
	//if (timTheoMS == true)
	//{
	//	cout << "\nTim Thay:";
	//	gs->xuat();
	//}
	//else if (timTheoMS == false)
	//{
	//	cout << "\nKhong Tim Thay:";
	//}
	//NongTrai TimTheoTuoi = nt->timTheoTuoi();
	//cout << "\nTim theo tuoi:";
	//TimTheoTuoi.xuat();
	/*NongTrai sapXepTheoLuongSua = nt->sapXepTheoLuongSua();
	cout << "\nSap xep theo Luong Sua:";
	sapXepTheoLuongSua.xuat();*/
	NongTrai SapXepTheoTuoi = nt->sapXepTheoTuoi();
	cout << "\nSap Xep theo Tuoi:";
	SapXepTheoTuoi.xuat();
	delete nt;
	return 0;
}