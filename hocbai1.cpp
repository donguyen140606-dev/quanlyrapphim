#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double LUONG_THEO_GIO = 30000.0;
const int GIO_MOT_CA = 6;
const double GIA_VE_TB = 100000.0;

class NhanVien {
public:
    string hoTen;
    int caLam;
    double tongLuong;
    
    void nhap();
    void tinhLuong();
    void xuat() const;
};

void NhanVien::nhap() {
    cin.ignore();
    cout << "\nNhap Ho Ten: ";
    getline(cin, hoTen);
    cout << "So ca lam viec trong thang: ";
    cin >> caLam;
}

void NhanVien::tinhLuong() {
    int soGioLam = caLam * GIO_MOT_CA;
    tongLuong = soGioLam * LUONG_THEO_GIO;
}

void NhanVien::xuat() const {
    cout << "----------------------------------------" << endl;
    cout << "Ho Ten        : " << hoTen << endl;
    cout << "Ca lam        : " << caLam << endl;
    cout << "Tong luong    : " << fixed << setprecision(0) << tongLuong << " VND" << endl;
    cout << "----------------------------------------" << endl;
}

struct NodeNV {
    NhanVien data;
    NodeNV* next;
};

class ListNhanVien {
public:
    NodeNV* head;
    NodeNV* tail;

    ListNhanVien() : head(NULL), tail(NULL) {}

    ~ListNhanVien() {
        NodeNV* current = head;
        while (current != NULL) {
            NodeNV* next = current->next;
            delete current;
            current = next;
        }
        head = tail = NULL;
    }

    void addNV(NhanVien nv) {
        nv.tinhLuong();
        NodeNV* p = new NodeNV{nv, NULL};
        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void show() const {
        if (head == NULL) {
            cout << "Chua co du lieu nhan vien nao!\n";
            return;
        }
        cout << "\n========= DANH SACH LUONG NHAN VIEN =========" << endl;
        for (NodeNV* i = head; i != NULL; i = i->next) {
            i->data.xuat();
        }
    }
    
    double tinhTongLuong() const {
        double tong = 0;
        for (NodeNV* i = head; i != NULL; i = i->next) {
            tong += i->data.tongLuong;
        }
        return tong;
    }
    
    bool isEmpty() const { return head == NULL; }
};

struct DoanhThuNgay {
    string ngayThang;
    int soVeBanRa;
    double doanhThu;

    void nhap();
    void tinhDoanhThu();
    void xuat() const;
};

void DoanhThuNgay::nhap() {
    cin.ignore();
    cout << "Nhap thang (VD: 1-12): ";
    getline(cin, ngayThang);
    cout << "Nhap so ve ban ra: ";
    cin >> soVeBanRa;
}

void DoanhThuNgay::tinhDoanhThu() {
    doanhThu = soVeBanRa * GIA_VE_TB;
}

void DoanhThuNgay::xuat() const { 
    cout << setw(10) << ngayThang
         << setw(20) << soVeBanRa
         << setw(25) << fixed << setprecision(0) << doanhThu << " VND" << endl;
}

struct NodeDT {
    DoanhThuNgay data;
    NodeDT* next;
};

class ListDoanhThu {
public:
    NodeDT* head;
    NodeDT* tail;
    
    ListDoanhThu() : head(NULL), tail(NULL) {}

    ~ListDoanhThu() {
        NodeDT* current = head;
        while (current != NULL) {
            NodeDT* next = current->next;
            delete current;
            current = next;
        }
        head = tail = NULL;
    }

    void addDT(DoanhThuNgay dt) {
        dt.tinhDoanhThu();
        NodeDT* p = new NodeDT{dt, NULL};
        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void show() const {
        if (head == NULL) {
            cout << "Chua co du lieu doanh thu thang nao!\n";
            return;
        }
        cout << "\n====== CHI TIET DOANH THU THEO THANG ======\n";
        cout << setw(10) << "THANG" << setw(20) << "SO VE BAN RA" << setw(25) << "DOANH THU\n";
        cout << string(55, '-') << endl;
        for (NodeDT* i = head; i != NULL; i = i->next) {
            i->data.xuat();
        }
        cout << string(55, '-') << endl;
    }

    double tinhTongDoanhThu() const {
        double tong = 0;
        for (NodeDT* i = head; i != NULL; i = i->next) {
            tong += i->data.doanhThu;
        }
        return tong;
    }

    bool isEmpty() const { return head == NULL; }
};


class QuanLyHeThong {
public:

    ListNhanVien dsNhanVien;
    ListDoanhThu dsDoanhThu; 
    
    double tongDoanhThuVe;
    double tongChiPhiNhanVien;
    double loiNhuan;
    
    QuanLyHeThong();

    void nhapNhanVien();
    void xemLuongNhanVien();

    void nhapDoanhThuNgay();
    void xemDanhSachDoanhThu();
    
