# Test Cases - Smart Assignment & Study Planner

Setiap test terdiri dari dua berkas:
- `tcXX_nama_input.txt`: urutan input yang diketikkan ke program (satu baris = satu Enter).
- `tcXX_nama_expected.txt`: output lengkap yang diharapkan.

## Daftar Test Case
| ID | Kategori | Yang diuji | Hasil yang diharapkan |
|----|----------|-----------|-----------------------|
| TC01 | Normal | Tambah 1 tugas lalu tampilkan | Tersimpan, priority MEDIUM (5 hari) |
| TC02 | Boundary | Priority pada hari 0,1,2,3,4,6,7 | URGENT, URGENT, HIGH, HIGH, MEDIUM, MEDIUM, LOW; statistik 2/2/2/1 |
| TC03 | Normal | Total dan rata-rata jam desimal (2.5, 1.5, 3) | Total 7.00, rata-rata 2.33, total rekursif 7 |
| TC04 | Negatif | ID duplikat | "Task ID already exists!" |
| TC05 | Negatif | ID huruf, hari negatif/huruf, jam 0 | Input ditolak dan diminta ulang |
| TC06 | Normal | Sort hari dan jam, asc dan desc | Urutan sesuai kriteria |
| TC07 | Normal | Search ID dan mata kuliah, termasuk tidak ditemukan | Data muncul / "Task not found!" |
| TC08 | Normal | Total rekursif (4 + 1.5 + 6.5) | 12 |
| TC09 | Normal | Study planner, 5 jam tersedia | Praktikum dan Kuis terpilih (3 jam), sisa 2 |
| TC10 | Edge | Semua menu saat data kosong | "No tasks available!" tanpa crash |
| TC11 | Edge | Planner 0.5 jam dan input -2 | Tidak ada tugas muat; -2 ditolak |
| TC12 | Negatif | Menu 9 dan "abc" | Pesan invalid |
| TC13 | Negatif | Pilihan sort/search berupa huruf | Pesan invalid, menu normal |
| TC14 | Negatif | ID search berupa huruf | Diminta ulang sampai angka |
| TC15 | Boundary | Jam tersedia sama dengan jam tugas (4 = 4) | Tugas terpilih, sisa 0 |

## Cara Menjalankan
Satu test manual:

    g++ -std=c++11 ../main.cpp -o planner
    ./planner < tc09_study_planner_input.txt

Semua test otomatis (Linux / macOS / Git Bash):

    bash run_tests.sh
