#include <Arduino.h>
#include <LiquidCrystal.h>

// ===== LCD =====
LiquidCrystal lcd(12,11,5,4,3,2);

// ===== HARDWARE PINS =====
const int ledPins[4] = {6,7,8,9};               // left→right
const int buttonPins[4] = {A3,A2,A1,A0};        // mirrored wiring fix
const int buzzer = 10;

// ===== GAME VARIABLES =====
const int maxPattern = 50;
int pattern[maxPattern];
int playerIndex = 0;
int level = 1;
int speedDelay = 600;

// ===== GAME STATES =====
enum GameState { START, SHOW_PATTERN, PLAYER_INPUT, NEXT_LEVEL, LOSE };
GameState state = START;

// ===== FUNCTION PROTOTYPES =====
void startScreen();
void showPattern();
void playerInput();
void nextLevel();
void gameOver();
int readButton();
void flashLED(int led);
void waitForRelease();

// =========================
// SETUP
// =========================
void setup() {
  lcd.begin(16,2);

  for(int i=0;i<4;i++){
    pinMode(ledPins[i],OUTPUT);
    pinMode(buttonPins[i],INPUT_PULLUP);
  }

  pinMode(buzzer,OUTPUT);

  randomSeed(analogRead(A5));

  lcd.print("Memory Game!");
  delay(1500);
  lcd.clear();
}

// =========================
// MAIN LOOP
// =========================
void loop() {

  switch(state) {

    case START:
      startScreen();
      break;

    case SHOW_PATTERN:
      showPattern();
      break;

    case PLAYER_INPUT:
      playerInput();
      break;

    case NEXT_LEVEL:
      nextLevel();
      break;

    case LOSE:
      gameOver();
      break;
  }
}

// =========================
// START SCREEN
// =========================
void startScreen() {

  lcd.clear();
  lcd.print("Press Button");
  lcd.setCursor(0,1);
  lcd.print("To Start");

  int btn = readButton();  // fresh press
  waitForRelease();

  level = 1;
  playerIndex = 0;
  speedDelay = 600;
  state = NEXT_LEVEL;
}

// =========================
// NEXT LEVEL
// =========================
void nextLevel() {

  pattern[level-1] = random(0,4);

  lcd.clear();
  lcd.print("Level ");
  lcd.print(level);

  delay(1000);

  state = SHOW_PATTERN;
}

// =========================
// SHOW PATTERN
// =========================
void showPattern() {

  lcd.clear();
  lcd.print("Watch!");

  for(int i=0;i<level;i++){
    flashLED(pattern[i]);
    delay(200);
  }

  playerIndex = 0;
  waitForRelease();

  lcd.clear();
  lcd.print("Your Turn");
  state = PLAYER_INPUT;
}

// =========================
// PLAYER INPUT
// =========================
void playerInput() {

  int btn = readButton();  // waits for fresh press

  flashLED(btn);

  if(btn == pattern[playerIndex]){
    playerIndex++;
    if(playerIndex >= level){
      level++;
      if(speedDelay > 200) speedDelay -= 20;
      state = NEXT_LEVEL;
    }
  }
  else{
    state = LOSE;
  }
}

// =========================
// GAME OVER
// =========================
void gameOver() {

  lcd.clear();
  lcd.print("You Lose!");
  lcd.setCursor(0,1);
  lcd.print("Score:");
  lcd.print(level-1);

  tone(buzzer,200,500);
  delay(3000);

  state = START;
}

// =========================
// READ BUTTON (Fresh Press)
// =========================
int readButton() {

  // wait until all buttons are released
  while(true){
    bool anyPressed = false;
    for(int i=0;i<4;i++){
      if(digitalRead(buttonPins[i]) == LOW){
        anyPressed = true;
      }
    }
    if(!anyPressed) break;
  }

  // wait for a NEW press
  while(true){
    for(int i=0;i<4;i++){
      if(digitalRead(buttonPins[i]) == LOW){
        delay(30);  // debounce
        if(digitalRead(buttonPins[i]) == LOW){
          return i;
        }
      }
    }
  }
}

// =========================
// FLASH LED
// =========================
void flashLED(int led) {
  digitalWrite(ledPins[led],HIGH);
  tone(buzzer, 700 + led*200);
  delay(speedDelay);
  digitalWrite(ledPins[led],LOW);
  noTone(buzzer);
  delay(150);
}

// =========================
// WAIT FOR BUTTON RELEASE
// =========================
void waitForRelease() {
  while(true){
    bool pressed = false;
    for(int i=0;i<4;i++){
      if(digitalRead(buttonPins[i]) == LOW){
        pressed = true;
      }
    }
    if(!pressed){
      delay(100);
      return;
    }
  }
}