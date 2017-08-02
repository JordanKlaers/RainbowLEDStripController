void checkforbuttons(){
  buttonnext = digitalRead(7);
  buttonback = digitalRead(8);
  rainbowbutton = digitalRead(9);

  if (buttonnext != previousbuttonnext) {                     //the loop function is always changing the value for the button (that lets us know its being pushed)

        options = 1;                                              // when single color button is pushed, it calls the function to update the color
        next();
      }
      if (buttonback != previousbuttonback){

        options = 1;                                             // when single color button is pushed, it calls the function to update the color
        back();
      }
      if (rainbowbutton != previousrainbowbutton){
        options = 0;
        rainbowselect();                                // this  command just reads if the button is pushed to select rainbow
      }
}

void BCsinglecolor(){
  slider = analogRead(A0);
  if (slider > (previousslider + 55) || slider < (previousslider -55) || (slider == 0 && previousslider != 0)){     //if the slider is zero and wasnt 0 previously, reupdate. if slider changes (more than it flickering) reupdate
    if (slider < 451){
      percentage = map(slider, 0, 450, 0, 30);
    }
    else if (slider > 450){
      percentage = map(slider, 451, 1023, 31, 100);
    }
    percentage = percentage/100;
    previousslider = slider;
    options = 1;                                       // when the slider moves, re update single color
  }
}

void BCrainbow(){
   slider = analogRead(A0);
 if (slider < 50){
   percentage = map(slider, 0, 49, 0, 0);
 }
  else if (slider > 49 && slider < 200){
    percentage = map(slider, 0, 199, 20, 20);
  }
  else if (slider > 199 && slider < 450){
    percentage = map(slider, 200, 449, 45, 45);
  }
  else if (slider > 449 && slider < 750){
    percentage = map(slider, 450, 750, 70, 70);
  }
  else if (slider >749){
    percentage = map(slider, 750, 1023, 100, 100);
  }
  percentage = percentage/100;
   previousslider = slider;


}


void next(){
  if (buttonnext == HIGH){
    if (colorwheel == 9){
      colorwheel = 0;
    }
    else {
      colorwheel += 1;
    }
    BC = 0;
    previousbuttonnext = buttonnext;
    prevTime2 = currentTime2;
  }
  else {
    previousbuttonnext = buttonnext;
  }
}


void back(){
   if (buttonback == HIGH){
     if (colorwheel == 0){
      colorwheel = 9;
    }
    else {
      colorwheel -= 1;
    }
    Serial.println(colorwheel);
    BC = 0;
    previousbuttonback = buttonback;
    prevTime2 = currentTime2;
  }
  else {
    previousbuttonback = buttonback;
  }
}


void rainbowselect(){
   if (rainbowbutton == HIGH){
    previousrainbowbutton = rainbowbutton;                      // change the state (helps compare to see if button is pushed)
    BC = 1;                                                   //when rainbow button pushed, this makes the slider read for rainbow pattern
    redbrightlvl = 225;                  // each time the rainbow pattern button is selected, it will start over
    greenbrightlvl = 0;
    bluebrightlvl = 0;
    transition = 1;
    prevTime2 = currentTime2;
  }
  else {
    previousrainbowbutton = rainbowbutton;
  }
}
