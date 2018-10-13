void lcdUpdate(){
    percentage = pwmValue / 2.5;
    lcd.setCursor ( 0, 0 );
    lcd.print("    Current RPM:    ");
    lcd.setCursor ( 0, 1 );
    lcd.print("        ");
    lcd.print(calculateRPM());
    lcd.print("        ");
    lcd.setCursor ( 0, 2 );
    lcd.print("      Percent:      ");
    lcd.setCursor ( 0, 3 );
    lcd.print("        ");
    lcd.print(percentage);
    lcd.print("       ");
}

void lcdWritepwmMinError(){
    percentage = pwmValue / 2.5;
    lcd.setCursor ( 0, 0 );
    lcd.print("    Current RPM:    ");
    lcd.setCursor ( 0, 1 );
    lcd.print("        ");
    lcd.print(calculateRPM());
    lcd.print("        ");
    lcd.setCursor ( 0, 2 );
    lcd.print("      Percent:      ");
    lcd.setCursor ( 0, 3 );
    lcd.print("   Already at 0%  ");
    delay(1000);
    lcdUpdate();
}

void lcdWritepwmMaxError(){
    percentage = pwmValue / 2.5;
    lcd.setCursor ( 0, 0 );
    lcd.print("    Current RPM:    ");
    lcd.setCursor ( 0, 1 );
    lcd.print("        ");
    lcd.print(calculateRPM());
    lcd.print("        ");
    lcd.setCursor ( 0, 2 );
    lcd.print("      Percent:      ");
    lcd.setCursor ( 0, 3 );
    lcd.print("  Already at 100% ");
    delay(1000);
    lcdUpdate();
}
