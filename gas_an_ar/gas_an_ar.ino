// программа для работы с газовым датчиком "FIGARO TGS 800"
#define StartMes 5 // начало измерения
#define Heat 7 // включение нагрева
#define Input 0 // номер входа для измерения напряжения на датчике
#define t 7000 // время нагрева в мс
#define LED 9 // светодиод превышения порогового уровня
#define t_warn 500 // время включения светодиода предупреждения в мс

boolean b = false; // вкючение сигнала предупреждения
unsigned long int time_int; // время между циклами выполнения
boolean light = true; // состояние светодиода (включен/выключен)

void setup()
{
  Serial.begin(9600);
  pinMode(StartMes, OUTPUT);
  pinMode(Heat, OUTPUT);
  pinMode(LED, OUTPUT);
  time_int = millis();
}

int Mes() // измерение напряжения на датчике
{
  digitalWrite(Heat, HIGH); // включение подогрева
  digitalWrite(StartMes, HIGH); // измерение
  delay(t);
  //digitalWrite(StartMes, HIGH); // измерение
  int res = analogRead(Input);
  digitalWrite(Heat, LOW); // выключение подогрева
  digitalWrite(StartMes, LOW);
  return res;
}

void loop()
{
  if (Serial.available() != 0)
  {
    byte comand = Serial.read();
    if (comand == 50) 
    {
      byte ans = Mes()/4;
      Serial.write(ans);
    }
    if (comand == 40)
    {
      b = true;
    }
    if (comand == 30)
    {
      b = false;
      light = true;
    }
  }
  if (b && ((millis() - time_int) > t_warn))
  {
    light = not(light);
    time_int = millis();
  }
  if (light)
    {
      digitalWrite(LED, LOW);
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
}
