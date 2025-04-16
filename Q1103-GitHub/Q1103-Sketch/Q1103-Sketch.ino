#define pinMotor1F 9
#define pinMotor1T 10

#define pinMotor2F 6
#define pinMotor2T 5

String comando;
String valor;
int velocidade = 255;

void setup() {
  pinMode(pinMotor1F, OUTPUT);
  pinMode(pinMotor1T, OUTPUT);
  pinMode(pinMotor2F, OUTPUT);
  pinMode(pinMotor2T, OUTPUT);

  Serial.begin(9600);

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
        digitalWrite(pinMotor1F, LOW);
        digitalWrite(pinMotor1T, LOW);
        Serial.println("Comando: Parar Motor 1");
      }
      if (valor == "2") {
        digitalWrite(pinMotor2F, LOW);
        digitalWrite(pinMotor2T, LOW);
        Serial.println("Comando: Parar Motor 2");
      }
    }

    //Comando para Acionar o Motor para FRENTE
    if ((comando[0] == 'f') || (comando[0] == 'F')) {
      if (valor == "1") {
        analogWrite(pinMotor1F, velocidade);
        analogWrite(pinMotor1T, 0);
        Serial.println("Comando: Motor 1 para Frente");
      }
      if (valor == "2") {
        analogWrite(pinMotor2F, velocidade);
        analogWrite(pinMotor2T, 0);
        Serial.println("Comando: Motor 2 para Frente");
      }
    }

    //Comando para Acionar o Motor para TRAS
    if ((comando[0] == 't') || (comando[0] == 'T')) {
      if (valor == "1") {
        analogWrite(pinMotor1F, 0);
        analogWrite(pinMotor1T, velocidade);
        Serial.println("Comando: Motor 1 para Trás");
      }
      if (valor == "2") {
        analogWrite(pinMotor2F, 0);
        analogWrite(pinMotor2T, velocidade);
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
