#define saturation 200 // valeur max (et min) du calcul d'écart
#define Lmax 500 // longueurs extrêmes de vérin autorisées
#define Lmin 350
#define L0 410
#define Pi 3.1415927
const float rM = 200 ; // rayon de la plate forme mobile
const float rf = 270 ; // rayon de la plate forme fixe
const float beta = 0.009 ; // demi angle entre 2 rotules adjacentes sur la plate forme mobile (en rad)
const float alpha = 0.007 ; // demi angle entre 2 rotules adjacentes sur la plate forme fixe (en rad)
const float h = 460 ; // hauteur de la plate forme mobile en position de référence

#define K 10   // coefficients correcteurs (boucle position)
#define Kd 0
#define Ki 1

const int analogInPot1 = 2;  // Analog input pin : potentiomètre vérin 1
const int analogInPot2 = 1;  // Analog input pin : potentiomètre vérin 2
const int analogInPot3 = 0;  // Analog input pin : potentiomètre vérin 3
const int analogInPot4 = 5;  // Analog input pin : potentiomètre vérin 4
const int analogInPot5 = 4;  // Analog input pin : potentiomètre vérin 5
const int analogInPot6 = 3;  // Analog input pin : potentiomètre vérin 6
int E1 = 10;
int M1 = 11;
int E2 = 4;
int M2 = 5;
int E3 = 2;
int M3 = 3;
int E4 = 8;
int M4 = 9;
int E5 = 6;
int M5 = 7;
int E6 = 12;
int M6 = 13;


// coordonnées directes de consigne
float x = 0;
float y = 0;
float z = 0;
float theta_x = 0;
float theta_y = 0;
float theta_z = 0;

float L1 = L0;        // Longueur du vérin 1 (en mm)
float L2 = L0;        // Longueur du vérin 2 (en mm)
float L3 = L0;        // Longueur du vérin 3 (en mm)
float L4 = L0;        // Longueur du vérin 4 (en mm)
float L5 = L0;        // Longueur du vérin 5 (en mm)
float L6 = L0;        // Longueur du vérin 6 (en mm)
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
boolean top_mesure = LOW;

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
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(M5, OUTPUT);
  pinMode(M6, OUTPUT);
  attachInterrupt(0, depart_mesure, CHANGE);
}

