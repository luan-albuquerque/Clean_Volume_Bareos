
//Projeto: Rastreador Solar
//Progamador:Luan Albuquerque dos Santos
//Resumo de Codigo Fonte do Arduino


#include <Servo.h>//Biblioteca Servo

//DEFINIÇÕES DE SERVOS

Servo servohori;//HORIZONTAL

int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti;//VERTICAL

int servov = 0;
int servovLimitHigh = 160;
int servovLimitLow = 20;

//ID DE PINOS DO ARDUINO NA VARIAVIES

int ldrtopl = 2; //LDR SUPERIOR ESQUERDO
int ldrtopr = 1; //LDR SUPERIOR DIREITO
int ldrbotl = 3; // LDR INFERIOR ESQUERDO
int ldrbotr = 0; // LDR INFERIOR DIREIRO

void setup ()
{
  //ID DE SERVOS NO ARDUINO
  //HORIZONTAL
  servohori.attach(10);
  servohori.write(0);//VALORES DA POSIÇÃO
  //VERTICAL
  servoverti.attach(9);
  servoverti.write(0);//VALORES DA POSIÇÃO

  delay(500);
}

void loop()
{

  servoh = servohori.read();
  servov = servoverti.read();

  //CAPTURANDO OS VALORES DO LDR E APLICANDO NAS VARIAVEIS

  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);

  //CALCULANDO A MEDIA ENTRE OS LDRS NAS EXTREMIDADE E APLICANDI EM UMA NOVA VARIAVEL

  int avgtop = (topl + topr) / 2; //MEDIA DE LDRS SUPERIORES0
  int avgbot = (botl + botr) / 2; //MEDIA DE LDRS INFEIRORES
  int avgleft = (topl + botl) / 2; //MEDIA DE LDRS A ESQUERDA
  int avgright = (topr + botr) / 2; //MEDIA DE LDRS A DIREITA

  if (avgtop < avgbot)
  {
    servoverti.write(servov + 1);
    if (servov > servovLimitHigh)
    {
      servov = servovLimitHigh;
    }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov - 1);
    if (servov < servovLimitLow)
    {
      servov = servovLimitLow;
    }
    delay(10);
  }
  else
  {
    servoverti.write(servov);
  }

  if (avgleft > avgright)
  {
    servohori.write(servoh + 1);
    if (servoh > servohLimitHigh)
    {
      servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh - 1);
    if (servoh < servohLimitLow)
    {
      servoh = servohLimitLow;
    }
    delay(10);
  }
  else
  {
    servohori.write(servoh);
  }
  delay(50);
}
