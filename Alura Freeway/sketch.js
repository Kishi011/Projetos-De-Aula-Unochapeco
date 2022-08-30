function setup() {
  createCanvas(500, 400);
  tocaTrilhaSonora();
}

function draw() {
  // mostra sprites
  background(fundo);
  mostraAtor();
  mostraCarro();
  // movimenta
  movimentaCarro();
  movimentaAtor();
  // ações do jogo
  voltaXCarro();
  chegouNoFinal();
  colideComCarro();
  mostraPontos();
}