    void tinhLoiNhuan();
    void xuatBaoCao();
};

void menuQuanLyNV(QuanLyHeThong& heThong);
void menuQuanLyDoanhThu(QuanLyHeThong& heThong);

QuanLyHeThong::QuanLyHeThong() : tongDoanhThuVe(0), tongChiPhiNhanVien(0), loiNhuan(0) {}

void QuanLyHeThong::nhapNhanVien() {
    NhanVien nv;
    cout << "\n--- THEM NHAN VIEN VA TINH LUONG ---\n";
    nv.nhap();
    dsNhanVien.addNV(nv); 
    cout << "Da them va tinh luong thanh cong!\n";
}

void QuanLyHeThong::xemLuongNhanVien() {
    dsNhanVien.show();
}

void QuanLyHeThong::nhapDoanhThuNgay() {
    DoanhThuNgay dt;
    cout << "\n--- THEM MUC DOANH THU THANG ---\n";
    dt.nhap();
    dsDoanhThu.addDT(dt); 
    cout << "Da them doanh thu thang thanh cong!\n";
}

void QuanLyHeThong::xemDanhSachDoanhThu() {
    dsDoanhThu.show();
    
    if (!dsDoanhThu.isEmpty()) {
        tongDoanhThuVe = dsDoanhThu.tinhTongDoanhThu();
        cout << "TONG DOANH THU VE: " << fixed << setprecision(0) << tongDoanhThuVe << " VND\n";
        cout << "===========================================\n";
    }
}

void QuanLyHeThong::tinhLoiNhuan() {
    tongDoanhThuVe = dsDoanhThu.tinhTongDoanhThu(); 
    tongChiPhiNhanVien = dsNhanVien.tinhTongLuong(); 
    loiNhuan = tongDoanhThuVe - tongChiPhiNhanVien;
}

void QuanLyHeThong::xuatBaoCao() {
    tinhLoiNhuan(); 
    
    cout << "\n";
    cout << "============================================\n";
    cout << "      BAO CAO TONG QUAN RAP PHIM          \n";
    cout << "============================================\n";
    cout << fixed << setprecision(0);
    
    cout << "\n**DOANH THU BAN VE**\n";
    cout << "Tong doanh thu tu ban ve: " << tongDoanhThuVe << " VND\n"; 
    
    cout << "\n**CHI PHI NHAN SU**\n";
    cout << "Tong luong nhan vien: " << tongChiPhiNhanVien << " VND\n";
    
    cout << "\n**LOI NHUAN (DOANH THU - LUONG NV)**\n";
    cout << "Loi nhuan = " << loiNhuan << " VND\n"; 
    
    if (loiNhuan > 0) {
        cout << "\n=> Rap dang SINH LOI! \n";
    } else if (loiNhuan < 0) {
        cout << "\n=> Rap dang LO! \n";
    } else {
        cout << "\n=> Rap HOA VON.\n";
    }
    cout << "============================================\n";
}

void menuQuanLyNV(QuanLyHeThong& heThong) {
    int nvChoice;
    do {
        cout << "\n===== TINH LUONG NHAN VIEN =====\n";
        cout << "1. Them nhan vien va tinh luong\n";
        cout << "2. Xem danh sach luong nhan vien\n";
        cout << "0. Quay lai\n";
        cout << "==============================\n";
        cout << "Nhap lua chon: ";
        cin >> nvChoice;

        if (nvChoice == 1) {
            heThong.nhapNhanVien();
        }
        else if (nvChoice == 2) {
            heThong.xemLuongNhanVien();
        }
    } while (nvChoice != 0);
}

void menuQuanLyDoanhThu(QuanLyHeThong& heThong) {
    int dtChoice;
    do {
        cout << "\n===== QUAN LY DOANH THU =====\n";
        cout << "1. Nhap doanh thu theo thang\n";
        cout << "2. Xem chi tiet doanh thu theo ngay\n";
        cout << "0. Quay lai\n";
        cout << "==============================\n";
        cout << "Nhap lua chon: ";
        cin >> dtChoice;

        if (dtChoice == 1) {
            heThong.nhapDoanhThuNgay();
        }
        else if (dtChoice == 2) {
            heThong.xemDanhSachDoanhThu();
        }
    } while (dtChoice != 0);
}

int main() {
    QuanLyHeThong heThong;
    int luaChon;

    do {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "  HE THONG QUAN LY LUONG VA DOANH THU   \n";
        cout << "========================================\n";
        cout << "1. Tinh luong nhan vien\n";
        cout << "2. Quan ly doanh thu thang\n";
        cout << "3. Bao cao tong quan Loi Nhuan\n";
        cout << "0. Thoat\n";
        cout << "========================================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (cin.fail()) {
            cout << "Loi nhap lieu. Vui long nhap so.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (luaChon == 1) {
            menuQuanLyNV(heThong);
        }
        else if (luaChon == 2) {
            menuQuanLyDoanhThu(heThong);
        }
        else if (luaChon == 3) {
            heThong.xuatBaoCao();
        }
        else if (luaChon != 0) {
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
        
    } while (luaChon != 0);

    cout << "\nCam on da su dung he thong!\n";
    return 0;
}