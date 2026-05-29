#include <stdio.h>
#include <string.h>

void checkBMI(float bmi, char* kategori, char* risiko, char* keterangan) {
    if (bmi < 18.5) {
        strcpy(kategori, "Underweight");
        strcpy(risiko, "Rendah");
        strcpy(keterangan, "Berisiko terkena osteoporosis dan malnutrisi");
    } else if (bmi >= 18.5 && bmi < 23.0) {
        strcpy(kategori, "Normal");
        strcpy(risiko, "Sangat Rendah");
        strcpy(keterangan, "Bagus. Tolong pertahankan ya");
    } else if (bmi >= 23.0 && bmi < 25.0) {
        strcpy(kategori, "Overweight");
        strcpy(risiko, "Sedang");
        strcpy(keterangan, "Berisiko terkena diabetes tipe 2 dan hipertensi");
    } else if (bmi >= 25.0 && bmi < 30.0) {
        strcpy(kategori, "Obesitas Tingkat 1");
        strcpy(risiko, "Tinggi");
        strcpy(keterangan, "Berisiko terkena penyakit kardiovaskular yang meningkat secara signifikan");
    } else {
        strcpy(kategori, "Obesitas Tingkat 2");
        strcpy(risiko, "Sangat Tinggi");
        strcpy(keterangan, "Sangat dibutuhkan penanganan medis segera");
    }
}

void analyzeDemographicRisk(int usia, char gender, float bmi) {
    printf("\n==================================================\n");
    printf("   ANALISIS RISIKO KESEHATAN TAMBAHAN (DEMOGRAFIS)  \n");
    printf("==================================================\n");

    printf("* Faktor Usia (%d tahun): ", usia);
    if (usia >= 45 && gender == 'L') {
        printf("Risiko penyakit jantung koroner meningkat secara alami pada pria di atas 45 tahun.\n");
    } else if (usia >= 55 && gender == 'P') {
        printf("resiko pasca menopause dapat meningkatkan akibat kerentanan terhadap gangguan metabolik dan kardiovaskular.\n");
    } else {
        printf("faktor risiko degeneratif berbasis usia masih tergolong rendah.\n");
    }
    
    printf("* Rekomendasi Klinis: ");
    if (bmi >= 23.0) {
        if (gender == 'L') {
            printf("Pria cenderung menyimpan lemak visceral di area perut. Fokus pada latihan kardio dan kurangi konsumsi lemak jenuh untuk mencegah perlemakan hati (fatty liver).\n");
        } else {
            printf("Wanita dengan BMI tinggi rentan terhadap ketidakseimbangan hormon (seperti PCOS jika di usia produktif) dan sindrom metabolik. Disarankan menjaga asupan kalori.\n");
        }
    } else if (bmi < 18.5) {
        printf("Disarankan untuk skrining kecukupan nutrisi, kadar zat besi (anemia), serta fungsi tiroid.\n");
    } else {
        printf("Pertahankan gaya hidup sehat, pola makan gizi seimbang, dan melakukan olahraga selama 150 menit/minggu.\n");
    }
}

int main() {
    char nama[50];
    int usia;
    char gender;
    float berat, tinggi, tinggiMeter, bmi;
    char kategori[100], risiko[100], keterangan[100];

    printf("==================================================\n");
    printf("        BMI & HEALTH RISK ANALYZER SYSTEM         \n");
    printf("==================================================\n");
    
    printf("Masukkan Nama            : ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0; 
    
    printf("Masukkan Usia (Tahun)    : ");
    scanf("%d", &usia);
    
    printf("Jenis Kelamin (L/P)      : ");
    scanf(" %c", &gender);
    
    printf("Masukkan Berat Badan (kg): ");
    scanf("%f", &berat);
    
    printf("Masukkan Tinggi Badan (cm): ");
    scanf("%f", &tinggi);
    
    tinggiMeter = tinggi / 100.0;
    bmi = berat / (tinggiMeter * tinggiMeter);
    
    checkBMI(bmi, kategori, risiko, keterangan);
    
    printf("\n==================================================\n");
    printf("                 HASIL SKRINING                   \n");
    printf("==================================================\n");
    printf("Nama Pasien    : %s\n", nama);
    printf("Karakteristik  : %s, %d Tahun\n", (gender == 'L' || gender == 'l') ? "Laki-laki" : "Perempuan", usia);
    printf("Skor BMI       : %.2f kg/m^2\n", bmi);
    printf("Kategori BMI   : %s\n", kategori);
    printf("Risiko Penyakit: %s\n", risiko);
    printf("Keterangan     : %s\n", keterangan);
    
    analyzeDemographicRisk(usia, (gender == 'L' || gender == 'l') ? 'L' : 'P', bmi);
    
    printf("==================================================\n");
    return 0;
}