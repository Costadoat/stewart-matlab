#define saturation 200 // valeur max (et min) du calcul d'écart
#define Lmax 510 // longueurs extrêmes de vérin autorisées
#define Lmin 410
#define Pi 3.1415927

#define K 10   // coefficients correcteurs (boucle position)
#define Kd 0
#define Ki 0

const float rM = 200 ; // rayon de la plate forme mobile
const float rf = 270 ; // rayon de la plate forme fixe
const float beta = 0.009 ; // demi angle entre 2 rotules adjacentes sur la plate forme mobile (en rad)
const float alpha = 0.007 ; // demi angle entre 2 rotules adjacentes sur la plate forme fixe (en rad)
const float h = 460 ; // hauteur de la plate forme mobile en position de référence

const int analogInPot1 = A0;  // Analog input pin : potentiomètre vérin 1
const int analogInPot2 = A1;  // Analog input pin : potentiomètre vérin 2
const int analogInPot3 = A2;  // Analog input pin : potentiomètre vérin 3
const int analogInPot4 = A3;  // Analog input pin : potentiomètre vérin 4
const int analogInPot5 = A4;  // Analog input pin : potentiomètre vérin 5
const int analogInPot6 = A5;  // Analog input pin : potentiomètre vérin 6
const int top_mesure = 4; // Sortie 4 pour lancer la mesure sur la carte NI
const int analogOutPin1 = 7; // Analog output pin : autoriser commande du vérin 1
const int analogOutPin2 = 8; // Analog output pin : autoriser commande du vérin 2
const int analogOutPin3 = 9; // Analog output pin : autoriser commande du vérin 3
const int analogOutPin4 = 10; // Analog output pin : autoriser commande du vérin 4
const int analogOutPin5 = 11; // Analog output pin : autoriser commande du vérin 5
const int analogOutPin6 = 12; // Analog output pin : autoriser commande du vérin 6

// coordonnées directes de consigne
float x = 0;
float y = 0;
float z = 0;
float theta_x = 0;
float theta_y = 0;
float theta_z = 0;

float L1 = 460;        // Longueur du vérin 1 (en mm)
float L2 = 460;        // Longueur du vérin 2 (en mm)
float L3 = 460;        // Longueur du vérin 3 (en mm)
float L4 = 460;        // Longueur du vérin 4 (en mm)
float L5 = 460;        // Longueur du vérin 5 (en mm)
float L6 = 460;        // Longueur du vérin 6 (en mm)
float Lmes1 = 0;  // Longueur mesurée du vérin 1 (mm)
float Lmes2 = 0;  // Longueur mesurée du vérin 2 (mm)
float Lmes3 = 0;  // Longueur mesurée du vérin 3 (mm)
float Lmes4 = 0;  // Longueur mesurée du vérin 4 (mm)
float Lmes5 = 0;  // Longueur mesurée du vérin 5 (mm)
float Lmes6 = 0;  // Longueur mesurée du vérin 6 (mm)
float potentiometre1 = 0;        // value read from the pot
float potentiometre2 = 0;        // value read from the pot
float potentiometre3 = 0;        // value read from the pot
float potentiometre4 = 0;        // value read from the pot
float potentiometre5 = 0;        // value read from the pot
float potentiometre6 = 0;        // value read from the pot
float pwm1 = 0;        // value output to the PWM
float pwm2 = 0;        // value output to the PWM
float pwm3 = 0;        // value output to the PWM
float pwm4 = 0;        // value output to the PWM
float pwm5 = 0;        // value output to the PWM
float pwm6 = 0;        // value output to the PWM
float eps1 = 0;        // erreur vérin 1
float eps2 = 0;        // erreur vérin 2
float eps3 = 0;        // erreur vérin 3
float eps4 = 0;        // erreur vérin 4
float eps5 = 0;        // erreur vérin 5
float eps6 = 0;        // erreur vérin 6

float dt = 0; // temps de la boucle (ms)

// Variables intermédiaires de calcul
float inte1 = 0;
float inte2 = 0;
float inte3 = 0;
float inte4 = 0;
float inte5 = 0;
float inte6 = 0;
float ecart1 = 0;
float ecart2 = 0;
float ecart3 = 0;
float ecart4 = 0;
float ecart5 = 0;
float ecart6 = 0;
float der = 0;

