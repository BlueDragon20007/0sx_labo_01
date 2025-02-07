const int LED = 13;
const String numEtudiant = "6307713";
const int temps = 2000;
const int tempsClignotement = 250;
int nbClignotement = numEtudiant.substring(5, 6).toInt() / 2 + 2; // +2 à la place de +1 car ça arrondit vers le bas
const int tempsVariation = 2048;
int intervalleVariation = tempsVariation / 256;
int etape = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  switch (etape) {
    case 0:
      allume();
      break;

    case 1:
      clignotement();
      break;

    case 2:
      variation();
      break;

    case 3:
      eteint();
      break;
  }
  etape = (etape + 1) % 4;
}


void allume() {
  Serial.print("Allume – ");
  Serial.println(numEtudiant);
  digitalWrite(LED, HIGH);
  delay(temps);
}

void clignotement() {
  Serial.print("Clignotement – ");
  Serial.println(numEtudiant);
  for (int i = 0; i < nbClignotement; i++) {
    digitalWrite(LED, LOW);
    delay(tempsClignotement);
    digitalWrite(LED, HIGH);
    delay(tempsClignotement);
  }
}

void variation() {
  Serial.print("Variation – ");
  Serial.println(numEtudiant);
  for (int i = 1; i < 255; i++) {
    if (numEtudiant.substring(6).toInt() % 2 == 0) {
      analogWrite(LED, i);
    } else {
      analogWrite(LED, -i);
    }
    delay(intervalleVariation);
  }
}

void eteint() {
  Serial.print("Éteint – ");
  Serial.println(numEtudiant);
  digitalWrite(LED, LOW);
  delay(temps);
}
