let pontos = 0;

function mostraPontos(){
    fill('yellow');
    textAlign(CENTER);
    textSize(24);
    text(pontos, 110, 25);
}

function marcaPonto(){
    return pontos++;
}

function perdePonto(){
    if(pontosMaiorQueZero()){
        pontos--;
    }
}

function pontosMaiorQueZero(){
    return pontos > 0;
}