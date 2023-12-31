#include <main.h>
#fuses NOWDT, XT, PUT, NOPROTECT
#use delay(clock=20000000)

const char TEXT []={"       ISIMG "};

int i,j,k,d,n,m,s,DATA;
//------------------------------------------------------------------
const char FONT1[32][7] ={
   0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,   //        Space
   0xFB,0xFB,0xFB,0xFB,0xFB,0xFF,0xFB,   //        !
   0xF5,0xF5,0xF5,0xFF,0xFF,0xFF,0xFF,   //        "
   0xF5,0xF5,0xE0,0xF5,0xE0,0xF5,0xF5,   //        #
   0xFB,0xF0,0xEB,0xF1,0xFA,0xE1,0xFB,   //        $
   0xE3,0xEA,0xE5,0xFB,0xF4,0xEA,0xF8,   //        %
   0xF7,0xEB,0xEB,0xF7,0xEA,0xED,0xF2,   //        &
   0xF9,0xF9,0xFD,0xFB,0xFF,0xFF,0xFF,   //        '
   0xFD,0xFB,0xF7,0xF7,0xF7,0xFB,0xFD,   //        (
   0xF7,0xFB,0xFD,0xFD,0xFD,0xFB,0xF7,   //        )
   0xFB,0xEA,0xF1,0xFB,0xF1,0xEA,0xFB,   //        *
   0xFF,0xFB,0xFB,0xE0,0xFB,0xFB,0xFF,   //        +
   0xFF,0xFF,0xFF,0xF3,0xF3,0xFB,0xF7,   //        ,
   0xFF,0xFF,0xFF,0xF1,0xFF,0xFF,0xFF,   //        -
   0xFF,0xFF,0xFF,0xFF,0xFF,0xF3,0xF3,   //        .
   0xFF,0xFE,0xFD,0xFB,0xF7,0xEF,0xFF,   //        /
   0xF1,0xEE,0xEC,0xEA,0xE6,0xEE,0xF1,   //        0
   0xFB,0xF3,0xFB,0xFB,0xFB,0xFB,0xF1,   //        1
   0xF1,0xEE,0xFE,0xF1,0xEF,0xEF,0xE0,   //        2
   0xF1,0xEE,0xFE,0xF9,0xFE,0xEE,0xF1,   //        3
   0xFD,0xF9,0xF5,0xED,0xE0,0xFD,0xFD,   //        4
   0xE0,0xEF,0xE1,0xFE,0xFE,0xFE,0xE1,   //        5
   0xF9,0xF7,0xEF,0xE1,0xEE,0xEE,0xF1,   //        6
   0xE0,0xFE,0xFD,0xFB,0xF7,0xF7,0xF7,   //        7
   0xF1,0xEE,0xEE,0xF1,0xEE,0xEE,0xF1,   //        8
   0xF1,0xEE,0xEE,0xF0,0xFE,0xFD,0xF3,   //        9
   0xFF,0xF3,0xF3,0xFF,0xF3,0xF3,0xFF,   //        :
   0xF3,0xFB,0xF3,0xF3,0xFF,0xF3,0xF3,   //        ;        
   0xFD,0xFB,0xF7,0xEF,0xF7,0xFB,0xFD,   //        <
   0xFF,0xFF,0xF1,0xFF,0xF1,0xFF,0xFF,   //        =
   0xF7,0xFB,0xFD,0xFE,0xFD,0xFB,0xF7,   //        >
   0xF1,0xEE,0xFE,0xFD,0xFB,0xFF,0xFB};  //        ?

