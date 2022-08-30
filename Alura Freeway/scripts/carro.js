// variáveis dos carros
let xCarros = [600, 600, 600, 600, 600, 600];
let yCarros = [40, 96, 150, 210, 265, 320];
let velCarros = [5, 3, 2.5, 6, 4, 3];

let larguraCarros = 50;
let alturaCarros = 40;

function mostraCarro(){
    for(let i = 0; i < imagemCarros.length; i++){
        image(imagemCarros[i], xCarros[i], yCarros[i], larguraCarros, alturaCarros);
    }
}
  
function movimentaCarro(){
    for(let i = 0; i < imagemCarros.length; i++){
        xCarros[i] -= velCarros[i];
    }
}

function voltaXCarro(){
    for(let i = 0; i < imagemCarros.length; i++){
        if(xCarros[i] < -50){
            xCarros[i] = 600;
        }
    }
}