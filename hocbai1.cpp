#include<iostream>
using namespace std;
class DoanhThu{
    public:
        int ngay, thang;
        void nhap();
        void xuat();
};
void DoanhThu::nhap(){
	cout <<"Nhap doanh thu theo ngay: ";
	cin >> ngay;
	cout <<"Nhap doanh thu theo thang: ";
	cin >> thang;
}
void DoanhThu::xuat(){
    cout <<"Doanh thu theo ngay: " << ngay << endl;
    cout <<"Doanh thu theo thang: " << thang << endl;
}
class TongSoVeBanRa{
	 public:
        int ve;
        void nhap();
        void xuat();
};
void TongSoVeBanRa::nhap(){
	cout <<"Nhap so ve ban ra: ";
	cin >> ve;
}
void TongSoVeBanRa::xuat(){
    cout <<"tong so ve ban ra " << ve << endl;
}
int main(){
	DoanhThu dt;
	TongSoVeBanRa v;
	dt.nhap();
	dt.xuat();
	v.nhap();
	v.xuat();
	return 0;
}