void loop() {

    // fonctions consignes
    z = 10*cos(3*millis()/1000.);
    
    // Calcul des longueurs de consigne
    L1 = sqrt( sq((cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*cos(alpha)+x)+ sq((sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*sin(alpha)+y)+ sq(-cos(theta_x)*sin(theta_y)*rM*cos(beta)-sin(theta_x)*rM*sin(beta)+h+z));
    L2 = sqrt( sq((cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)+rf*cos(1/3.*Pi+alpha)+x)+ sq((sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(beta)-rf*sin(1/3.*Pi+alpha)+y)+ sq(-cos(theta_x)*sin(theta_y)*rM*cos(beta)+sin(theta_x)*rM*sin(beta)+h+z));
    L3 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)+rf*sin(1/6.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)-rf*cos(1/6.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*cos(1/3.*Pi+beta)+sin(theta_x)*rM*sin(1/3.*Pi+beta)+h+z));
    L4 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)-sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*sin(1/6.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)+cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*cos(1/6.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*sin(1/6.*Pi+beta)+sin(theta_x)*rM*cos(1/6.*Pi+beta)+h+z));
    L5 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*cos(1/3.*Pi+alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*sin(1/6.*Pi+beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*cos(1/6.*Pi+beta)+rf*sin(1/3.*Pi+alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*sin(1/6.*Pi+beta)-sin(theta_x)*rM*cos(1/6.*Pi+beta)+h+z));
    L6 = sqrt( sq(-(cos(1/3.*Pi+theta_z)*cos(theta_y)-sin(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)+sin(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)-rf*cos(alpha)+x)+ sq(-(sin(1/3.*Pi+theta_z)*cos(theta_y)+cos(1/3.*Pi+theta_z)*sin(theta_x)*sin(theta_y))*rM*cos(1/3.*Pi+beta)-cos(1/3.*Pi+theta_z)*cos(theta_x)*rM*sin(1/3.*Pi+beta)+rf*sin(alpha)+y)+ sq(cos(theta_x)*sin(theta_y)*rM*cos(1/3.*Pi+beta)-sin(theta_x)*rM*sin(1/3.*Pi+beta)+h+z));
 
    // Calcul des longueurs de consigne
    // L1 = L0+10*cos(3*millis()/1000.);
    // L2 = L0+10*cos(3*millis()/1000.);
    // L3 = L0+10*cos(3*millis()/1000.);
    // L4 = L0+10*cos(3*millis()/1000.);
    // L5 = L0+10*cos(3*millis()/1000.);
    // L6 = L0+10*cos(3*millis()/1000.);

    // Acquisition des valeurs des potentiomètres
    potentiometre1 = 1.*analogRead(analogInPot1) / 1024.;
    potentiometre2 = 1.*analogRead(analogInPot2) / 1024.;
    potentiometre3 = 1.*analogRead(analogInPot3) / 1024.;
    potentiometre4 = 1.*analogRead(analogInPot4) / 1024.;
    potentiometre5 = 1.*analogRead(analogInPot5) / 1024.;
    potentiometre6 = 1.*analogRead(analogInPot6) / 1024.;

    // Calcul des longueurs de vérin
    Lmes1 = (potentiometre1 * (Lmax - Lmin)) + Lmin;
    Lmes2 = (potentiometre2 * (Lmax - Lmin)) + Lmin;
    Lmes3 = (potentiometre3 * (Lmax - Lmin)) + Lmin;
    Lmes4 = (potentiometre4 * (Lmax - Lmin)) + Lmin;
    Lmes5 = (potentiometre5 * (Lmax - Lmin)) + Lmin;
    Lmes6 = (potentiometre6 * (Lmax - Lmin)) + Lmin;
      
    // Initialisation des écarts
    eps1 = 0;
    eps2 = 0;
    eps3 = 0;
    eps4 = 0;
    eps5 = 0;
    eps6 = 0;

    // Calcul de la sortie du correcteur C du vérin 1
    if (Lmes1 > Lmin + 5 && Lmes1 < Lmax - 5) {
      der = ((L1 - Lmes1) - ecart1) / (millis() - dt) * 100;
      ecart1 = L1 - Lmes1;
      inte1 = inte1 + (millis() - dt) * ecart1 / 1000.;
     //  eps1 = K * (L1 - Lmes1) + Ki * inte1 + Kd * der;
      eps1 = K * (L1 - Lmes1);
    }

    // Calcul de la sortie du correcteur C du vérin 2
    if (Lmes2 > Lmin + 5 && Lmes2 < Lmax - 11) {
      der = ((L2 - Lmes2) - ecart2) / (millis() - dt) * 100;
      ecart2 = L2 - Lmes2;
      inte2 = inte2 + (millis() - dt) * ecart2 / 1000.;
      // eps2 = K * (L2 - Lmes2) + Ki * inte2 + Kd * der;
      eps2 = K * (L2 - Lmes2);
    }

    // Calcul de la sortie du correcteur C du vérin 3
    if (Lmes3 > Lmin + 5 && Lmes3 < Lmax - 5) {
      der = ((L3 - Lmes3) - ecart3) / (millis() - dt) * 100;
      ecart3 = L3 - Lmes3;
      inte3 = inte3 + (millis() - dt) * ecart3 / 1000.;
      // eps3 = K * (L3 - Lmes3) + Ki * inte3 + Kd * der;
      eps3 = K * (L3 - Lmes3);
    }

    // Calcul de la sortie du correcteur C du vérin 4
    if (Lmes4 > Lmin + 5 && Lmes4 < Lmax - 5) {
      der = ((L4 - Lmes4) - ecart4) / (millis() - dt) * 100;
      ecart4 = L4 - Lmes4;
      inte4 = inte4 + (millis() - dt) * ecart4 / 1000.;
      // eps4 = K * (L4 - Lmes4) + Ki * inte4 + Kd * der;
      eps4 = K * (L4 - Lmes4);
    }

    // Calcul de la sortie du correcteur C du vérin 5
    if (Lmes5 > Lmin + 5 && Lmes5 < Lmax - 5) {
      der = ((L5 - Lmes5) - ecart5) / (millis() - dt) * 100;
      ecart5 = L5 - Lmes5;
      inte5 = inte5 + (millis() - dt) * ecart5 / 1000.;
      // eps5 = K * (L5 - Lmes5) + Ki * inte5 + Kd * der;
      eps5 = K * (L5 - Lmes5);
    }

    // Calcul de la sortie du correcteur C du vérin 6
    if (Lmes6 > Lmin + 5 && Lmes6 < Lmax - 5) {
      der = ((L6 - Lmes6) - ecart6) / (millis() - dt) * 100;
      ecart6 = L6 - Lmes6;
      inte6 = inte6 + (millis() - dt) * ecart6 / 1000.;
      // eps6 = K * (L6 - Lmes6) + Ki * inte6 + Kd * der;
      eps6 = K * (L6 - Lmes6);
    }
    Serial.print(Lmes2);
    Serial.print(" ");
    Serial.println(eps2);
    dt = millis();
    
    // Mapping des sorties de correcteurs entre 0 et 255
    eps1 = constrain(eps1, -saturation, saturation);
    pwm1 = map(abs(eps1), 0, saturation, 0, 255) - .5;
    if (eps1 > 0){digitalWrite(M1, HIGH);}else{digitalWrite(M1, LOW);}
    eps2 = constrain(eps2, -saturation, saturation);
    pwm2 = map(abs(eps2), 0, saturation, 0, 255) - .5;
    if (eps2 > 0){digitalWrite(M2, HIGH);}else{digitalWrite(M2, LOW);}
    eps3 = constrain(eps3, -saturation, saturation);
    pwm3 = map(abs(eps3), 0, saturation, 0, 255) - .5;
    if (eps3 > 0){digitalWrite(M3, HIGH);}else{digitalWrite(M3, LOW);}
    eps4 = constrain(eps4, -saturation, saturation);
    pwm4 = map(abs(eps4), 0, saturation, 0, 255) - .5;
    if (eps4 > 0){digitalWrite(M4, HIGH);}else{digitalWrite(M4, LOW);}
    eps5 = constrain(eps5, -saturation, saturation);
    pwm5 = map(abs(eps5), 0, saturation, 0, 255) - .5;
    if (eps5 > 0){digitalWrite(M5, HIGH);}else{digitalWrite(M5, LOW);}
    eps6 = constrain(eps6, -saturation, saturation);
    pwm6 = map(abs(eps6), 0, saturation, 0, 255) - .5;
    if (eps6 > 0){digitalWrite(M6, HIGH);}else{digitalWrite(M6, LOW);}
        
    // Envoi des consignes aux vérins

    analogWrite(E1, pwm1);
    analogWrite(E2, pwm2);
    analogWrite(E3, pwm3);
    analogWrite(E4, pwm4);
    analogWrite(E5, pwm5);
    analogWrite(E6, pwm6);

    // test
    //  Serial.print("\t Lmes1 = ");
    //  Serial.print(Lmes1);
    //  Serial.print("\t Lmes2 = ");
    //  Serial.print(Lmes2);
    //  Serial.print("\t Lmes3 = ");
    //  Serial.print(Lmes3);
    //  Serial.print("\t Lmes4 = ");
    //  Serial.print(Lmes4);
    //  Serial.print("\t Lmes5 = ");
    //  Serial.print(Lmes5);
    //  Serial.print("\t Lmes6 = ");
    //  Serial.println(Lmes6);


    delayMicroseconds(10);
}

void depart_mesure()
{
  top_mesure = HIGH;
}
