#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#define Type DHT11

int sensePin = 4;
DHT dht(sensePin, Type);
float humidity;
float tempC;
float tempF;

// Wi-Fi settings
const char* ssid = "Speed-2.4G";         // Replace with your Wi-Fi SSID
const char* password = "tesla@1856"; // Replace with your Wi-Fi password

// void setup() {
//   Serial.begin(115200);
//   dht.begin();  // Initialize DHT sensor

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
// }

// void loop() {
//   if (WiFi.status() == WL_CONNECTED) {
//     HTTPClient http;

//     // Read temperature and humidity from DHT sensor
//     float temperature = dht.readTemperature();
//     float humidity = dht.readHumidity();
//     Serial.print("Temperature: ");
//     Serial.println(temperature);
//     Serial.print("Humidity: ");
//     Serial.println(humidity);
//     // Check if readings are valid
//     if (isnan(temperature) || isnan(humidity)) {
//       Serial.println("Failed to read from DHT sensor!");
//       return;
//     }

//     // Server URL (replace with the actual server IP address)
//     String serverURL = "http://localhost:5001/data"; 

//     // Prepare the JSON data to send
//     String jsonData = "{\"temperature\": " + String(temperature, 2) + ", \"humidity\": " + String(humidity, 2) + "}";

//     // Send the POST request
//     http.begin(serverURL);
//     http.addHeader("Content-Type", "application/json");
//     int httpResponseCode = http.POST(jsonData);

//     // Handle server response
//     if (httpResponseCode > 0) {
//       String response = http.getString();
//       Serial.println(httpResponseCode);
//       Serial.println(response);
//     } else {
//       Serial.print("Error on sending POST: ");
//       Serial.println(httpResponseCode);
//     }

//     http.end();  // Free resources
//   }

//   delay(2000);  // Send data every 2 seconds
// }

 
// void setup() {
 
//   Serial.begin(115200);
//   delay(4000);   //Delay needed before calling the WiFi.begin
 
//   WiFi.begin(ssid, password); 
 
//   while (WiFi.status() != WL_CONNECTED) { //Check for the connection
//     delay(1000);
//     Serial.println("Connecting to WiFi..");
//   }
 
//   Serial.println("Connected to the WiFi network");
 
// }
 
// void loop() {
 
//  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
//    HTTPClient http;   
 
//    http.begin("http://localhost:5001/data");  //Specify destination for HTTP request
//    //http.begin("http://jsonplaceholder.typicode.com/posts");  //Specify destination for HTTP request
//    http.addHeader("Content-Type", "text/plain");             //Specify content-type header
 
//    int httpResponseCode = http.POST("test=POSTING from ESP32");   //Send the actual POST request
 
//    if(httpResponseCode>0){
 
//     String response = http.getString();                       //Get the response to the request

//     Serial.println("Return code");
//     Serial.println(httpResponseCode);   //Print return code
//     Serial.println("Request answer");
//     Serial.println(response);           //Print request answer
 
//    }else{
 
//     Serial.print("Error on sending POST: ");
//     Serial.println(httpResponseCode);
 
//    }
 
//    http.end();  //Free resources
 
//  }else{
 
//     Serial.println("Error in WiFi connection");   
 
//  }
 
//   delay(10000);  //Send a request every 10 seconds
 
// }


// #include <WiFi.h>
// #include <HTTPClient.h>

// const char* ssid = "Bateman";
// const char* password = "Christian_Bale";

const char* apiUrl = "http://127.0.0.1:5000";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + String(apiUrl) + "... ");

  // sendHttpPost();
}

void loop() {
  HTTPClient http;

  // Specify the destination URL
  http.begin(apiUrl);

  // Set the content type to JSON (adjust accordingly based on your API requirements)
  http.addHeader("Content-Type", "application/json");

  // Create a JSON payload (adjust this based on your API's expected data format)
  String jsonData = "{\"key1\":\"value1\",\"key2\":\"value2\"}";

  // Send the POST request with the JSON data
  int httpResponseCode = http.POST(jsonData);

  // Check the response
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Print the response payload
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("HTTP POST request failed, error code: ");
    Serial.println(httpResponseCode);
  }

  // Close the connection
  http.end();
  delay(2000);
}

// void sendHttpPost() {
  // HTTPClient http;

  // // Specify the destination URL
  // http.begin(apiUrl);

  // // Set the content type to JSON (adjust accordingly based on your API requirements)
  // http.addHeader("Content-Type", "application/json");

  // // Create a JSON payload (adjust this based on your API's expected data format)
  // String jsonData = "{\"key1\":\"value1\",\"key2\":\"value2\"}";

  // // Send the POST request with the JSON data
  // int httpResponseCode = http.POST(jsonData);

  // // Check the response
  // if (httpResponseCode > 0) {
  //   Serial.print("HTTP Response code: ");
  //   Serial.println(httpResponseCode);

  //   // Print the response payload
  //   String payload = http.getString();
  //   Serial.println(payload);
  // } else {
  //   Serial.print("HTTP POST request failed, error code: ");
  //   Serial.println(httpResponseCode);
  // }

  // // Close the connection
  // http.end();
// }