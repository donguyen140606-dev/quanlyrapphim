//quan ly doanh thu theo ngay,thang va so ve ban ra
#include<iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const double luongTheoGio = 30000.0;
const int gioMotCa = 6;


class QuanLyDoanhThu{
    public:
        int ngay, thang, veNgay, veThang, giaVe; 
        double doanhThuNgay, doanhThuThang; 
        void nhap();
        void tinhToan();
        void xuat();
};

void QuanLyDoanhThu::nhap(){
    cout << "--- NHAP THONG TIN VE BAN ---" << endl;
    cout <<"Nhap gia ve: ";
    cin >> giaVe;
    cout <<"Nhap ngay: ";
    cin >> ngay;
    cout <<"Nhap so ve ban ra trong ngay " << ngay << ": ";
    cin >> veNgay;
    cout <<"Nhap thang: ";
    cin >> thang;
    cout <<"Nhap so ve ban ra trong thang " << thang << ": ";
    cin >> veThang;
}

void QuanLyDoanhThu::tinhToan(){
    doanhThuNgay = (double)veNgay * giaVe;
    doanhThuThang = (double)veThang * giaVe;
}

void QuanLyDoanhThu::xuat(){
    cout << fixed << setprecision(0);
    cout << "\n**THONG KE TRONG NGAY**" << endl;
    cout << "So ve ban ra trong ngay "<< ngay <<": " << veNgay << " ve" << endl;
    cout << "Doanh thu trong ngay: " << doanhThuNgay << " VND" << endl;
    cout << "\n**THONG KE TRONG THANG**" << endl;
    cout << "Tong so ve da ban ra trong thang " << thang << ": " << veThang << " ve" << endl;
    cout << "Tong doanh thu cua thang: " << doanhThuThang << " VND" << endl;
}

class QuanLyNhanSu{
      public:
          string ten;
          string id;
          string gioiTinh;
          int soCaLam;
          double tongLuong;
    void nhap();
    void tinhToan();
    void xuat();
};

void QuanLyNhanSu::nhap(){
    cout << "\n--- NHAP THONG TIN NHAN VIEN ---" << endl; 
    cout << "Nhap ten nhan vien: ";
    getline(cin, ten);    

    cout << "Nhap ID nhan vien: ";
    getline(cin, id);

    cout << "Nhap gioi tinh (Nam/Nu): ";
    getline(cin, gioiTinh);

    cout << "Nhap so ca lam viec trong thang : ";
    cin >> soCaLam; 
}

void QuanLyNhanSu::tinhToan(){
    int soGioLam = soCaLam * gioMotCa;
    tongLuong = soGioLam * luongTheoGio;
}

 void QuanLyNhanSu::xuat(){
    cout << fixed << setprecision(0);
        cout << "\n--- KET QUA TINH LUONG NHAN VIEN ---" << endl;
        cout << "Ten nhan vien: " << ten << endl;
        cout << "ID nhan vien: " << id << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "So ca lam viec: " << soCaLam << " ca" << endl;
        cout << "Tong so gio lam: " << soCaLam * gioMotCa << " gio" << endl; 
        cout << "Tien luong nhan vien " << ten << " nhan duoc : " << tongLuong << " VND" << endl;
 }

int main(){
    QuanLyDoanhThu dt;
    QuanLyNhanSu ns;
    
    dt.nhap();
    dt.tinhToan();
    dt.xuat();
    
    cout << "\n----------------------------------------\n";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    ns.nhap();
    ns.tinhToan();
    ns.xuat();
    
    return 0;
}
