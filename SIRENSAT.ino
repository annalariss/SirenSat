
#include <WiFi.h>
#include <WebServer.h>

// Substitua com o nome da sua rede Wi-Fi e senha
const char* ssid = "Santiago2G";
const char* password = "qgx8f2222";

// Cria um servidor web na porta 80
WebServer server(80);

// Página web com estilo CSS
void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head>";
  html += "<title>Sirensat</title>";
  html += "<style>";
  // CSS para estilizar a página
  html += "body { background: linear-gradient(to bottom right, #1e3a8a, #6d28d9, #ec4899); font-family: Arial, sans-serif; text-align: center; padding: 50px; color: #ffffff; }";
  html += "h1 { color: #ffffff; }";
  html += "p { font-size: 18px; color: #ffffff; margin: 20px 0; }";
  html += "img { max-width: 100%; height: auto; border-radius: 10px; margin: 20px 0; }";
  html += "footer { margin-top: 50px; font-size: 16px; }";
  html += "footer p { margin: 10px 0; }";
  html += "</style>";
  html += "</head>";
  html += "<body>";
  html += "<h1>Bem-vindo ao Sirensat!</h1>";
  html += "<p>Nosso projeto utiliza inteligência artificial para detectar lixo no mar e identificar o tipo de lixo. Através de um cubesat equipado com sensores e câmeras, buscamos contribuir para a limpeza dos oceanos e preservação ambiental.</p>";
  html += "<img src='https://example.com/imagem_coleta_lixo.jpg' alt='Coleta de Lixo no Mar'>";
  html += "<img src='https://example.com/imagem_cubesat.jpg' alt='Cubesat'>";
  html += "<footer>";
  html += "<p><strong>Alunas:</strong> ANNA LARISSA, CECILIA, MARIA CLARA, NATHALY</p>";
  html += "<p><strong>Professora:</strong> THAYSE</p>";
  html += "<p><strong>Mentora:</strong> NATÁLIA</p>";
  html += "</footer>";
  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}


void setup() {
  Serial.begin(115200);

  // Conectando ao Wi-Fi
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  
  // Aguarda a conexão ao Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }
  
  Serial.println("Conectado ao WiFi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Configura a rota principal ("/") para servir a página HTML
  server.on("/", handleRoot);

  // Inicia o servidor
  server.begin();
  Serial.println("Servidor iniciado!");
}

void loop() {
  // Lida com as solicitações do cliente
  server.handleClient();
}