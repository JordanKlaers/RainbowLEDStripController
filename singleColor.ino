void colorselect(int colorwheel){
  switch(colorwheel){
    case 0:
      analogWrite(red, (225 * percentage));
      analogWrite(green, (80 * percentage));
      analogWrite(blue, (0 * percentage));
      break;
    case 1:
      analogWrite(red, (225 * percentage));
      analogWrite(green, (225 * percentage));
      analogWrite(blue, (0 * percentage));
      break;
    case 2:
      analogWrite(red, (128 * percentage));
      analogWrite(green, (225 * percentage));
      analogWrite(blue, (0 * percentage));
      break;
    case 3:
      analogWrite(red, (0 * percentage));
      analogWrite(green, (225 * percentage));
      analogWrite(blue, (0 * percentage));
      break;
    case 4:
      analogWrite(red, (0 * percentage));
      analogWrite(green, (225 * percentage));
      analogWrite(blue, (225 * percentage));
      break;
    case 5:
      analogWrite(red, (0 * percentage));
      analogWrite(green, (0 * percentage));
      analogWrite(blue, (225 * percentage));
      break;
    case 6:
      analogWrite(red, (127 * percentage));
      analogWrite(green, (0 * percentage));
      analogWrite(blue, (225 * percentage));
      break;
    case 7:
      analogWrite(red, (225 * percentage));
      analogWrite(green, (0 * percentage));
      analogWrite(blue, (225 * percentage));
      break;
    case 8:
      analogWrite(red, (225 * percentage));
      analogWrite(green, (0 * percentage));
      analogWrite(blue, (80 * percentage));
      break;
      case 9:
      analogWrite(red, (225 * percentage));
      analogWrite(green, (0 * percentage));
      analogWrite(blue, (0 * percentage));
      break;
  }
  options = 2;                                    // if options is two, nothing runs, the single color stay, and once a button is pushed it will change again
}
