
////////////////////////////VARIABLES GLOBALES////////////////////////////////
#include <SoftwareSerial.h>

//Variables Globales
char BT_recibido;
#define config A0
#define sensorMov A1

//Variables Globales 
SoftwareSerial BT ( 0 , 1 ); //Rx Tx

//Variables Globales Motores
#define motor1 5
#define motor2 3
#define motor3 6
#define motor4 9

#define motor1_1 8
#define motor1_2 7
#define motor2_1 2
#define motor2_2 4
#define motor3_1 11
#define motor3_2 10
#define motor4_1 12
#define motor4_2 13


/////////////////////////////////SETUP/////////////////////////////////////


void setup()
{
  //Configurar pines
  pines();
  
  //Iniciar Consola
  Serial.begin( 9600 );
  
}//fin setup


//////////////////////////////////LOOP/////////////////////////////////////


void loop()
{
  configurarBT();
  
  if ( leerMovimiento() )
  {  comunicacion() ;  }

  switch ( BT_recibido )
  {
    case 'w':
  		avanzar();
  		break;
  	case 's':
  		retroceder();
  		break;
  	case 'a':
  		girarIzq();
  		break;
  	case 'd':
  		girarDer();
  		break;
  	case 'f':
  		frenarDespacio();
  		break;
  	case 'x':
  		frenarInstantaneo();
  		break;
  	case 'q':
  		girarIzqEnSuEje();
  		break;
  	case 'e':
  		girarDerEnSuEje();
  		break;
  }
  
  delay( 10 );
  
}//fin loop


////////////////////////////////FUNCIONES///////////////////////////////////


void pines()
{
  int pin[14] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2, motor2_1, motor2_2,
                    motor3_1, motor3_2, motor4_1, motor4_2, config, sensorMov };
  int estado[14] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 };
  for ( int i ; i > 14 ; i++ )
  {
    pinMode( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion pines


void serialEvent()  
{
  while ( Serial.available() )
  {
    BT_recibido = Serial.read();
    
  }//fin while
  Serial.flush();
  
}//fin funcion serialEvent


void configurarBT()
{
  if ( analogRead(config) )
  {
    if ( BT.available() )
    {
      Serial.write( BT.read() ) ; 
    }//fin if

    if ( Serial.available() )
    {
      BT.write( Serial.read() );
    }//fin if

  }//fin if config

}//fin funcion configurarBT


bool leerMovimiento()
{
  bool pirvalor = analogRead ( sensorMov ) ;
  return pirvalor ;

}//fin funcion leerMovimiento


void comunicacion()
{
  if ( !BT.available() )
  {  Serial.write ("Hay un objeto adelante") ;  }
  
  delay ( 100 );
  
}//fin funcion comunicacion


/////////////////////////////Movimiento/////////////////////////////////////


void avanzar()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion avanzar


void retroceder()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion retroceder


void frenarDespacio()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion frenarDespacio


void frenarInstantaneo()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion frenarInstantaneo


////////////////////////////////GIRAR//////////////////////////////////////


void girarIzq()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion girarIzq


void girarDer()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion girarDer


void girarIzqEnSuEje()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 0};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion girarIzqEnSuEje


void girarDerEnSuEje()
{
  int pin[12] 	= { motor1, motor2, motor3, motor4, motor1_1, motor1_2,
                   motor2_1, motor2_2, motor3_1, motor3_2, motor4_1, motor4_2 };
  int estado[12] = { 255 , 255 , 255 , 255 , 1 , 0 , 0 , 1 , 1 , 0 , 0 , 1};
  for ( int i ; i > 12 ; i++ )
  {
    digitalWrite( pin[i] , estado[i] );
    analogWrite ( pin[i] , estado[i] );
  }//fin for
  
}//fin funcion girarDerEnSuEje
