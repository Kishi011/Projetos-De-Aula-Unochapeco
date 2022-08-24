let canvasWidth = 600;
let canvasHeight = 400;

// variáveis da bolinha
let diametro = 30;
let raio = diametro/2;

// coordenadas
let xBolinha = /*canvasWidth*0.05*/ canvasWidth/2;
let yBolinha = canvasHeight/2;

// velocidade
let direcao = 1;
let velXBolinha = 5 * direcao;
let velYBolinha = 5;


// variáveis das Raquetes
let largura = 10;
let altura = 90;
let meiaAltura = altura/2;
let vel = 3;
let colidiu = false;


// P1
let xP1Raquete = canvasWidth*0.02;
let yP1Raquete = canvasHeight*0.5;


// CPU
let xCPURaquete = canvasWidth*0.98-largura;
let yCPURaquete = canvasHeight*0.5;


// funções da Bolinha
function inverteDirecao(){
  
  console.log('inverteu');
  return direcao *= -1;
}

function quandoTocaBorda(){
  
  if(xBolinha + raio >= canvasWidth   
     || xBolinha - raio <= 0){  

      inverteDirecao();
      velXBolinha *= direcao;
    }

  if(yBolinha + raio >= canvasHeight 
     || yBolinha - raio <= 0){

      velYBolinha *= -1;
    }
}

function quandoTocaRaquete(){
  
    if(xBolinha - raio <= xP1Raquete + largura 
    && yBolinha >= yP1Raquete-meiaAltura && yBolinha <= yP1Raquete+meiaAltura 
    || xBolinha + raio >= xCPURaquete
    && yBolinha >= yCPURaquete-meiaAltura && yBolinha <= yCPURaquete+meiaAltura){
      
       inverteDirecao();
       velXBolinha *= direcao;
     }
}

// função importada da bibliotace p5.collide2d.js
function colideComRaquete(){

  var colideP1Raquete = collideRectCircle(xP1Raquete, yP1Raquete, largura, altura, xBolinha, yBolinha, diametro);
  if(colideP1Raquete){
    inverteDirecao();
  }
}

function movimentaBolinha(){
  
  xBolinha += velXBolinha;
  yBolinha += velYBolinha;
}

function desenhaBolinha(){
  
  circle(xBolinha, yBolinha, diametro);  
}


// funções das Raquetes
function desenhaRaquete(x, y){
  
  rect(x, y - meiaAltura, largura, altura);
}

function raqueteColideComBorda(y, meiaAltura){

  if(y - meiaAltura < 0 || y + meiaAltura > canvasHeight){

    return true;
  }
  else{

    return false;
  }
}

function movimentaP1Raquete(){
  
  var colideComBorda = raqueteColideComBorda(yP1Raquete, meiaAltura);

  if(!colideComBorda){

    if(keyIsDown(UP_ARROW)){
     
      yP1Raquete -= vel;
    }
   
   if(keyIsDown(DOWN_ARROW)){
      
      yP1Raquete += vel;
    }
  }

  if(colideComBorda){

    if(yP1Raquete - meiaAltura < 0){
      
      yP1Raquete += 1;
    }
    if(yP1Raquete + meiaAltura > canvasHeight){
      
      yP1Raquete -= 1;
    }
  }
}

function movimentaCPURaquete(){

  var colideComBorda = raqueteColideComBorda(yCPURaquete, meiaAltura); 

  if(!colideComBorda){

    if(yBolinha - raio - 30 <= yCPURaquete-meiaAltura){
    
      yCPURaquete -= vel;
    }
  
    if(yBolinha + raio + 30 >= yCPURaquete+meiaAltura){
  
      yCPURaquete += vel;
    }
  }

  if(colideComBorda){

    if(yCPURaquete - meiaAltura < 0){
      
      yCPURaquete += 1;
    }
    if(yCPURaquete + meiaAltura > canvasHeight){
      
      yCPURaquete -= 1;
    }
  }
}


function setup() {
  createCanvas(canvasWidth, canvasHeight);
}

function draw() {
  background(0);
  desenhaBolinha();
  desenhaRaquete(xP1Raquete, yP1Raquete);
  desenhaRaquete(xCPURaquete, yCPURaquete);
  quandoTocaRaquete();
  //colideComRaquete();
  quandoTocaBorda();
  movimentaBolinha();
  movimentaP1Raquete();
  movimentaCPURaquete();
}