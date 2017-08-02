
bool hasenoughtimepassed2(){                               // this function controlls how frequently the brightness values get sent to the led
 currentTime2 = millis();

  if(currentTime2 - prevTime2 >= normalInterval2){
    prevTime2 = currentTime2;
    return true;
  }
  else{
    return false;
  }
}


bool hasEnoughTimePassed(){                               // this function controlls how frequently the brightness values get sent to the led
  currentTime = millis();

  if(currentTime - prevTime >= normalInterval){
    prevTime = currentTime;
    return true;
  }
  else{
    return false;
  }

}
