const int analogInPin = A0;

// ===== CONFIGURACION =====
const unsigned int N_MUESTRAS = 1000;   // numero de muestras por medicion
const unsigned int DT_MS = 4;           // tiempo entre muestras [ms]
// =========================

void setup() {
  Serial.begin(9600);

  analogReference(DEFAULT);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("\n\n✅ Sistema listo.");
  Serial.println("\n⚠️ Presione ENTER en el monitor serial para realizar una medicion.");
  Serial.print("📊 Cada medicion promedia ");
  Serial.print(N_MUESTRAS);
  Serial.println(" muestras.");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 

  // Esperar orden desde el monitor serial
  if (Serial.available() > 0) {

    // Vaciar buffer (ENTER)
    while (Serial.available() > 0) {
      Serial.read();
    }

    unsigned long sumaADC = 0;

    Serial.println("\n⏳ Calculando campo magnetico 🧲");

    // Adquisicion controlada
    for (unsigned int i = 0; i < N_MUESTRAS; i++) {
      sumaADC += analogRead(analogInPin);
      delay(DT_MS);
    }

    float promedioADC = (float)sumaADC / N_MUESTRAS;
    float voltaje = (promedioADC * 5.0) / 1023.0;

    Serial.println("\nMediciones realizadas:");
    Serial.print("\n📊 Numero de muestras recolectadas: ");
    Serial.println(N_MUESTRAS);
    Serial.print("📏 Voltaje promedio calculado [V]: ");
    Serial.println(voltaje, 6);
    Serial.println("\n---------------------------------------------");
    Serial.println("\n✅ Listo para la siguiente medicion.");
    Serial.println("\n⚠️ Presione ENTER en el monitor serial para realizar una medicion.");
  }
}
