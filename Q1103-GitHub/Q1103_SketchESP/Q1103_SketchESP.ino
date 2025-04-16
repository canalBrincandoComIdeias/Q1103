#define pinMotor1F 2
#define pinMotor1T 4

#define pinMotor2F 19
#define pinMotor2T 18

int freq = 976;      // Frequência PWM (976 Hz compativel com Arduino UNO)
int resolution = 8;  // Resolução de 8 bits (Compatível com Arduino UNO)

String comando;
String valor;
int velocidade = 255;

void setup() {
  pinMode(pinMotor1F, OUTPUT);
  pinMode(pinMotor1T, OUTPUT);
  pinMode(pinMotor2F, OUTPUT);
  pinMode(pinMotor2T, OUTPUT);

  Serial.begin(9600);

  ledcAttach(pinMotor1F, freq, resolution);
  ledcAttach(pinMotor1T, freq, resolution);
  ledcAttach(pinMotor2F, freq, resolution);
  ledcAttach(pinMotor2T, freq, resolution);

  Serial.println("Motor montTUDO");
  Serial.println("-----------------");
  Serial.println("Comandos disponiveis via serial:");
  Serial.println("p<motor> - Para o motor especificado.  Ex: p1");
  Serial.println("f<motor> - Aciona o motor especificado para frente.  Ex: f2");
  Serial.println("t<motor> - Aciona o motor especificado para trás.");
  Serial.println("v<velocidade> - Altera a velocidade para o valor especificado (de 0 a 255");
  Serial.println("Digite o comando e pressione enter...");
  Serial.println();
  Serial.println("Skecth Iniciado!");
}

void loop() {

  if (Serial.available()) {
    comando = Serial.readString();
    comando.trim();
    valor = comando.substring(1);

    //Comando para PARAR
    if ((comando[0] == 'p') || (comando[0] == 'P')) {
      if (valor == "1") {
        ledcWrite(pinMotor1F, 0);
        ledcWrite(pinMotor1T, 0);
        Serial.println("Comando: Parar Motor 1");
      }
      if (valor == "2") {
        ledcWrite(pinMotor2F, 0);
        ledcWrite(pinMotor2T, 0);
        Serial.println("Comando: Parar Motor 2");
      }
    }

    //Comando para Acionar o Motor para FRENTE
    if ((comando[0] == 'f') || (comando[0] == 'F')) {
      if (valor == "1") {
        ledcWrite(pinMotor1F, velocidade);
        ledcWrite(pinMotor1T, 0);
        Serial.println("Comando: Motor 1 para Frente");
      }
      if (valor == "2") {
        ledcWrite(pinMotor2F, velocidade);
        ledcWrite(pinMotor2T, 0);
        Serial.println("Comando: Motor 2 para Frente");
      }
    }

    //Comando para Acionar o Motor para TRAS
    if ((comando[0] == 't') || (comando[0] == 'T')) {
      if (valor == "1") {
        ledcWrite(pinMotor1T, velocidade);
        ledcWrite(pinMotor1F, 0);
        Serial.println("Comando: Motor 1 para Trás");
      }
      if (valor == "2") {
        ledcWrite(pinMotor2T, velocidade);
        ledcWrite(pinMotor2F, 0);
        Serial.println("Comando: Motor 2 para Trás");
      }
    }

    //Comando para Mudar a Valocidade
    if ((comando[0] == 'v') || (comando[0] == 'V')) {
      velocidade = valor.toInt();
      Serial.print("Comando: Velocidade = ");
      Serial.println(velocidade);
    }
  }
}