const char FONT2[32][7] ={
   0xF1,0xEE,0xFE,0xF2,0xEA,0xEA,0xF1,   //        @
   0xFB,0xF5,0xEE,0xEE,0xE0,0xEE,0xEE,   //        A
   0xE1,0xF6,0xF6,0xF1,0xF6,0xF6,0xE1,   //        B
   0xF1,0xEE,0xEF,0xEF,0xEF,0xEE,0xF1,   //        C
   0xE1,0xF6,0xF6,0xF6,0xF6,0xF6,0xE1,   //        D
   0xE0,0xEF,0xEF,0xE3,0xEF,0xEF,0xE0,   //        E
   0xE0,0xEF,0xEF,0xE3,0xEF,0xEF,0xEF,   //        F
   0xF1,0xEE,0xEF,0xE8,0xEE,0xEE,0xF1,   //        G
   0xEE,0xEE,0xEE,0xE0,0xEE,0xEE,0xEE,   //        H
   0xF1,0xFB,0xFB,0xFB,0xFB,0xFB,0xF1,   //        I
   0xF8,0xFD,0xFD,0xFD,0xFD,0xFD,0xF3,   //        J
   0xEE,0xED,0xEB,0xE7,0xEB,0xED,0xEE,   //        K
   0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xE0,   //        L
   0xEE,0xE4,0xEA,0xEA,0xEE,0xEE,0xEE,   //        M
   0xEE,0xE6,0xEA,0xEC,0xEE,0xEE,0xEE,   //        N
   0xF1,0xEE,0xEE,0xEE,0xEE,0xEE,0xF1,   //        O
   0xE1,0xEE,0xEE,0xE1,0xEF,0xEF,0xEF,   //        P
   0xF1,0xEE,0xEE,0xEE,0xEA,0xED,0xF2,   //        Q
   0xE1,0xEE,0xEE,0xE1,0xEB,0xED,0xEE,   //        R  
   0xF1,0xEE,0xEF,0xF1,0xFE,0xEE,0xF1,   //        S
   0xE0,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,   //        T
   0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xF1,   //        U
   0xEE,0xEE,0xEE,0xF5,0xF5,0xFB,0xFB,   //        V
   0xEE,0xEE,0xEE,0xEA,0xEA,0xE4,0xEE,   //        W
   0xEE,0xEE,0xF5,0xFB,0xF5,0xEE,0xEE,   //        X
   0xEE,0xEE,0xF5,0xFB,0xFB,0xFB,0xFB,   //        Y
   0xE0,0xFE,0xFD,0xFB,0xF7,0xEF,0xE0,   //        Z
   0xF1,0xF7,0xF7,0xF7,0xF7,0xF7,0xF1,   //        [
   0xFF,0xEF,0xF7,0xFB,0xFD,0xFE,0xFF,   //        \
   0xF1,0xFD,0xFD,0xFD,0xFD,0xFD,0xF1,   //        [
   0xFB,0xF5,0xEE,0xFF,0xFF,0xFF,0xFF,   //        ^
   0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0};  //        _