void setup() {
  Serial.begin(38400); 
  pinMode(analogOutPin1, OUTPUT);           
  pinMode(analogOutPin2, OUTPUT);           
  pinMode(analogOutPin3, OUTPUT);           
  pinMode(analogOutPin4, OUTPUT);           
  pinMode(analogOutPin5, OUTPUT);           
  pinMode(analogOutPin6, OUTPUT);           
  digitalWrite(analogOutPin1, LOW);           
  digitalWrite(analogOutPin2, LOW);           
  digitalWrite(analogOutPin3, LOW);           
  digitalWrite(analogOutPin4, LOW);           
  digitalWrite(analogOutPin5, LOW);           
  digitalWrite(analogOutPin6, LOW);           
  digitalWrite(top_mesure, LOW);           
  digitalWrite(top_mesure, HIGH);           
  }

void loop() {
// fonctions consignes
//  x = 10*cos(3*millis()/1000.);
//  y = 10*cos(3*millis()/1000.);
//  z = 10*cos(3*millis()/1000.);
//  theta_x = 0.1*cos(3*millis()/1000.);
//  theta_y = 0.1*cos(3*millis()/1000.);
//  theta_z = 0.3*cos(3*millis()/1000.);
  
  
// Calcul des longueurs de consigne
  L1 = sqrt( sq((cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*cos(alpha)+x)+ sq((sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*sin(alpha)+y)+ sq(-cos(theta_x)*sin(theta_y)*rM*cos(beta)-sin(theta_x)*rM*sin(beta)+h+z));
  L2 = sqrt( sq((cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)+rf*cos(1/3.*Pi+alpha)+x)+ sq((sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*sin(1/3.*Pi+alpha)+y)+ sq(-cos(theta_x)*sin(theta_y)*rM*cos(beta)+sin(theta_x)*rM*sin(beta)+h+z));
  L3 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)+rf*sin(1/6.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)-rf*cos(1/6.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*cos(1/3.*Pi+beta)+sin(theta_x)*rM*sin(1/3.*Pi+beta)+h+z));
  L4 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*sin(1/6.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*cos(1/6.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*sin(1/6.*Pi+beta)+sin(theta_x)*rM*cos(1/6.*Pi+beta)+h+z));
  L5 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*cos(1/3.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*sin(1/3.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*sin(1/6.*Pi+beta)-sin(theta_x)*rM*cos(1/6.*Pi+beta)+h+z));
  L6 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)-rf*cos(alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)+rf*sin(alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*cos(1/3.*Pi+beta)-sin(theta_x)*rM*sin(1/3.*Pi+beta)+h+z));
  
// Acquisition des valeurs des potentiomètres
  potentiometre1 = analogRead(analogInPot1)/1024.;            
  potentiometre2 = analogRead(analogInPot2)/1024.;            
  potentiometre3 = analogRead(analogInPot3)/1024.;            
  potentiometre4 = analogRead(analogInPot4)/1024.;            
  potentiometre5 = analogRead(analogInPot5)/1024.;            
  potentiometre6 = analogRead(analogInPot6)/1024.;            
  
// Calcul des longueurs de vérin
  Lmes1 = (potentiometre1*(Lmax-Lmin))+Lmin;
  Lmes2 = (potentiometre2*(Lmax-Lmin))+Lmin;
  Lmes3 = (potentiometre3*(Lmax-Lmin))+Lmin;
  Lmes4 = (potentiometre4*(Lmax-Lmin))+Lmin;
  Lmes5 = (potentiometre5*(Lmax-Lmin))+Lmin;
  Lmes6 = (potentiometre6*(Lmax-Lmin))+Lmin;
  
// Initialisation des écarts
  eps1 = 0;
  eps2 = 0;
  eps3 = 0;
  eps4 = 0;
  eps5 = 0;
  eps6 = 0;

// Calcul de la sortie du correcteur C du vérin 1
  if (Lmes1>Lmin+10 && Lmes1<Lmax-10) {
  der = ((L1-Lmes1)-ecart1)/(millis()-dt)*1000;  
  ecart1 = L1-Lmes1;
  inte1 = inte1 + (millis()-dt)*ecart1/1000.;
  eps1 = K*(L1-Lmes1) + Ki*inte1 + Kd*der;
  }

