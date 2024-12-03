#include <stdio.h>

int main() {
    int ans, n;
    int a[100][100];
    long long int tong = 0;
    long long int tich = 1;
    
    do {
        printf("\n            Menu             \n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang.\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran.\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich.\n");
        printf("4. In cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu.\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan.\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang.\n");
        printf("8. Thoat.");
        printf("\nLua chon cua ban: ");
        scanf("%d", &ans);
        
        switch(ans) {
            case 1:
                printf("Nhap kich co cua mang: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("Kich co ma tran khong hop le, vui long nhap lai.\n");
                    break;
                }
                printf("\nNhap gia tri cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("a[%d][%d] = ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }
                break;

            case 2:
                printf("\nMa tran cua mang la:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\nCac phan tu duong bien la:");
                tich = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                            printf("%d ", a[i][j]);
                            tich *= a[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu cua duong bien la: %lld", tich);
                break;

            case 4:
                if (n <= 0) {
                    printf("Ma tran khong hop le, vui long nhap kich co ma tran vuong.\n");
                    break;
                }
                printf("\nCac phan tu nam tren duong cheo chinh la:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i][i]);
                }
                printf("\n");
                break;

            case 5:
                if (n <= 0) {
                    printf("Ma tran khong hop le, vui long nhap kich co ma tran vuong.\n");
                    break;
                }
                printf("\nCac phan tu nam tren duong cheo phu la:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i][n - 1 - i]);
                }
                printf("\n");
                break;

            case 6:
                if (n <= 0) {
                    printf("Ma tran khong hop le, vui long nhap kich co ma tran vuong.\n");
                    break;
                }
                printf("\nSap xep duong cheo chinh tang dan:\n");
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (a[i][i] > a[j][j]) {
                            int temp = a[i][i];
                            a[i][i] = a[j][j];
                            a[j][j] = temp;
                        }
                    }
                }
                printf("\nMa tran sau khi sap xep duong cheo chinh tang dan la:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 7: {
                int x, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                printf("\nVi tri cua phan tu %d trong mang:\n", x);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] == x) {
                            printf("a[%d][%d] ", i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong mang.\n", x);
                } else {
                    printf("\n");
                }
                break;
            }

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (ans != 8);

    return 0;
}