const char FONT3[32][7] ={
   0xF3,0xF3,0xF7,0xFB,0xFF,0xFF,0xFF,   //        `
   0xFF,0xFF,0xF1,0xFE,0xF0,0xEE,0xF1,   //        a
   0xEF,0xEF,0xE9,0xE6,0xEE,0xE6,0xE9,   //        b
   0xFF,0xFF,0xF8,0xF7,0xF7,0xF7,0xF8,   //        c
   0xFE,0xFE,0xF2,0xEC,0xEE,0xEC,0xF2,   //        d
   0xFF,0xFF,0xF1,0xEE,0xE0,0xEF,0xF1,   //        e
   0xF9,0xF6,0xF7,0xE1,0xF7,0xF7,0xF7,   //        f
   0xFF,0xFF,0xF0,0xEE,0xF0,0xFE,0xF1,   //        g
   0xEF,0xEF,0xE9,0xE6,0xEE,0xEE,0xEE,   //        h
   0xFB,0xFF,0xF3,0xFB,0xFB,0xFB,0xF1,   //        i
   0xFD,0xFF,0xF9,0xFD,0xFD,0xFD,0xF3,   //        j
   0xF7,0xF7,0xF6,0xF5,0xF3,0xF5,0xF6,   //        k
   0xF3,0xFB,0xFB,0xFB,0xFB,0xFB,0xF1,   //        l
   0xFF,0xFF,0xE5,0xEA,0xEA,0xEA,0xEA,   //        m
   0xFF,0xFF,0xE9,0xE6,0xEE,0xEE,0xEE,   //        n
   0xFF,0xFF,0xF1,0xEE,0xEE,0xEE,0xF1,   //        o
   0xFF,0xFF,0xE1,0xEE,0xE1,0xEF,0xEF,   //        p
   0xFF,0xFF,0xF0,0xEE,0xF0,0xFE,0xFE,   //        q
   0xFF,0xFF,0xE9,0xE6,0xEF,0xEF,0xEF,   //        r
   0xFF,0xFF,0xF0,0xEF,0xF1,0xFE,0xE1,   //        s
   0xFB,0xFB,0xF0,0xFB,0xFB,0xFB,0xFC,   //        t
   0xFF,0xFF,0xEE,0xEE,0xEE,0xEC,0xF2,   //        u
   0xFF,0xFF,0xEE,0xEE,0xEE,0xF5,0xFB,   //        v
   0xFF,0xFF,0xEE,0xEE,0xEA,0xEA,0xF4,   //        w
   0xFF,0xFF,0xEE,0xF5,0xFB,0xF5,0xEE,   //        x
   0xFF,0xFF,0xEE,0xF5,0xFB,0xFB,0xF3,   //        y
   0xFF,0xFF,0xE0,0xFD,0xFB,0xF7,0xE0,   //        z
   0xF9,0xF7,0xF7,0xE7,0xF7,0xF7,0xF9,   //        {
   0xFB,0xFB,0xFB,0xFF,0xFB,0xFB,0xFB,   //        |
   0xF3,0xFD,0xFD,0xFC,0xFD,0xFD,0xF3,   //        }
   0xF5,0xEA,0xFF,0xFF,0xFF,0xFF,0xFF};  //        ~
//------------------------------------------------------------------
void main()
{//setup_adc_ports(no_ANALOG);




   OUTPUT_A(0x00);OUTPUT_B(0x00);
   while(TRUE)
   {
       for(j=0;j<8;j++)
       {      
       for(i=d;i<d+8;i++)
         {
         if (TEXT [i]<='?')DATA=~FONT1[TEXT [i]-' '][j];else
         if (TEXT [i]<='_')DATA=~FONT2[TEXT [i]-'@'][j];else
         if (TEXT [i]<='~')DATA=~FONT3[TEXT [i]-'`'][j];
         if(j==7)DATA=0x00;
         for(k=0;k<8;k++)
           {
           OUTPUT_BIT(PIN_A1,shift_left(&DATA,1,0)); // Permet de mettre la pin (PIN_A1) � l'�tat logique (shift_left(&DATA,1,0)) --shift_left: D�calage � gauche de 1 positions de la variable � DATA �
           if(k>=2){OUTPUT_HIGH(PIN_A0);OUTPUT_LOW (PIN_A0);}
           } 
         }
 OUTPUT_LOW (PIN_A1);
for(k=0;k<n;k++){OUTPUT_HIGH(PIN_A0);OUTPUT_LOW (PIN_A0);}
 //
       OUTPUT_HIGH(PIN_A2); //Permet de mettre � 1 la pin (PIN_A2)
       delay_ms(5);         //Temporisation de 5 secondes
       OUTPUT_LOW (PIN_A2); //Permet de mettre � 0 la pin (PIN_A2)
       OUTPUT_B(s+=1);      //La valeur s+=1 est envoy�e sur le port B
       }
       m+=1;
       if(m==5){m=0;n+=1;};
       if(n==6){n=0;d+=1;}
       if(d==12)d=0;
       
   }
}
//------------------------------------------------------------------

