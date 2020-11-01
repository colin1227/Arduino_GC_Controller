
#include <WiFiNINA.h>
#include "arduino_secrets.h"
const char* ssid     = SECRET_SSID;
const char* password = SECRET_PASS;

WiFiServer server(80);

void setup()
{
    pinMode(2, OUTPUT);
    delay(10);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(2, HIGH);
      delay(250);
      digitalWrite(2, LOW);
      delay(750);
    }
    
    for (int i = 0; i < 5; i++) {
      digitalWrite(2, HIGH);
      delay((1000 - (200 * i)) /2);
      digitalWrite(2, LOW);
      delay((1000 - (200 * i)) /2);
    }
    server.begin();
    delay(1000);
}

int value = 0;

void loop(){
 
 WiFiClient client = server.available();
 
 if (client) {
   boolean currentLineIsBlank = true;
   while (client.connected()) {
    if (client.available()) {
        digitalWrite(2, HIGH);
        client.flush();
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("<style>.controller.gc { background: url(https://gamepadviewer.com/gc-assets/base.svgz) no-repeat; height: 837px; width: 978px; } .gc.disconnected { background: url(https://gamepadviewer.com/gc-assets/disconnected.svgz) no-repeat; } .gc.disconnected div { display: none; } .gc .triggers { width: 775px; height: 95px; position: absolute; left: 102px; } .gc .trigger { width: 131px; height: 100%; background: url(https://gamepadviewer.com/gc-assets/trigger.svgz); opacity: 0; } .gc .trigger.left { float: left; } .gc .trigger.right { float: right; } .gc .bumper { width: 158px; height: 100%; background: url(https://gamepadviewer.com/gc-assets/buttons.svgz) no-repeat; background-position: -358px 0px; opacity: 0; } .gc .bumpers { position: absolute; width: 792px; height: 73px; left: 103px; top: 138px; } .gc .bumper.pressed { opacity: 1; } .gc .bumper.left { /* -webkit-transform: rotateY(180deg); */ /* transform: rotateY(180deg); */ float: left; display: none; } .gc .bumper.right { float: right; } /*Not needed, but I like keeping them here for posterity*/ /*.gc .quadrant{ position: absolute; background: url(https://gamepadviewer.com/gc-assets/player-n.svgz); height: 17px; width: 111px; top: 140px; left: 240px; } .gc .p0{ background-position: 0 -6px; } .gc .p1{ background-position: 0 -28px; } .gc .p2{ background-position: 0 -49px; } .gc .p3{ background-position: 0 -70px; }*/ .gc .arrows { position: absolute; width: 50px; height: 50px; top: 324px; left: 465px; } .gc .back, .gc .start { width: 43px; height: 43px; background: #E7E7E7; border-radius: 100%; border: solid 4.5px rgba(0, 0, 0, .65); background-clip: content-box; opacity: 0; } .gc .back.pressed, .gc .start.pressed { opacity: 1; filter: invert(1); -webkit-filter: invert(1); } .gc .back { display: none; } .gc .start { float: right; } .gc .abxy { position: absolute; width: 288px; height: 230px; top: 207px; left: 640px; } .gc .button { position: absolute; background: url(https://gamepadviewer.com/gc-assets/buttons.svgz); opacity: 0; } .gc .button.pressed { opacity: 1; } .gc .a { background-position: 0 0; width: 114px; height: 114px; bottom: 35px; left: 91px; } .gc .b { width: 71px; height: 71px; background-position: -116px 0; bottom: 0px; left: 1px; } .gc .x { width: 66px; height: 103px; background-position: -292px 0; top: 65px; right: 0px; } .gc .y { width: 103px; height: 66px; background-position: -189px 0; left: 67px; top: 2px; } .gc .sticks { position: absolute; width: 628px; height: 392px; top: 265px; left: 114px; } .gc .stick { position: absolute; } .gc .stick.left { top: 24px; left: 23px; background: url(https://gamepadviewer.com/gc-assets/left-stick.svgz) center no-repeat; height: 121px; width: 121px; } .gc .stick.right { top: calc(100% - 127px); left: calc(100% - 125px); background: url(https://gamepadviewer.com/gc-assets/cstick.svgz) center no-repeat; width: 84px; height: 84px; } .gc .dpad { position: absolute; width: 125px; height: 126px; top: 181px; left: 92px; } .gc .dpad { position: absolute; width: 130px; height: 130px; top: 497px; left: 263px; } .gc .face { background: url(https://gamepadviewer.com/gc-assets/dpad.svgz) no-repeat; position: absolute; opacity: 0; } .gc .face.up, .gc .face.down { width: 44px; height: 65px; } .gc .face.left, .gc .face.right { width: 65px; height: 44px; } .gc .face.up { left: 42px; top: 0; background-position: 0px 0px; } .gc .face.down { left: 42px; bottom: 0; background-position: -46px 0; } .gc .face.left { top: 43px; left: 0; background-position: -93px 0; } .gc .face.right { top: 43px; right: 0px; background-position: -160px 0; } .gc .face.pressed { opacity: 1; }</style>");
        client.println("<div class='controller gc active' id='gamepad-0'>");   
        client.println("<div class='triggers'>");
        client.println("<span class='trigger left' data-name='button-left-shoulder-bottom' style='opacity: 0;'></span>");
        client.println("<span class='trigger right' data-name='button-right-shoulder-bottom' style='opacity: 0;'></span>");
        client.println("<span class='trigger-button left' data-name='button-left-shoulder-bottom-digital'></span>");
        client.println("<span class='trigger-button right' data-name='button-right-shoulder-bottom-digital'></span>");
        client.println("<span class='clear'></span>");
        client.println("</div>");
        client.println("<div class='bumpers'>");
        client.println("<span class='bumper left' data-name='button-left-shoulder-top'></span>");
        client.println("<span class='bumper right' data-name='button-right-shoulder-top'></span>");
        client.println("<span class='clear'></span>");
        client.println("</div>");
        client.println("<div class='touchpad' data-name='touch-pad'></div>");
        client.println("<div class='quadrant p0'></div>");
        client.println("<div class='meta' data-name='button-meta'></div>");
        client.println("<div class='arrows'>");
        client.println("<span class='back' data-name='button-select'></span>");
        client.println("<span class='start' data-name='button-start'></span>");
        client.println("<span class='clear'></span>");
        client.println("</div>");
        client.println("<div class='abxy'>");
        client.println("<span class='button a' data-name='button-1'></span>");
        client.println("<span class='button b' data-name='button-2'></span>");
        client.println("<span class='button x' data-name='button-3'></span>");
        client.println("<span class='button y' data-name='button-4'></span>");
        client.println("</div>");
        client.println("<div class='sticks'>");
        client.println("<span class='stick left' data-name='stick-1' style='margin-left: 0px; margin-top: 0px; transform: rotateX(0deg) rotateY(0deg);'></span>");
        client.println("<span class='stick right' data-name='stick-2' style='margin-left: 0px; margin-top: 0px; transform: rotateX(0deg) rotateY(0deg);'></span>");
        client.println("</div>");
        client.println("<div class='wheels'>");
        client.println("<span class='wheel left' data-name='stick-1-wheel' style='transform: rotate(0deg);'></span>");
        client.println("<span class='wheel right' data-name='stick-2-wheel' style='transform: rotate(0deg);'></span>");
        client.println("</div>");
        client.println("<div class='dpad'>");
        client.println("<span class='face up' data-name='button-dpad-top'></span>");
        client.println("<span class='face down' data-name='button-dpad-bottom'></span>");
        client.println("<span class='face left' data-name='button-dpad-left'></span>");
        client.println("<span class='face right' data-name='button-dpad-right'></span>");
        client.println("</div>");
        client.println("<div class='fstick' data-name='arcade-stick'></div>");
        client.println("</div>");
        client.println("<script>");
        client.println("  let dirs = [];");
        client.println("  const buttonCorrelation = { A: { className: '.a' }, B: { className: '.b' }, X: { className: '.x' }, Z: { className: '.bumper.right' }, CUp: { className: '.stick.right', axis: 'Y', val: -22 }, CRight: { className: '.stick.right', axis: 'X', val: 22 }, CDown: { className: '.stick.right', axis: 'Y',  val: 22 }, R: { className: '.trigger.right' }, CLeft: { className: '.stick.right', axis: 'X', val: -22 }, Up: { className: '.stick.left',  axis: 'Y', val: -22 }, Down: { className: '.stick.left', axis: 'Y', val: 22 }, Right: { className: '.stick.left', axis: 'X', val: 22 }, Left: { className: '.stick.left', axis: 'X', val: -22 }, L: { className: '.trigger.left' }, start: { className: '.start' }, HardLeft: { className: '.stick.left', axis: 'X', val: -17 }, SoftLeft: { className: '.stick.left', axis: 'X', val: -6 }, SoftRight: { className: '.stick.left', axis: 'X', val: 6 }, HardRight: { className: '.stick.left', axis: 'X', val: 17 }};");
        client.println("  const buttonCorrelationValues = Object.values(buttonCorrelation)");
        client.println("  const buttonCorrelationKeys = Object.keys(buttonCorrelation)");
        client.println("  let nano33Socket = new WebSocket('" + String(WEB_SOCKET_HOST) + "');");
        client.println("  nano33Socket.onmessage = (msg) => {");
        client.println("    const pressedButtons = msg.data.includes(',') ? msg.data.split(',') : msg.data.length ? [msg.data] : [];");
        client.println("    dirs = [];");
        client.println("    for (let i = 0; i < buttonCorrelationValues.length; i++) {");
        client.println("      const button = document.querySelector(buttonCorrelationValues[i].className);");
//        
        client.println("      let isPressed = pressedButtons.indexOf(buttonCorrelationKeys[i]);");
        client.println("      if (isPressed >= 0 && Object.values(buttonCorrelationValues[i]).length > 1) {");
        client.println("        dirs.push(buttonCorrelationValues[i].className)");
        client.println("        if (buttonCorrelationValues[i].axis === 'Y') {");
        client.println("          button.style['margin-top'] = `${buttonCorrelationValues[i].val}px`;");
        client.println("          button.style['margin-left'] = '0px';");
        client.println("          button.style.transform = `rotateX(${buttonCorrelationValues[i].val}deg)`;");
        client.println("        } else {");
        client.println("          button.style['margin-left'] = `${buttonCorrelationValues[i].val}px`;");
        client.println("          button.style['margin-top'] = '0px';");
        client.println("          button.style.transform = `rotateY(${buttonCorrelationValues[i].val}deg)`;");
        client.println("        }");
        client.println("      } else if (isPressed == -1 && Object.values(buttonCorrelationValues[i]).length > 1 && !dirs.includes(buttonCorrelationValues[i].className)) {");
        client.println("        button.style['margin-top'] = '0px';");
        client.println("        button.style['margin-left'] = '0px';");
        client.println("        button.style.transform = 'rotateX(0deg) rotateY(0deg)';");
        client.println("      } else if (isPressed >= 0 && buttonCorrelationValues[i].className.includes('.trigger')) {");
        client.println("        button.style.opacity = 1;");
        client.println("      } else if (isPressed == -1 && ['L', 'R'].includes(buttonCorrelationKeys[i])) {");
        client.println("        button.style.opacity = 0;");
        client.println("      } else if (isPressed >= 0 && Object.values(buttonCorrelationValues[i]).length == 1) {");
        client.println("        button.classList.add('pressed');");
        client.println("      } else {");
        client.println("        button.classList.remove('pressed');");
        client.println("      }");
        client.println("    }");
        client.println("  }");
        client.println("</script>");
        client.println("</html>");
        digitalWrite(2, LOW);
    }
    delay(3000);
    client.stop();
    digitalWrite(2, LOW);
  }
 }
}
