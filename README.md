# Smart Assignment & Study Planner

Program C++ berbasis konsol untuk mencatat tugas akademik, menentukan prioritas berdasarkan sisa hari menuju deadline, 
dan merekomendasikan tugas yang dapat dikerjakan sesuai jam belajar yang tersedia hari ini.

## Anggota Kelompok 3
|No |         Nama          |       NIM          |
|---|-----------------------|--------------------|
| 1 | Aulia Dwi Novita      | 26/583177/PA/24475 |
| 2 | Berliana Woro Aninda  | 26/577966/PA/24205 |
| 3 | Kalila Indri Sahasika | 26/588392/PA/24806 |
| 4 | Khaira Denisa         | 26/586577/PA/24693 |
| 5 | Hilmiya Fathma Hanun  | 26/576961/PA/24119 |

## Fitur
1. Tambah tugas (validasi input dan cek ID duplikat)
2. Tampilkan semua tugas
3. Statistik waktu belajar (total dan rata-rata jam)
4. Statistik jumlah tugas per priority
5. Sort berdasarkan sisa hari atau estimasi jam
6. Search berdasarkan ID tugas atau nama mata kuliah
7. Total waktu belajar (menggunakan rekursi)
8. Today's Study Planner (challenge)

## Aturan Priority
| Sisa hari | Priority |
|-----------|----------|
|   0 - 1   | URGENT   |
|   2 - 3   | HIGH     |
|   4 - 6   | MEDIUM   |
|   >= 7    | LOW      |

## Cara Menjalankan
    g++ -std=c++11 main.cpp -o planner
    ./planner          (Windows: planner.exe)

## Pengujian
15 test case ada di folder `test_cases/` (lihat `test_cases/README.md`).

    cd test_cases
    bash run_tests.sh

## Struktur Repository
- `main.cpp` : source code
- `test_cases/` : berkas input, expected output, dan script uji otomatis
- `Laporan_Smart_Assignment_Study_Planner.pdf` : laporan
- `Persiapan_Demo.md` : panduan demo

## Keterbatasan
- Search mata kuliah sensitif huruf besar/kecil
- Priority dihitung saat tugas ditambahkan, tidak berkurang otomatis tiap hari
- Study planner bersifat greedy (urut priority, lalu urutan input)
