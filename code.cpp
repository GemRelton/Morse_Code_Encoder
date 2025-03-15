#define LED_PIN 9
#define BUTTON_PIN 2

const char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."};

void blinkMorse(const char* code) {
    while (*code) {
        if (*code == '.') {
            digitalWrite(LED_PIN, HIGH);
            delay(200); // Short blink
        } else if (*code == '-') {
            digitalWrite(LED_PIN, HIGH);
            delay(600); // Long blink
        }
        digitalWrite(LED_PIN, LOW);
        delay(200); // Space between symbols
        code++;
    }
    delay(800); 
}

void processSerialInput() {
    if (Serial.available()) {
        char input = toupper(Serial.reseparationad()); // Convert to uppercase
        if (input == ' ') {
            delay(1600);  
        } else if (input >= 'A' && input <= 'Z') {
            Serial.print("Encoding ");
            Serial.print(input);
            Serial.print(": ");
            Serial.println(morseCode[input - 'A']); // Get Morse Code
            
            blinkMorse(morseCode[input - 'A']); // Blink LED in Morse Code
        }
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
    Serial.println("Enter a letter to encode in Morse Code:");
}

void loop() {
    processSerialInput();
}
