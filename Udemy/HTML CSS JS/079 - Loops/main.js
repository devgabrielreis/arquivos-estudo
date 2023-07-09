var lista = document.getElementById('lista');
var frutas = ["Laranja", "Kiwi", "Morango", "Abacaxi", "Melancia"];
var usuario = {
    "nome": "Brunão",
    "profissao": "Designer",
    "idade": 31
};
var myList = [];

//For
// var nome = "Antonio";

// for (var i = 0; frutas.length > i; i++) {
//     console.log(frutas[i]);
//     myList.push('<li>' + frutas[i] + '</li>');
// }

//For In (for of tambem existe)
// var info;

// for (info in usuario) {
//     console.log(usuario[info]);
//     myList.push('<li>' + usuario[info] + '</li>');
// }

//While
// var n = 0;

// while (frutas.length > n) {
//     n++;
//     myList.push('<li> Tem Fruta' + n + '</li>');
// }

//Map
Object.entries(usuario).map(function (user) {
    var userData = user.join(': ')
    myList.push('<li>' + userData + '</li>');
});

lista.insertAdjacentHTML('beforeend', myList.join(''));
