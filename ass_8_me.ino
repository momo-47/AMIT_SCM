#define Signal_A 12
#define Signal_B 13
#define Signal_C 7
#define Signal_D 8

#define PWM_pinA 5
#define PWM_pinB 6

String str = "";
String PWM_String = "";
char x;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(Signal_A, OUTPUT);
  pinMode(Signal_B, OUTPUT);
  pinMode(Signal_C, OUTPUT);
  pinMode(Signal_D, OUTPUT);

  pinMode(PWM_pinA, OUTPUT);
  pinMode(PWM_pinB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    x = Serial.read();
    str += x;
    delay(2);
  }
  if (str.substring(0, 2) == "M1") {
    if (str.substring(2, 4) == "CW") {
      digitalWrite(Signal_A, HIGH);
      digitalWrite(Signal_B, LOW);
      PWM_String += str.substring(4);
      value = PWM_String.toInt();
      analogWrite(PWM_pinA, value);
      Serial.println(value);
      str = "";
      PWM_String = "";
    }
    else if (str.substring(2, 5) == "CCW") {
      digitalWrite(Signal_A, LOW);
      digitalWrite(Signal_B, HIGH);
      PWM_String += str.substring(5);
      value = PWM_String.toInt();
      analogWrite(PWM_pinA, value);
      Serial.println(value);
      str = "";
      PWM_String = "";
    }

    else if (str.substring(0, 2) == "M2") {
      if (str.substring(2, 4) == "CW") {
        digitalWrite(Signal_C, HIGH);
        digitalWrite(Signal_D, LOW);
        PWM_String += str.substring(4);
        value = PWM_String.toInt();
        analogWrite(PWM_pinB, value);
        Serial.println(value);
        str = "";
        PWM_String = "";
      }
      else if (str.substring(2, 5) == "CCW") {
        digitalWrite(Signal_C, LOW);
        digitalWrite(Signal_D, HIGH);
        PWM_String += str.substring(5);
        value = PWM_String.toInt();
        analogWrite(PWM_pinB, value);
        Serial.println(value);
        str = "";
        PWM_String = "";
      }


    }
  }}
