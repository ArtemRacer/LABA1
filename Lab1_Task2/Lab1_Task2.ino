// Визначення номеру піна для світлодіода
const int ledPin = 13;

void setup() {
  // Ініціалізація порту UART з швидкістю 9600 біт/с
  Serial.begin(9600);
  
  // Визначення піна для світлодіода як вихідний
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Перевірка, чи отримано дані через UART
  if (Serial.available() > 0) {
    // Зчитування першого символу
    char firstChar = Serial.read();

    // Перевірка, чи це символ "A"
    if (firstChar == 'A') {
      // Якщо так, чекаємо на інші символи для формування команди
      delay(10); // Затримка для читання решти команди

      // Отримання числа після "AT+"
      int number = Serial.parseInt();

      // Перевірка, чи число кратне 10
      if (number % 10 == 0) {
        // Якщо так, вмикаємо світлодіод
        digitalWrite(ledPin, HIGH);
      } else {
        // Якщо ні, вимикаємо світлодіод
        digitalWrite(ledPin, LOW);
      }
    }
  }
}
