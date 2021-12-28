#pragma once
#include "GiaSuc.h"
class De :public GiaSuc
{
protected:
	float LuongSua;
public:
	De() {
		this->MaSo = "";
		this->CanNang = 0;
		this->Tuoi = 0;
		this->LuongSua = 0;
	}
	De(string maso, float cannang, int tuoi, float luongsua) {
		this->MaSo = maso;
		this->CanNang = cannang;
		this->Tuoi = tuoi;
		this->LuongSua = luongsua;
	}
	~De(){}
	void nhap() {
		GiaSuc::nhap();
	}
	void xuat() {
		GiaSuc::xuat();
	}
	float tinhLuongSua() {
		if (this->Tuoi >= 1 && this->Tuoi <=2)
		{
			this->LuongSua = this->CanNang / 10;
		}
		else if (this->Tuoi > 2 && this->Tuoi <= 4) {
			this->LuongSua = this->CanNang / 15;
		}
		else
		{
			this->LuongSua = 0;
		}
		return this->LuongSua;
	}
};

