void rainbow(){
  if(hasEnoughTimePassed()){
      prevTime = currentTime;
      analogWrite(red, (redbrightlvl * percentage));
      analogWrite(green, (greenbrightlvl * percentage));
      analogWrite(blue, (bluebrightlvl * percentage));
      if (transition == 1) {                                 // Transitions 1 through 10 execute the commands for fading between each color that I considered a "checkpoint" in the rainbow
        redtoorange();
      }
      else if (transition == 2) {
        orangetoyellow();
      }
      else if (transition == 3) {
        yellowtolimegreen();
      }
      else if (transition == 4) {
        limegreentogreen();
      }
      else if (transition == 5) {
        greentoturquoise();
      }
      else if (transition == 6) {
        turquoisetoblue();
      }
      else if (transition == 7) {
        bluetopurpley();
      }
      else if (transition == 8) {
        purpleytopurple();
      }
      else if (transition == 9) {
        purpletopink();
      }
      else if (transition == 10) {
        pinktored();
      }

   }
}






void redtoorange(){                                  //this function changes the brightness level of green so that the color displayed will fade from red to orange.
  greenbrightlvl += 1;
  if (greenbrightlvl >=79) {
    greenbrightlvl = 80;
    transition = 2;
  }
}

void orangetoyellow(){
  greenbrightlvl += 2;
  if (greenbrightlvl >= 220) {
    greenbrightlvl = 225;
    transition = 3;
  }
}

void yellowtolimegreen(){
  redbrightlvl -= 2;
  if (redbrightlvl <= 130) {
    redbrightlvl = 128;
    transition = 4;
  }
}

void limegreentogreen(){
  redbrightlvl -= 1;
  if (redbrightlvl <=2) {
    redbrightlvl = 0;
    transition = 5;
  }
}

void greentoturquoise(){
  bluebrightlvl += 3;
  if (bluebrightlvl >= 219) {
    bluebrightlvl = 225;
    transition = 6;
  }
}

void turquoisetoblue(){
  greenbrightlvl -= 3;
  if (greenbrightlvl <= 6) {
    greenbrightlvl = 0;
    transition = 7;
  }
}

void bluetopurpley(){
  redbrightlvl += 1;
  if (redbrightlvl >= 124) {
    redbrightlvl = 127;
    transition = 8;
  }
}

void purpleytopurple(){
  redbrightlvl += 2;
  if (redbrightlvl >=220) {
    redbrightlvl = 225;
    transition = 9;
  }
}

void purpletopink(){
  bluebrightlvl -= 3;
  if (bluebrightlvl <= 84) {
    bluebrightlvl = 80;
    transition = 10;
  }
}


void pinktored(){
  bluebrightlvl -= 1;
  if (bluebrightlvl <= 2) {
    bluebrightlvl = 0;
    transition = 1;
  }
}
