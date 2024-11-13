#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define AIR_QUALITY_THRESHOLD 400  // Ambang batas kualitas udara
#define TEMP_THRESHOLD 30          // Ambang batas suhu

#define DHTPIN 2                  // Pin data untuk sensor DHT22
#define DHTTYPE DHT22             // Tipe sensor DHT
#define LED_PIN 13                // Pin untuk LED indikator
#define BUZZER_PIN 12             // Pin untuk Buzzer
#define POT_PIN A0                // Pin untuk Potentiometer yang digunakan untuk mensimulasikan MQ135

DHT dht(DHTPIN, DHTTYPE);            // Inisialisasi sensor DHT
LiquidCrystal_I2C lcd(0x27, 20, 4);  // LCD 20x4 (Alamat I2C)

void setup() {
  Serial.begin(9600);  // Mulai komunikasi serial
  dht.begin();         // Inisialisasi sensor DHT
  lcd.begin(20, 4);    // Inisialisasi LCD 20x4
  lcd.init();          // Inisialisasi LCD
  lcd.backlight();     // Aktifkan lampu latar LCD

  pinMode(LED_PIN, OUTPUT);    // Set pin LED sebagai output
  pinMode(BUZZER_PIN, OUTPUT); // Set pin buzzer sebagai output

  // LED indikator menyala untuk menunjukkan perangkat aktif
  digitalWrite(LED_PIN, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Perangkat On");
  delay(2000);  // Tampilkan pesan selama 2 detik
  lcd.clear();
}

void loop() {
  // Membaca suhu dari sensor DHT
  float temp = dht.readTemperature();

  // Membaca kualitas udara dari potentiometer (untuk simulasi)
  int airQuality = analogRead(POT_PIN);

  // Menampilkan suhu dan kualitas udara pada LCD
  lcd.setCursor(0, 0); 
  lcd.print("Suhu: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 2);  // Pindah ke baris ketiga
  lcd.print("Kualitas: ");
  lcd.print(airQuality);

  // Kondisi 1: Alarm jika suhu terlalu tinggi
  if (temp > TEMP_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);  // Nyalakan buzzer
    lcd.setCursor(0, 1);  // Pindah ke baris kedua
    lcd.print("Suhu: Tinggi!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Matikan buzzer
    lcd.setCursor(0, 1);  // Pindah ke baris kedua
    lcd.print("Suhu: Aman");
  }

  // Kondisi 2: Alarm jika kualitas udara buruk
  if (airQuality > AIR_QUALITY_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);  // Nyalakan buzzer
    lcd.setCursor(0, 3);  // Pindah ke baris keempat
    lcd.print("Kualitas: Buruk");
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Matikan buzzer
    lcd.setCursor(0, 3);  // Pindah ke baris keempat
    lcd.print("Kualitas: Baik");
  }

  delay(3000);  // Update data setiap 3 detik
  lcd.clear();   // Clear LCD untuk update layar
}
