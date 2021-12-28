#pragma once
#include "GiaSuc.h"
class Bo :public GiaSuc
{
protected:
	float LuongSua;
public:
	Bo() {
		this->MaSo = "";
		this->CanNang = 0;
		this->Tuoi = 0;
		this->LuongSua = 0;
	}
	Bo(string maso, float cannang, int tuoi, float luongsua) {
		this->MaSo = maso;
		this->CanNang = cannang;
		this->Tuoi = tuoi;
		this->LuongSua = luongsua;
	}
	~Bo(){}
	void nhap() {
		GiaSuc::nhap();
	}
	void xuat() {
		GiaSuc::xuat();
	}
	float tinhLuongSua() {
		if (this->Tuoi >= 2 && this->Tuoi <=5)
		{
			this->LuongSua = (this->CanNang - this->Tuoi) / 10;
		}
		else if (this->Tuoi < 2 || this->Tuoi > 5)
		{
			this->LuongSua = 0;
		}
		return this->LuongSua;
	}
};

