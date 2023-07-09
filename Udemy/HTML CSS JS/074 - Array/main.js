var listaFrutas = document.getElementById('frutas');

var frutas = ["Laranja", "Kiwi", "Morango"];
frutas.push("Uva")

var myList = [];

console.log(myList);

for (var i = 0; frutas.length > i; i++) {
    myList.push("<li>" + frutas[i] + "</li>");
}

frutas.forEach(function(item, index, array){console.log(item, index, array)});

listaFrutas.insertAdjacentHTML('beforeend', myList.join(''));
