int ldr = 7;
int buffer = 0; // Buffer variable to store debounced value
unsigned long lastDebounceTime = 0; // Variable to store the last time the input was read

void setup() {
  pinMode(ldr, INPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the input
  int data = digitalRead(ldr);

  // Call the debounce function to get a stable value
  int debouncedData = debounce(data);

  // Print the debounced value to serial monitor
  Serial.println(debouncedData);

  // Delay to slow down the readings (optional)
  delay(100);
}

int debounce(int input) {
  // Define debounce time (adjust according to your needs)
  unsigned long debounceDelay = 50;

  // If the input has changed, reset the debounce timer
  if (input != buffer) {
    lastDebounceTime = millis();
  }

  // Check if the debounce delay has elapsed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Update the buffer with the new input value
    buffer = input;
  }

  // Return the debounced value
  return buffer;
}
