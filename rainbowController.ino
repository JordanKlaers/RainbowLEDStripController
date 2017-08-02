const int blue =  6 ;         // the number of the LED pin
const int green = 5;
const int red = 3;

int rainbowbutton = 0;
int previousrainbowbutton = 0;

int buttonnext = 0;
int previousbuttonnext = 0;

int buttonback = 0;
int previousbuttonback = 0;


int redbrightlvl = 225;                  // starting color will be red
int greenbrightlvl = 0;
int bluebrightlvl = 0;
int transition = 1;

int options = 1;                        //when options = 0 do the rainbow pattern, 1 = single color select

int colorwheel = 9;                 //which color to display for the single color option
int BC = 0;                       //1 converts slider data to 4 brightness levels for the tape, and 0 fades, for single color

float slider = 0;                   // variables for the silder to hold its value, and compare to its previous value
float previousslider = 0;
float percentage = 1.00;

unsigned long currentTime = 0;              //variables for how long to wait before updating the rainbow
unsigned long prevTime = 0;
unsigned long normalInterval = 20;

unsigned long currentTime2 = 0;              //variables for how long to wait before seeing again if a button is pushed (stops the button from being pressed too fast)
unsigned long prevTime2 = 0;
unsigned long normalInterval2 = 100;


int test = 0;                           // how many times to print to serial monitor in function tell me()

void setup() {
  // put your setup code here, to run once:
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (options == 0){
    rainbow();
  }
  else if (options == 1){
    colorselect(colorwheel);
  }

  checkforbuttons();



  if (hasenoughtimepassed2()){                                // reading the slider and converting it to single color, or rainbow
    if(BC == 0 ){                                             //this variable becomes 0 after a single color button is pushed - (need to find a way to reupdate the singlecolor
      BCsinglecolor();
    }
    else if (BC == 1){
      BCrainbow();
    }
  }
}
