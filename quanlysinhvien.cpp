#include <iostream>
#include<stdio.h>
#include<conio.h>
#include <string.h>
#define MAX 100
using namespace std;

struct SinhVienUTC2 {
    int mssv;
    char ten[40];
    int tuoi;
	char gioiTinh[4];
    float diemToan;
    float diemHoa;
    float diemLy;
    float diemTB = 0;
    char hocluc[10] = "-";
};

typedef SinhVienUTC2 SV;

void printLine(int n);
void nhapThongTinSV(SV &sv, int mssv);
void nhapSV(SV a[], int mssv, int n);
void capNhatThongTinSV(SV &sv);
void capNhatSV(SV a[], int mssv, int n);
int xoaTheoMSSV(SV a[], int mssv, int n);
void timKiemTheoTen(SV a[], char ten[], int n);
void tinhDTB(SV &sv);
void xeploai(SV &sv);
void showStudent(SV a[], int n);
int mssvLonNhat(SV a[], int n);
void sapXepTheoTen(SV a[], int n);
void sapxepTheoDTB(SV a[], int n);
int docFile(SV a[], char fileName[]);
void ghiFile(SV a[], int n, char fileName[]);
void pressAnyKey();

int main() {
    int key;
    char fileName[] = "sinhvien.txt";
    SV arraySV[MAX];
    int soluongSV = 0;
    int mssvCount = 0;
    soluongSV = docFile(arraySV, fileName);
    mssvCount = mssvLonNhat (arraySV, soluongSV);

    while(true) {
        cout << "CHUONG TRINH QUAN LY SINH VIEN UTC2 \n";
        cout <<"(UTC2)====================MENU-CHINH===============(UTC2)\n";
        cout << " ||  1. Them sinh vien.                               ||\n";
        cout << " ||  2. Cap nhat thong tin sinh vien bang MSSV.       ||\n";
        cout << " ||  3. Xoa sinh vien bang MSSV.                      ||\n";
        cout << " ||  4. Tim kiem sinh vien theo ten.                  ||\n";
        cout << " ||  5. Sap xep sinh vien theo ten .                  ||\n";
        cout << " ||  6. Sap xep sinh vien theo diem trung binh.       ||\n";
        cout << " ||  7. Hien thi danh sach sinh vien.                 ||\n";
        cout << " ||  8. Ghi danh sach sinh vien vao file.             ||\n";
        cout << " ||  0. Thoat                                         ||\n";
        cout << " =======================================================\n";
        cout << "Chon chuc nang: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n 1. Them sinh vien.";
                mssvCount++;
                nhapSV(arraySV, mssvCount, soluongSV);
                printf("\nThem sinh vien thanh cong!");
                soluongSV++;
                pressAnyKey();
                break;
            case 2:
                if(soluongSV > 0) {
                    int mssv;
                    cout << "\n 2. Cap nhat thong tin sinh vien. ";
                    cout << "\n Nhap MSSV: "; cin >> mssv;
                    capNhatSV(arraySV, mssv, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSV > 0) {
                    int mssv;
                    cout << "\n 3. Xoa sinh vien.";
                    cout << "\n Nhap MSSV: "; cin >> mssv;
                    if (xoaTheoMSSV(arraySV, mssv, soluongSV) == 1) {
                        printf("\nSinh vien co MSSV = %d da bi xoa.", &mssv);
                        soluongSV--;
                    }
                }else{
                    cout << "\n Danh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSV > 0) {
                    cout << "\n 4. Tim kiem sinh vien theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arraySV, strTen, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongSV > 0) {
                    cout << "\n 5. Sap xep sinh vien theo ten.";
                    sapXepTheoTen(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                } else {
                    cout << "\nDanh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongSV > 0) {
                    cout << "\n 6. Sap xep sinh vien theo diem trung binh (GPA).";
                    sapxepTheoDTB(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\n Danh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;    
            case 7:
                if(soluongSV > 0){
                    cout << "\n 7. Hien thi danh sach sinh vien.";
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien hien chua co!";
                }
                pressAnyKey();
                break;
            case 8:
                if(soluongSV > 0){
                    cout << "\n 8. Ghi danh sach sinh vien vao file.";
                    ghiFile(arraySV, soluongSV, fileName);
                }else{
                    cout << "\n Danh sach sinh vien hien chua co!";
                }
                printf("\n Ghi danh sach sinh vien vao file %s hoan tat!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat ung dung!";
                getch();
                return 0;
            default:
                cout << "\n Khong co chuc nang nay!";
                cout << "\n Hay chon chuc nang trong  menu chinh.";
                pressAnyKey();
                break;
        }
    }
}
 
void tinhDTB(SV &sv) {
    sv.diemTB = (sv.diemLy + sv.diemToan + sv.diemHoa) / 3;    
}

void xeploai(SV &sv) {
    if(sv.diemTB >= 8) strcpy(sv.hocluc, "Gioi");
    else if(sv.diemTB >= 6) strcpy(sv.hocluc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocluc, "Trung binh");
    else strcpy(sv.hocluc, "Yeu");
}
 
void nhapThongTinSV(SV &sv, int mssv) {
    cout << "\n Nhap ho ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap gioi tinh: "; gets(sv.gioiTinh);
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    cout << " Nhap diem Hoa: "; cin >> sv.diemHoa;
    sv.mssv = mssv;
    tinhDTB(sv);
    xeploai(sv);
}

void nhapSV(SV a[], int mssv, int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], mssv);
    printLine(40);
}

void capNhatThongTinSV(SV &sv) {
    cout << "\n Nhap ho ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap gioi tinh: "; gets(sv.gioiTinh);
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    cout << " Nhap diem Hoa: "; cin >> sv.diemHoa;
    tinhDTB(sv);
    xeploai(sv);
}

void capNhatSV(SV a[], int mssv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].mssv == mssv) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co MSSV = " << mssv;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co MSSV = %d khong ton tai.", mssv);
    }
}

int xoaTheoMSSV(SV a[], int mssv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].mssv == mssv) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co MSSV = " << mssv;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien  MSSV = %d khong ton tai.", mssv);
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void showStudent(SV a[], int n) {
    printLine(100);
    cout <<"\n\STT\tMSSV\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        printf("\n %d", i + 1);
        printf("\t%d", a[i].mssv);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocluc);
    }
    printLine(100);
}
 
void sapxepTheoDTB(SV a[], int n) {
    SV tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapXepTheoTen(SV a[], int n) {
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < n; i++) {
    	strcpy(tenSV1, a[i].ten);
        for(int j = i+1; j < n; j++) {
        	strcpy(tenSV2, a[j].ten);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int mssvLonNhat (SV a[], int n) {
    int mssvMax = 0;
    if (n > 0) {
        mssvMax = a[0].mssv;
        for(int i = 0;i < n; i++) {
            if (a[i].mssv > mssvMax) {
                mssvMax = a[i].mssv;
            }
        }
    }
    return mssvMax;
}

int docFile(SV a[], char fileName[]) {
    FILE * fop;
    int i = 0;
    fop = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    while (fscanf(fop, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].mssv, &a[i].ten, 
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa, 
            &a[i].diemTB, &a[i].hocluc) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    fclose (fop);
    return i;
}

void ghiFile(SV a[], int n, char fileName[]) {
    FILE * fop;
    fop = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fop, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].mssv, a[i].ten,a[i].gioiTinh, 
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocluc);
    }
    fclose (fop);
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\n\nNhan phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
