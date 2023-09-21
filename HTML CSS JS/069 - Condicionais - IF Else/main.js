//Expressao Regular que checa se é um email valido
//Regex
const emailRegex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
const fieldNome = document.getElementById('nome');
const fieldEmail = document.getElementById('email');
const wrapperNome = document.getElementById('form-field-nome');
const wrapperEmail = document.getElementById('form-field-email');

function validaForm() {
    let nomeStr = fieldNome.value;
    let emailStr = fieldEmail.value;

    if (nomeStr.length > 0 && nomeStr.length >= 3) {
        wrapperNome.querySelector('span').classList.add('success');
        wrapperNome.querySelector('span').classList.remove('error');
        wrapperNome.querySelector('span').innerText = "Validado Com Sucesso";

    } else {
        wrapperNome.querySelector('span').classList.add('error');
        wrapperNome.querySelector('span').classList.remove('success')
        wrapperNome.querySelector('span').innerText = "Informação Inválida";
    }

    if (emailRegex.test(emailStr)) {
        wrapperEmail.querySelector('span').classList.add('success');
        wrapperEmail.querySelector('span').classList.remove('error');
        wrapperEmail.querySelector('span').innerText = "Email Validado Com Sucesso";
    } else {
        wrapperEmail.querySelector('span').classList.add('error');
        wrapperEmail.querySelector('span').classList.remove('success');
        wrapperEmail.querySelector('span').innerText = "Email Invalido";
    }
}
