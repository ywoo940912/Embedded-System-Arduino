//Parking timer

unsigned long start, finished, elapsed;

void setup() 
{
Serial.begin(9600);
pinMode(2, INPUT);
pinMode(3, INPUT);
Serial.println("Press 1 for Start/reset, 2 for elapsed time");

}

void displayResult() 
{
float h, m, s, ms;
unsigned long over;
int ticketPrice;
elapsed = finished - start;
h = int(elapsed / 3600000);
over = elapsed % 3600000;
m = int(over / 60000);
ticketPrice = h * 10;

Serial.print("Hours you parked : ");
Serial.print(h, 0);
Serial.print("h ");
Serial.print(m, 0);
Serial.println("m");
Serial.print("Estimated parking price: ");
Serial.print(ticketPrice, "dollars");
}

void loop()
{
  if (digitalRead(2) == HIGH)
  {
    start = millis();
    delay(200);
    Serial.println("Started...");
    }
   if(digitalRead(3) == HIGH)
   {
    finished = millis();
    delay(200);
    displayResult();
    }
  }
