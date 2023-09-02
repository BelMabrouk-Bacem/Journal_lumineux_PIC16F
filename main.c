#include <main.h>
#fuses NOWDT, XT, PUT, NOPROTECT
#use delay(clock=20000000)

//const char TEXT []={"       I"};
int i,j,k,DATA,s;
//------------------------------------------------------------------

const char TEXT[1][7] ={0x0E,0x04,0x04,0x04,0x04,0x04,0x0E};  
//------------------------------------------------------------------
void main()
{//setup_adc_ports(no_ANALOG);

   OUTPUT_A(0x00);OUTPUT_B(0x00);
   while(TRUE)
   {  DATA=TEXT[i][j];
       for(j=0;j<8;j++)
       { 
         DATA=TEXT[i][j];
         for(k=0;k<8;k++)
           {
           OUTPUT_BIT(PIN_A1,shift_left(&DATA,1,0)); // Permet de mettre la pin (PIN_A1) � l'�tat logique (shift_left(&DATA,1,0)) --shift_left: D�calage � gauche de 1 positions de la variable � DATA �
           if(k>=1){OUTPUT_HIGH(PIN_A0);OUTPUT_LOW (PIN_A0);}
           }

       OUTPUT_HIGH(PIN_A2); //Permet de mettre � 1 la pin (PIN_A2)
       delay_ms(5);         //Temporisation de 5 secondes
       OUTPUT_LOW (PIN_A2); //Permet de mettre � 0 la pin (PIN_A2)
       OUTPUT_B(s+=1);      //La valeur s+=1 est envoy�e sur le port B
       }
   }
}
