#include"NongTrai.h"
int main() {
	NongTrai* nt = new NongTrai();

	nt->nhap();
	nt->xuat();
	float suabo = nt->tinhTongLuongSuaBo();
	cout << "\nLuong sua Bo thu duoc:\t" << suabo;
	return 0;
}