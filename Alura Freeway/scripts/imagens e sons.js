// sprites do jogo
let ator;
let carro1;
let carro2;
let carro3;
let fundo;
// sons
let ost;
let snd_colide;
let snd_ponto;

// função de pré-carregamento, carrega antes da função setup
function preload(){
  // imagens
    fundo = loadImage("material/img/estrada.png");
    ator = loadImage("material/img/ator-1.png");
    carro1 = loadImage("material/img/carro-1.png");
    carro2 = loadImage("material/img/carro-2.png");
    carro3 = loadImage("material/img/carro-3.png");
    imagemCarros = [carro1, carro2, carro3, carro1, carro2, carro3];
    // sons
    ost = loadSound('material/sons/trilha.mp3');
    snd_colide = loadSound('material/sons/colidiu.mp3');
    snd_ponto = loadSound('material/sons/pontos.wav');
  }

function tocaTrilhaSonora(){
  ost.loop();
}

function tocaSomColisao(){
  snd_colide.play();
}

function tocaSomPonto(){
  snd_ponto.play();
}