# esp32-amazon-dash-button
Detect Amazon Dash Button with ESP32.

Long push the button (until blue LED flashing), the button starts WiFi AP. ESP32 is looking for this AP, then connect and get information.

This means
- can detect the Dash Button its WiFi has not been configured
- need to push and HOLD the button
- (Maybe) drain more battery power than WiFi configured, DHCP listen hack.

I have used
- DOIT ESP32 DevKit v1
- Visual Studio Code + PlatformIO
- Amazon Dash Buttons
