#include   
#include 
#include
#include	
#include
#define	false	0
#define true	1
#define maxsize 10

	


int i; 
char COMMAND[5] = {"AT","AT+CGATT=1","AT+CGDCONT=1,IP,INTERNET", "AT+CGACT=1,1","ATD*99#"};

char RESPONSES[5] = {"OK","OK","OK","OK","CONNECT"};

char tmpdata; // Used in receive function


int READY = false ;
int FLAG = true ;

  
void receive(int j);
void send(int k);
void initialize (void) ;



void main(void) 


    {
TRISD=0;
TRISCbits.TRISC6 =0;     
TRISCbits.TRISC7 =1; 
TRISAbits.TRISA4 =0; 
		
//configures Usart with boud rate 9600  ? (4*9600)/ 2400000 -1=624 
	
OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_SYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW,624);
PORTAbits.RA4= 1;

for (i=0;i<=4;++i)
{
send (i);
if(i==4) receive(7);
else   receive(2);
 while(FLAG)


        {
        if (strcmp(tmpdata,RESPONSES[i]))
   {
if (i==0)PORTDbits.RD0= 1;  // ok 
if (i==1)PORTDbits.RD1= 1;
if (i==2)PORTDbits.RD2= 1;
if (i==3)PORTDbits.RD3= 1;
if (i==4)PORTDbits.RD4= 1;
 Delay10TCYx( 5 );         
  READY = 1;
            FLAG = false;
        }

        else 


            {
if (i==0)PORTDbits.RD0= 0;  //error
if (i==1)PORTDbits.RD1= 0;
if (i==2)PORTDbits.RD2= 0;
if (i==3)PORTDbits.RD3= 0;
if (i==4)PORTDbits.RD4= 0;

Delay10TCYx( 5 );
            send(i);
            if(i==4) receive(7);
            else   receive(2);
        }

    }

    if (READY == 1)


        {
        FLAG = true;
    }

  }
  
}

void receive( int j)


    {
  
 if( DataRdyUSART( ))
     getsUSART(tmpdata,j); //read data ;
           

    }  
void send ( int k)

{
putsUSART(COMMAND[i]);
while(BusyUSART());
}
