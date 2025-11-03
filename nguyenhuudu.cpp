#include <iostream>
using namespace std;

struct node {
    string maGhe;
    node *next;
};

void themGhe(node* &head, string ghe) {
    node *p = new node;
    p->maGhe = ghe;
    p->next = head;
    head = p;
}

bool daChonGhe(node *head, string ghe) {
    for (node *temp = head; temp != NULL; temp = temp->next)
        if (temp->maGhe == ghe)
            return true;
    return false;
}

bool huyGhe(node* &head, string ghe) {
    if (!head) return false;
    node *temp = head, *prev = NULL;

    if (head->maGhe == ghe) {
        head = head->next;
        delete temp;
        return true;
    }

    while (temp && temp->maGhe != ghe) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return false;

    prev->next = temp->next;
    delete temp;
    return true;
}

void inSoDo(node *danhSachGhe) {
    cout << "\n    ";
    for (int i = 1; i <= 8; i++) cout << i << "   ";
    cout << endl;

    for (int i = 0; i < 8; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < 8; j++) {
            string maGhe = "";
            maGhe += char('A' + i);
            maGhe += to_string(j + 1);
            cout << (daChonGhe(danhSachGhe, maGhe) ? "[X] " : "[ ] ");
        }
        cout << endl << endl;
    }
}

void chonGhe(node* &danhSachGhe) {
    int luaChon;
    string ghe;

    while (true) {
        inSoDo(danhSachGhe);
        cout << "\n===== MENU GHE =====";
        cout << "\n1. Chon ghe";
        cout << "\n2. Huy ghe";
        cout << "\n3. Thoat";
        cout << "\n====================";
        cout << "\nNhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            cout << "Nhap ma ghe (vd: A1): ";
            cin >> ghe;
            if (!daChonGhe(danhSachGhe, ghe)) {
                themGhe(danhSachGhe, ghe);
                cout << "Da chon ghe " << ghe << endl;
            } else {
                cout << "Ghe " << ghe << " da duoc chon!\n";
            }
        } 
        else if (luaChon == 2) {
            cout << "Nhap ma ghe can huy (vd: A1): ";
            cin >> ghe;
            if (huyGhe(danhSachGhe, ghe))
                cout << "Da huy ghe " << ghe << endl;
            else
                cout << "Ghe " << ghe << " chua duoc chon!\n";
        } 
        else if (luaChon == 3) {
            cout << "Quay lai chon phim hoac suat chieu.\n";
            break;
        } 
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }
}

int chonPhim(string phimList[], int soPhim) {
    cout << "\n===== DANH SACH PHIM =====\n";
    for (int i = 0; i < soPhim; i++)
        cout << phimList[i] << endl;
    cout << "===========================\n";

    int chon;
    do {
        cout << "Chon phim (1-" << soPhim << "): ";
        cin >> chon;
        if (chon < 1 || chon > soPhim)
            cout << "Lua chon khong hop le, nhap lai!\n";
    } while (chon < 1 || chon > soPhim);

    cout << "\nBan da chon phim: " << phimList[chon - 1].substr(3) << "\n";
    return chon - 1;
}

int chonSuatChieu(string suatList[][3], int phimIndex) {
    cout << "\n===== SUAT CHIEU =====\n";
    for (int i = 0; i < 3; i++)
        cout << suatList[phimIndex][i] << endl;
    cout << "======================\n";

    int chon;
    do {
        cout << "Chon suat chieu (1-3): ";
        cin >> chon;
        if (chon < 1 || chon > 3)
            cout << "Lua chon khong hop le, nhap lai!\n";
    } while (chon < 1 || chon > 3);

    cout << "\nSuat chieu da chon: " << suatList[phimIndex][chon - 1].substr(3) << endl;
    return chon - 1;
}

int main() {
    string phimList[3] = {
        "1. Avengers: Endgame",
        "2. Spider-Man: No Way Home",
        "3. Inside Out 2"
    };

    string suatChieu[3][3] = {
        {"1. 09:00", "2. 13:30", "3. 19:00"},
        {"1. 10:00", "2. 15:00", "3. 20:15"},
        {"1. 08:30", "2. 12:00", "3. 18:45"}
    };

    node* ghePhim[3][3] = {NULL};

    while (true) {
        cout << "\n========== HE THONG DAT VE ==========\n";
        cout << "1. Chon phim va suat chieu\n";
        cout << "2. Thoat chuong trinh\n";
        cout << "=====================================\n";
        cout << "Nhap lua chon: ";

        int luaChon;
        cin >> luaChon;

        if (luaChon == 1) {
            int phimIndex = chonPhim(phimList, 3);
            int suatIndex = chonSuatChieu(suatChieu, phimIndex);

            cout << "\nBat dau chon ghe cho phim '" 
                 << phimList[phimIndex].substr(3)
                 << "' - suat " 
                 << suatChieu[phimIndex][suatIndex].substr(3)
                 << "'\n";

            chonGhe(ghePhim[phimIndex][suatIndex]);
        }
        else if (luaChon == 2) {
            cout << "\nDa thoat chuong trinh.\n";
            break;
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