// Calcul de la sortie du correcteur C du vérin 2
  if (Lmes2>Lmin+10 && Lmes2<Lmax-10) {
  der = ((L2-Lmes2)-ecart2)/(millis()-dt)*1000;  
  ecart2 = L2-Lmes2;
  inte2 = inte2 + (millis()-dt)*ecart2/1000.;
  eps2 = K*(L2-Lmes2) + Ki*inte2 + Kd*der;
  }

// Calcul de la sortie du correcteur C du vérin 3
  if (Lmes3>Lmin+10 && Lmes3<Lmax-10) {
  der = ((L3-Lmes3)-ecart3)/(millis()-dt)*1000;  
  ecart3 = L3-Lmes3;
  inte3 = inte3 + (millis()-dt)*ecart3/1000.;
  eps3 = K*(L3-Lmes3) + Ki*inte3 + Kd*der;
  }

// Calcul de la sortie du correcteur C du vérin 4
  if (Lmes4>Lmin+10 && Lmes4<Lmax-10) {
  der = ((L4-Lmes4)-ecart4)/(millis()-dt)*1000;  
  ecart4 = L4-Lmes4;
  inte4 = inte4 + (millis()-dt)*ecart4/1000.;
  eps4 = K*(L4-Lmes4) + Ki*inte4 + Kd*der;
  }

// Calcul de la sortie du correcteur C du vérin 5
  if (Lmes5>Lmin+10 && Lmes5<Lmax-10) {
  der = ((L5-Lmes5)-ecart5)/(millis()-dt)*1000;  
  ecart5 = L5-Lmes5;
  inte5 = inte5 + (millis()-dt)*ecart5/1000.;
  eps5 = K*(L5-Lmes5) + Ki*inte5 + Kd*der;
  }

// Calcul de la sortie du correcteur C du vérin 6
  if (Lmes6>Lmin+10 && Lmes6<Lmax-10) {
  der = ((L6-Lmes6)-ecart6)/(millis()-dt)*1000;  
  ecart6 = L6-Lmes6;
  inte6 = inte6 + (millis()-dt)*ecart6/1000.;
  eps6 = K*(L6-Lmes6) + Ki*inte6 + Kd*der;
  }
   
  dt = millis();
  
// Mapping des sorties de correcteurs entre 0 et 255
  eps1 = constrain(eps1, -saturation, saturation);
  pwm1 = map(eps1, -saturation, saturation, 0, 255)-.5;  
  eps2 = constrain(eps2, -saturation, saturation);
  pwm2 = map(eps2, -saturation, saturation, 0, 255)-.5;  
  eps3 = constrain(eps3, -saturation, saturation);
  pwm3 = map(eps3, -saturation, saturation, 0, 255)-.5;  
  eps4 = constrain(eps4, -saturation, saturation);
  pwm4 = map(eps4, -saturation, saturation, 0, 255)-.5;  
  eps5 = constrain(eps5, -saturation, saturation);
  pwm5 = map(eps5, -saturation, saturation, 0, 255)-.5;  
  eps6 = constrain(eps6, -saturation, saturation);
  pwm6 = map(eps6, -saturation, saturation, 0, 255)-.5;  

// Envoi des consignes aux vérins
  digitalWrite(analogOutPin1, HIGH);           
  Serial.write(pwm1);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin1, LOW);

  digitalWrite(analogOutPin2, HIGH);           
  Serial.write(pwm2);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin2, LOW);

  digitalWrite(analogOutPin3, HIGH);           
  Serial.write(pwm3);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin3, LOW);

  digitalWrite(analogOutPin4, HIGH);           
  Serial.write(pwm4);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin4, LOW);

  digitalWrite(analogOutPin5, HIGH);           
  Serial.write(pwm5);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin5, LOW);

  digitalWrite(analogOutPin6, HIGH);           
  Serial.write(pwm6);
  delayMicroseconds(300); 
  digitalWrite(analogOutPin6, LOW);

  
// test  
//  Serial.print("\t L1 = ");      
//  Serial.print(L1);   
//  Serial.print("\t L2 = ");      
//  Serial.print(L2);   
//  Serial.print("\t L3 = ");      
//  Serial.print(L3);
//  Serial.print("\t L4 = ");      
//  Serial.print(L4);   
//  Serial.print("\t L5 = ");      
//  Serial.print(L5);   
//  Serial.print("\t L6 = ");      
//  Serial.println(L6);   


  delay(10); 
}
