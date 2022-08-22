let canvasWidth = 600;
let canvasHeight = 400;

// variáveis da bolinha
let diametro = 30;
let raio = diametro/2;

// coordenadas
let xBolinha = canvasWidth/2;
let yBolinha = canvasHeight/2;

// velocidade
let velXBolinha = 5;
let velYBolinha = 5;


// variáveis das Raquetes
let largura = 10;
let altura = 90;
let vel = 3;


// P1
let xP1Raquete = canvasWidth*0.02;
let yP1Raquete = canvasHeight*0.5;


// CPU
let xCPURaquete = canvasWidth*0.98-largura;
let yCPURaquete= canvasHeight*0.5;


// funções da Bolinha
function inverteDirecao(){
  
  velXBolinha *= -1;
}

function quandoTocaBorda(){
  
  if(xBolinha + raio >= canvasWidth   
     || xBolinha - raio <= 0){  

      inverteDirecao();
    }

  if(yBolinha + raio >= canvasHeight 
     || yBolinha - raio <= 0){

      velYBolinha *= -1;
    }
}

function quandoTocaRaquete(){
  
    if(xBolinha - raio <= xP1Raquete + largura 
    && yBolinha >= yP1Raquete-(altura/2) && yBolinha <= yP1Raquete-(altura/2) + altura
    || xBolinha + raio >= xCPURaquete
    && yBolinha >= yCPURaquete-(altura/2) && yBolinha <= yCPURaquete + altura){
      
       inverteDirecao();
     }
}

function movimentaBolinha(){
  
  xBolinha += velXBolinha;
  //yBolinha += velYBolinha;
}

function desenhaBolinha(){
  
  circle(xBolinha, yBolinha, diametro);  
}


// funções das Raquetes
function desenhaP1Raquete(){
  
  rect(xP1Raquete, yP1Raquete - altura/2, largura, altura);
}

function movimentaP1Raquete(){
  
  if(keyIsDown(UP_ARROW)){
     
     yP1Raquete -= vel;
     }
  
  if(keyIsDown(DOWN_ARROW)){
     
     yP1Raquete += vel;
     }
}

function desenhaCPURaquete(){
  
  rect(xCPURaquete, yCPURaquete - altura/2, largura, altura);
}


function setup() {
  createCanvas(canvasWidth, canvasHeight);
}

function draw() {
  background(0);
  desenhaBolinha();
  desenhaP1Raquete();
  desenhaCPURaquete();
  quandoTocaRaquete();
  quandoTocaBorda();
  movimentaBolinha();
  movimentaP1Raquete();
}