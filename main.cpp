#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>

int x = 0;

struct mahasiswa
{
	char nama[20];
	char nim[20];
	char nilai;
	char status;
	int tugas;
	int kuis;
	int uts;
	int uas;
	float nilaiAkhir;

} mhs[200];

int main()
{
	int pilih;
	char status;
	
	do
	{
	tampilan:
		printf("\n-------------------------------------------------\n");
		printf("Program Structur Menghitung Nilai Akhir Mahasiswa\n");
		printf("-------------------------------------------------\n");
		printf("1. Input Data Mahasiswa\n");
		printf("2. Tampilkan Data Mahasiswa\n");
		printf("3. Exit\n");
		printf(">>");
		scanf("%d", &pilih);
		if (pilih > 3)
		{
			printf("============================================\n");
			printf("Angka Yang Anda Masukkan Salah, Coba Lagi!!!\n");
			printf("============================================\n");
		}

		switch (pilih)
		{
		case 1:
		{
		pilihan1:
			system("cls");
			printf("Data Mahasiswa - %d\n\n", x + 1);
			printf("[1]. Nama        : ");
			scanf("%s", &mhs[x].nama);
			printf("[2]. NIM         : ");
			scanf("%s", &mhs[x].nim);
			printf("[3]. Nilai Tugas : ");
			scanf("%d", &mhs[x].tugas);
			printf("[4]. Nilai Kuis  : ");
			scanf("%d", &mhs[x].kuis);
			printf("[5]. Nilai UTS   : ");
			scanf("%d", &mhs[x].uts);
			printf("[6]. Nilai UAS   : ");
			scanf("%d", &mhs[x].uas);

			mhs[x].nilaiAkhir = (float)(mhs[x].tugas + mhs[x].kuis +
										mhs[x].uts + mhs[x].uas) /
								4;

			if (mhs[x].nilaiAkhir >= 80)
				mhs[x].nilai = 'A';
			else if (mhs[x].nilaiAkhir >= 70)
				mhs[x].nilai = 'B';
			else if (mhs[x].nilaiAkhir >= 55)
				mhs[x].nilai = 'C';
			else if (mhs[x].nilaiAkhir >= 40)
				mhs[x].nilai = 'D';
			else if (mhs[x].nilaiAkhir < 40)
				mhs[x].nilai = 'E';

			FILE *f = fopen("nilai.txt", "a");
			fprintf(f, "%s\t%s\t%d\t%d\t%d\t%d\t%f (%c)\n", mhs[x].nama, mhs[x].nim,
					mhs[x].tugas, mhs[x].kuis, mhs[x].uts, mhs[x].uas, mhs[x].nilaiAkhir,
					mhs[x].nilai);
			x++;
			printf("\nData Mahasiswa Berhasil Di Simpan\n");
			
		}

			printf("\nApakah Anda Ingin Menginput Data Lagi ? [Y/T]");
			status = getche();
			system("cls");
			if (toupper(status) == 'Y')
				goto pilihan1;
			else
				goto tampilan;

		case 2:

			system("cls");
			printf("===================================================================\n");
			printf("Nama\tNIM\t\tTugas\tKuis\tUTS\tUAS\tNilai Akhir\n");
			printf("===================================================================\n");
			int i;
			for (i = 0; i < x; i++)
			{
				printf("%s\t%s\t%d\t%d\t%d\t%d\t%.2f (%c)\n", mhs[i].nama, mhs[i].nim,
					   mhs[i].tugas, mhs[i].kuis, mhs[i].uts, mhs[i].uas, mhs[i].nilaiAkhir,
					   mhs[i].nilai);
			}
			printf("\nPress any key to continue . . .\n");
			getch();
			break;
		}
	} while (pilih != 3);
	exit(0);
}

