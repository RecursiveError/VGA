#include <vga.hpp>

char (*VGAframeBuffer)[SCREEN_W]; //7COLORS
volatile uint16_t lineCounter = 0;
volatile char PXL_OUT = 0;


ISR(TIMER1_OVF_vect){
  lineCounter = 0; // reset line counter
}

ISR(TIMER2_COMPB_vect)
{
  register char *rowPtr;

  switch (PXL_OUT){
    case 1:
    rowPtr = &(VGAframeBuffer[(lineCounter - 35)>>4][0]);
    //columnCounter = SCREEN_W;

    for(int i = 0; i<SCREEN_W;i++){
      PORTC = (*(rowPtr+i));
    }
    PORTC = 0;
    break;
  }

  lineCounter++;

  if ((lineCounter >= 35) && (lineCounter < 515) ){
    PXL_OUT = 1;
  }
  else{
    PXL_OUT = 0;
  }
}

void VGA_setup(){
    cli();
    DDRD = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;
    // TIMER1 FAST PWM MODE / 1024 Prescaler ~1.5Khz
    TCCR1A |= (1<<COM1B1) | (1<<WGM10) | (1<<WGM11);
    TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<< CS12) | (1<<CS10);
    TIMSK1 |= (1<<TOIE1);
    TIFR1 |= (1<<TOV1);

    //TIMER2 FAST PWM MODE / 8 Prescaler ~2Mhz
    TCCR2A  |= (1<<COM2B1) | (1<<WGM21) | (1<<WGM20);
    TCCR2B |= (1<<WGM22) | (1<<CS01);
    TIMSK2 |= (1<<OCIE2B);
    TIFR2 |= (1<<OCF2B);

    //Reset Timers
    //TCNT1 = 0;
    //TCNT2 = 0;
    OCR1A  = 259;
    OCR1B  = 0;
    OCR2A  = 63;
    OCR2B  = 7;
    lineCounter = 0;
    // ENABLE INTERRUPT
    sei();
}

void set_VGAbuffer(char (*framebuf)[SCREEN_W]){
    cli();
    if(framebuf) VGAframeBuffer = framebuf;
    sei();
}
