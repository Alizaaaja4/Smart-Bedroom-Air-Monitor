# Smart-Bedroom-Air-Monitor

<img src="https://github.com/Alizaaaja4/Smart-Bedroom-Air-Monitor/blob/main/dokumentasi.jpg" width="800" height="400" />

**Smart-Bedroom-Air-Monitor** adalah sistem pemantauan kualitas udara dan suhu di kamar tidur berbasis **IoT**. Alat ini menggunakan berbagai sensor untuk mendeteksi kondisi udara dan suhu di dalam ruangan, serta memberikan indikasi melalui LED dan buzzer jika kondisi udara atau suhu berada di luar batas aman. Data kualitas udara dan suhu ditampilkan secara real-time pada **LCD 20x4**.

### Komponen yang Digunakan:
1. **MQ4 Sensor (simulasi menggunakan Potentiometer)**: Digunakan untuk mendeteksi kualitas udara (level gas).
2. **DHT22 Sensor**: Digunakan untuk mengukur suhu dan kelembapan udara di kamar tidur.
3. **LCD 20x4 (I2C)**: Menampilkan hasil pembacaan suhu dan kualitas udara secara real-time.
4. **LED**: Digunakan sebagai indikator perangkat aktif.
5. **Buzzer**: Memberikan peringatan suara jika kualitas udara atau suhu berada di luar ambang batas yang telah ditentukan.
6. **Potentiometer (untuk simulasi MQ4)**: Digunakan untuk mensimulasikan pembacaan kualitas udara sebagai input analog.
7. **Arduino (misalnya, Arduino Uno)**: Sebagai pengendali utama yang memproses data dari sensor dan mengendalikan LED dan buzzer.

### Cara Kerja Alat:
1. **Pengukuran Suhu dan Kualitas Udara**:
   - **Sensor DHT22** mengukur suhu dan kelembapan udara di kamar tidur.
   - **Potentiometer** (yang digunakan untuk mensimulasikan sensor MQ4) memberikan nilai analog yang diubah menjadi data kualitas udara.
  
2. **Tampilan Data pada LCD**:
   - Data suhu ditampilkan di baris pertama LCD, sedangkan data kualitas udara ditampilkan di baris kedua.
   - Jika kualitas udara buruk atau suhu melebihi ambang batas yang telah ditentukan, **buzzer** akan berbunyi dan status tersebut akan ditampilkan pada baris ketiga atau keempat LCD.

3. **Indikasi LED dan Buzzer**:
   - **LED** menyala untuk menunjukkan bahwa sistem sedang aktif.
   - **Buzzer** akan menyala jika suhu atau kualitas udara tidak aman, memberi peringatan kepada pengguna.

4. **Pengaturan Ambang Batas**:
   - Jika kualitas udara lebih tinggi dari nilai ambang batas yang ditentukan (misalnya, lebih dari 400), maka kualitas udara dianggap buruk dan buzzer akan berbunyi.
   - Jika suhu melebihi nilai ambang batas yang ditentukan (misalnya, lebih dari 30°C), buzzer juga akan berbunyi sebagai peringatan.

