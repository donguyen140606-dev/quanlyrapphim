#include<iostream> 
#include<string> 
using namespace std;
 
 class NhanVien {
public:
    string hoTen, gioiTinh, viTriWork;
    int caLam;
    long long ID;
    double tongLuong;

    void nhap();
    void tinhLuong();
    void xuat();
};

// Định nghĩa hàm NhanVien bên ngoài class
void NhanVien::nhap() {
    cin.ignore();
    cout << "\nNhap Ho Ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Vi tri lam viec: ";
    getline(cin, viTriWork);
    
    // Nhập ID 
    do {
        cout << "So ID (so nguyen duong): ";
        cin >> ID;
        if (cin.fail() || ID <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ID khong hop le! Vui long nhap lai.\n";
        } else {
            break;
        }
    } while (true);
    
    // Nhập số ca làm 
    do {
        cout << "So ca lam viec trong thang: ";
        cin >> caLam;
        if (cin.fail() || caLam < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "So ca khong hop le! Vui long nhap lai.\n";
        } else {
            break;
        }
    } while (true);
    
    tinhLuong();
}

void NhanVien::tinhLuong() {
    int soGioLam = caLam * GIO_MOT_CA;
    tongLuong = soGioLam * LUONG_THEO_GIO;
}

void NhanVien::xuat() {
    cout << "========================================" << endl;
    cout << "Ho Ten          : " << hoTen << endl;
    cout << "Gioi Tinh       : " << gioiTinh << endl;
    cout << "Vi tri          : " << viTriWork << endl;
    cout << "ID              : " << ID << endl;
    cout << "So ca lam       : " << caLam << endl;
    cout << "Tong luong      : " << fixed << setprecision(0) << tongLuong << " VND" << endl;
    cout << "========================================" << endl;
}

// ================== DANH SACH NHAN VIEN ==================
struct NodeNV {
    NhanVien data;
    NodeNV* next;
};

class ListNhanVien {
public:
    NodeNV* head;
    NodeNV* tail;
    
    ListNhanVien();
    NodeNV* createNode(NhanVien v);
    bool kiemTraIDTonTai(int id);
    void addNV(NhanVien v);
    void deleteNV(int id);
    void editNV(int id);
    void show();
    double tinhTongLuong();
};

// Định nghĩa hàm ListNhanVien bên ngoài class
ListNhanVien::ListNhanVien() { 
    head = tail = NULL; 
}

NodeNV* ListNhanVien::createNode(NhanVien v) {
    NodeNV* p = new NodeNV();
    p->data = v;
    p->next = NULL;
    return p;
}

bool ListNhanVien::kiemTraIDTonTai(int id) {
    for (NodeNV* i = head; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            return true;
        }
    }
    return false;
}

void ListNhanVien::addNV(NhanVien v) {
    // Kiểm tra ID trùng
    if (kiemTraIDTonTai(v.ID)) {
        cout << "\n ID " << v.ID << " da ton tai! Vui long nhap ID khac.\n";
        return;
    }
    
    v.tinhLuong();
    NodeNV* p = createNode(v);
    if (head == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    cout << "Da them nhan vien thanh cong!\n";
}

void ListNhanVien::deleteNV(int id) {
    if (head == NULL) {
        cout << "\nKhong co nhan vien nao" << endl;
        return;
    }
    
    if (head->data.ID == id) {
        NodeNV* p = head;
        head = head->next;
        delete p;
        cout << "\nDa xoa nhan vien thanh cong" << endl;
        return;
    }
    
    NodeNV* j = head;
    for (NodeNV* i = head->next; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            j->next = i->next;
            if (i == tail) tail = j;
            delete i;
            cout << "\nDa xoa nhan vien thanh cong" << endl;
            return;
        }
        j = i;
    }
    cout << "\nKhong tim thay ID" << endl;
}

void ListNhanVien::editNV(int id) {
    for (NodeNV* i = head; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            cout << "Da tim thay nhan vien:" << endl;
            i->data.xuat();
            cout << "\n----Nhap lai thong tin----:" << endl;
            i->data.nhap();
            cout << "Cap nhat thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void ListNhanVien::show() {
    if (!head) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    cout << "\n========= DANH SACH NHAN VIEN =========" << endl;
    for (NodeNV* i = head; i != NULL; i = i->next) {
        i->data.xuat();
    }
}

double ListNhanVien::tinhTongLuong() {
    double tong = 0;
    for (NodeNV* i = head; i != NULL; i = i->next) {
        tong += i->data.tongLuong;
    }
    return tong;
}

 
  
 int main(){
 	NhanVien a;
 	ListNhanVien b; 
 	int menu;
 	do{ 
 	  cout<<"=========== MENU QUAN LY NHAN VIEN ===========" << endl;
 	  cout<<"1.Them nhan vien"<<endl;
 	  cout<<"2.Hien thi danh sach sinh vien"<<endl;
 	  cout<<"3.Sua thong tin nhan vien"<<endl;
 	  cout<<"4.Xoa nhan vien"<<endl;
 	 
 	  cout<<"0.Thoat chuong trinh"<<endl;
 	  cout<<"-----------------------"<<endl;
 	  cout<<"Xin moi chon phuong thuc:";
 	  cin>>menu;
 	  
 	  switch(menu){
 	  	case 1:{
 	  		int n; 
 	        cout<<"\nNhap so nhan vien: " ;
 	        cin>>n;
	        for(int i=0;i<n;i++) {
	 	      a.nhap() ;
	 	      b.addNV(a) ;
	 }
			break;
		   }
		case 2:{
			b.Show();
			break;
		}
		case 3:{
			int d;
	        cout<<"\nNhap ID NV can sua thong tin:"<<endl;
	        cin>>d;
 	        b.editNV(d);
			break;
		}
		case 4:{
			int c; 
 	        cout<<"\nNhap ID can xoa: " ;
 	        cin>>c; 
 	        b.deleteNV(c);
			break;
		}
		case 0:{
			cout<<"Thoat chuong trinh"<<endl;
			break;
		}
		default:
			cout<<"Lua chon khong hop le. Vui long nhap lai"<<endl;
	   }
	 }while (menu !=0);



