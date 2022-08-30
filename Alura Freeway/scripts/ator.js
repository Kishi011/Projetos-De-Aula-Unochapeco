// variáveis do ator
let xAtor = 100;
let yAtor = 366;
let colisao = false;

function mostraAtor(){
    image(ator, xAtor, yAtor, 30, 30);
}

function movimentaAtor(){
    if(keyIsDown(UP_ARROW)){
      yAtor -= 3;
    }
    if(keyIsDown(DOWN_ARROW) && podeSeMover()){
      yAtor += 3;
    }
}

// essa função retorna um boolean
function podeSeMover(){
  return yAtor < 366;
}

function chegouNoFinal(){
  if(yAtor < -15){
    tocaSomPonto();
    marcaPonto();
    voltaYAtor();
  }
}

function voltaYAtor(){
    return yAtor = 366;
}

function colideComCarro(){
  for(let i = 0; i < imagemCarros.length; i++){
    if(colisao = collideRectCircle(xCarros[i], yCarros[i], larguraCarros, alturaCarros, xAtor, yAtor, 10)){
      tocaSomColisao();
      voltaYAtor();
      perdePonto();
    }
  }
}