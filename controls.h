void handleButton(){
  //Read Pins
  int read1 = analogRead(BUTTON1);
  int read2 = analogRead(BUTTON2);
  int read3 = analogRead(BUTTON3);
  int read4 = analogRead(BUTTON4);
  int read5 = analogRead(BUTTON5);
  int read6 = analogRead(BUTTON6);

  //Debugging
//  Serial.println("------");
//  Serial.println(read1);
//  Serial.println("------");
//  Serial.println(read2);
//  Serial.println("------");
//  Serial.println(read3);
//  Serial.println("------");
//  Serial.println(read4);
//  Serial.println("------");
//  Serial.println(read5);
//  Serial.println("------");
//  Serial.println(read6);
//  Serial.println("------");
  
  if (read1>500){
    Serial.println("Off Pressed");
    lastpwmValue = pwmValue;
    pwmValue = 0;
    lcdUpdate();
    delay(200);
  }else if (read2>500){
    Serial.println("On Pressed");
    pwmValue = lastpwmValue;
    lcdUpdate();
    delay(200);
  }else if (read3>500){
    Serial.println("-5 Pressed");
    Serial.println("Old PWM: ");
    Serial.println(pwmValue);
    if (pwmValue > pwmMin){
      newpwmValue = pwmValue - 5;
      Serial.println("Trying to set PWM to: ");
      Serial.println(newpwmValue);
      if (newpwmValue < pwmMin){
        newpwmValue = 75;
      }
      pwmValue = newpwmValue;
      Serial.println("New PWM: ");
      Serial.println(pwmValue);
      lcdUpdate();
    }
    else {
      lcdWritepwmMinError();
      lcdUpdate();
    }
    delay(200);
  }else if (read4>500){
    Serial.println("-10 Pressed");
    Serial.println("Old PWM: ");
    Serial.println(pwmValue);
    if (pwmValue > pwmMin){
      newpwmValue = pwmValue - 10;
      Serial.println("Trying to set PWM to: ");
      Serial.println(newpwmValue);
      if (newpwmValue < pwmMin){
        newpwmValue = 75;
      }
      pwmValue = newpwmValue;
      Serial.println("New PWM: ");
      Serial.println(pwmValue);
      lcdUpdate();
    }
    else {
      lcdWritepwmMinError();
      lcdUpdate();
    }
    delay(200);
  }else if (read5>500){
    Serial.println("+5 Pressed");
    Serial.println("Old PWM: ");
    Serial.println(pwmValue);
    if (pwmValue < pwmMax){
      newpwmValue = pwmValue + 5;
      Serial.println("Trying to set PWM to: ");
      Serial.println(newpwmValue);
      if (newpwmValue > pwmMax){
        newpwmValue = 250;
      }
      pwmValue = newpwmValue;
      Serial.println("New PWM: ");
      Serial.println(pwmValue);
      lcdUpdate();
    }
    else {
      lcdWritepwmMaxError();
      lcdUpdate();
    }
    delay(200);
  }else if (read6>500){
    Serial.println("+10 Pressed");
    Serial.println("Old PWM: ");
    Serial.println(pwmValue);
    if (pwmValue < pwmMax){
      newpwmValue = pwmValue + 10;
      Serial.println("Trying to set PWM to: ");
      Serial.println(newpwmValue);
      if (newpwmValue > pwmMax){
        newpwmValue = 250;
      }
      pwmValue = newpwmValue;
      Serial.println("New PWM: ");
      Serial.println(pwmValue);
      lcdUpdate();
    }
    else {
      lcdWritepwmMaxError();
      lcdUpdate();
    }
    delay(200);
  }else{
  }
}
